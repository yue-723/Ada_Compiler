%{

#include <iostream>
#include "symbolTab.h"
#include "lex.yy.cpp"
#include "CodeGenerator.hpp"

#define Trace(t) if (Opt_P) cout << "TRACE => " << t << endl;

int Opt_P = 1;
void yyerror(string s);

SymbolTables symbol_tables;
CodeGenerator Code_Generator;

// Insert ID in current table (tables[top]), return 1 if succedd.
bool insertTableEntry(SymInfo*);
// check now is in main
bool is_Main_Block = false;
bool isReturn = false;
// Variable stack index
int stackVarID = 0;

%}

/* yylval */
%union {
    int 	ival;
    float 	fval;
    bool    bval;

    // pointer use *$
    string *sval;

    // Non-terminal type
    _Data_type dataType;
    Data *dataValue;

    SymInfo *func_arg;
    vector<SymInfo*>* func_args;
    vector<Data*>* func_call;
}

/* tokens */
%token LE GE EQ NEQ AND OR NOT ASSIGN
%token BEGINN BOOLEAN BREAK CHARACTER CASE CONTINUE CONSTANT DECLARE DO ELSE END EXIT FLOAT FOR IF IN INTEGER LOOP PRINT PRINTLN PROCEDURE PROGRAM RETURN STRING WHILE READ THEN
%token <ival> CONST_INT
%token <fval> CONST_FLOAT
%token <bval> CONST_BOOL
%token <sval> CONST_STR
%token <sval> ID

/* type for non-terminal */
%type <dataType> type return_type function_invocation
%type <dataValue> expression literal_const
%type <func_arg> arg
%type <func_args> formal_args
%type <func_call> comma_separated_expression

/* precedence */
%left OR
%left AND
%left NOT
%left '<' LE EQ GE '>' NEQ
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS


%start program

%%
program:
                PROGRAM ID
                {
                    Trace("REDUCE < PROGRAM >");
                    // Insert ID in current table.
                    insertTableEntry(new SymInfo(*$2, DEC_PROGRAM));
                    Code_Generator.program_start();
                }
                declartion procedure_decs BEGINN
                {
                    Code_Generator.main_start();
                    is_Main_Block = true;
                }
                statements END ';' END ID
                {
                    if (*$2 != *$12)
                        yyerror("Program ID not match!");
                    //Dump all the list of tables.
                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    Code_Generator.main_end();
                    Code_Generator.program_end();
                }
                ;
declartion:     
                DECLARE var_const_decs { Trace("REDUCE < DECLARTION >") }; 
                | /* optional */
                ;
var_const_decs: 
                var_const_dec var_const_decs
                | /* zero or more */
                ;

var_const_dec:  
                const_dec | var_dec
                ;

const_dec:
                ID ':' CONSTANT ':' type ASSIGN expression ';'
                {
                    if ($5 != $7->get_data_type()) 
                    {
                        yyerror("Declartion Type Inconsistent");
                    }
                    insertTableEntry(new SymInfo(*$1, DEC_CONST, $5, *$7));
                }
                | ID ':' CONSTANT ASSIGN expression ';'
                {
                    insertTableEntry(new SymInfo(*$1, DEC_CONST, *$5));
                }
                ;

var_dec:
                ID ':' type ASSIGN expression ';'
                {
                    if ($3 != $5->get_data_type())
                    {
                        yyerror("Declartion Type Inconsistent");
                    }
                    insertTableEntry(new SymInfo(*$1, DEC_VAR, $3, *$5));
                    if (symbol_tables.isGlobalTable())
                    {
                        if ($5->get_data_type() == TYPE_BOOL){
                            Code_Generator.dec_global_var_with_value(*$1, $5->get_bool()? 1:0);
                        }
                        else{
                        Code_Generator.dec_global_var_with_value(*$1, $5->get_int());
                        }
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*$1);
                        id->stackID = stackVarID;
                        Code_Generator.assign_local_var(stackVarID++);
                    }
                }
                | ID ':' type ';'
                {
                    insertTableEntry(new SymInfo(*$1, DEC_VAR, $3));
                    if (symbol_tables.isGlobalTable())
                    {
                         Code_Generator.dec_global_var(*$1);
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*$1);
                        id->stackID = stackVarID;
                        stackVarID++;
                    }
                }
                | ID ASSIGN expression ';'
                {
                    insertTableEntry(new SymInfo(*$1, DEC_VAR, *$3));
                    if (symbol_tables.isGlobalTable())
                    {
                        if ($3->get_data_type() == TYPE_BOOL){
                            Code_Generator.dec_global_var_with_value(*$1, $3->get_bool()? 1:0);
                        }
                        else{
                        Code_Generator.dec_global_var_with_value(*$1, $3->get_int());
                        }
                    }
                    else
                    {
                        SymInfo *id = symbol_tables.look_up(*$1);
                        id->stackID = stackVarID;
                        Code_Generator.assign_local_var(stackVarID++);
                    }
                }
                | ID ':' type '[' CONST_INT ']' ';'   /* Array */
                {
                    if ($5 < 1)
                    {
                        yyerror("Array length must greater than 1");
                    }
                    insertTableEntry(new SymInfo(*$1, DEC_ARRAY, $3, $5));
                }
                ;

type:
                INTEGER
                {
                    $$ = TYPE_INT;
                }
                | FLOAT
                {
                    $$ = TYPE_FLOAT;
                }
                | STRING
                {
                    $$ = TYPE_STRING;
                }
                | BOOLEAN
                {
                    $$ = TYPE_BOOL;
                }
                ;

procedure_decs:    
                procedure_dec procedure_decs
                | /* zero or more*/
                ;

procedure_dec:     
                PROCEDURE ID 
                {
                    Trace("REDUCE < PROCEDURE(args) >");
                    // New a function type STEI.
                    SymInfo* func = new SymInfo(*$2, DEC_PROCEDURE);
                    stackVarID = 0;

                    // Add func into current table.
                    insertTableEntry(func);

                    /* Create a new child table. */
                    symbol_tables.add_table();
                }
                '(' formal_args ')' return_type
                {
                    SymInfo* func = symbol_tables.look_up(*$2);
                    // Add function arg type. use to check.
                    for(int i = 0 ; i < $5->size(); i++)
                    {
                        func->add_arg_type((*$5)[i]->get_data_type());
                    }
                    func->set_return_type($7);
                    // Add func args into new table.
                    for (int i = 0 ; i < $5->size(); i++)
                    {
                        insertTableEntry((*$5)[i]);
                    }
                    Code_Generator.dec_func_start(func);
                }
                declartion BEGINN statements END ';'  /* equal block prevent add_table() twice */ 
                { Trace("REDUCE < Procedure(args) end >");} END ID ';'
                {
                    SymInfo* func = symbol_tables.look_up(*$2);
                    Code_Generator.def_func_end(func , isReturn);

                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    isReturn = false;
                }
                /* Parentheses are not required when no arguments are declared */
                | PROCEDURE ID return_type
                {
                    Trace("REDUCE < PROCEDURE() >");
                    // New a function type STEI.
                    SymInfo* func = new SymInfo(*$2, DEC_PROCEDURE);
                    stackVarID = 0;
                    func->set_return_type($3);
                    Code_Generator.dec_func_start(func);
                    // Add func into current table.
                    insertTableEntry(func);

                    /* Create a new child table. */
                    symbol_tables.add_table();
                }
                declartion BEGINN statements END ';' /* equal block prevent add_table() twice */ 
                { Trace("REDUCE < Procedure() end >");} END ID ';'
                {
                    SymInfo* func = symbol_tables.look_up(*$2);
                    Code_Generator.def_func_end(func , isReturn);

                    symbol_tables.dump();
                    // End block then pop current table.
                    symbol_tables.pop_table();
                    isReturn = false;
                }
                ;

return_type:    
                RETURN type
                {
                    $$ = $2;
                }
                | /* No return type */
                {
                    $$ = TYPE_NONE;
                }
                ;

formal_args:    
                arg ';' formal_args
                {
                    // Store arg into formal_args
                    $3->push_back($1);
                    $$ = $3;
                }
                | arg
                {
                    // Create a vector which store only one arg.
                    vector<SymInfo*>* temp = new vector<SymInfo*>();
                    temp->push_back($1);
                    $$ = temp;
                }
                | /* zero or more */
                {
                    $$ = new vector<SymInfo*>();
                }
                ;

arg:            
                ID ':' type
                {
                    // Procedure args are all immutable
                    $$ = new SymInfo(*$1, DEC_VAR, $3);
                    if (insertTableEntry($$))
                    {
                        $$->stackID = stackVarID++;
                    }
                }
                ;

statements:     
                statement statements
                | /* zero or more */
                ;

statement:
                simple_statement
                | block
                | condition
                | loop
                | function_invocation ';' 
                ;


simple_statement:
                ID ASSIGN expression ';'
                {
                    Trace("REDUCE < ID := EXPR >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else
                    {
                        // Declare must be DEC_VAR
                        if (id->get_declare_type() != DEC_VAR)
                        {
                            yyerror(string("ID " + *$1 + " CONSTANT can't be assign"));
                        }   
                        // Only assign with same data type
                        else if (id->get_data_type() != $3->get_data_type())
                        {
                            yyerror(string("ID " + *$1 + " Assign with different Data type"));
                        }
                        else 
                        {
                            // Set variable data
                            id->set_data(*$3);
                            // global
                            if (id->isGlobal())
                            {
                                Code_Generator.assign_global_var(id->get_id_name());
                            }
                            // local
                            else
                            {
                                Code_Generator.assign_local_var(id->stackID);
                            }
                        }
                    }
                }
                | ID '[' expression ']' ASSIGN expression ';'
                {
                    Trace("REDUCE < ID[EXPR] := EXPR >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else 
                    {
                        // Index must be int
                        if ($3->get_data_type() != TYPE_INT)
                        {
                            yyerror(string("ID " + *$1 + " array index must be int"));
                        }
                        // Declare type must be DEC_ARRAY;
                        else if (id->get_declare_type() != DEC_ARRAY)
                        {
                            yyerror(string("ID " + *$1 + " not array type"));
                        }
                        // Only assign with same data type
                        else if (id->get_array_data_type() != $6->get_data_type())
                        {
                            yyerror(string("ID " + *$1 + " Assign with different Data type"));
                        }
                        // Check if index out of range
                        else if (id->get_array_length() <= $3->get_int())
                        {
                            yyerror(string("ID " + *$1 + " array index out of range"));
                        }
                        else 
                        {
                            // Set array[index] data.
                            id->set_array_data($3->get_int(), *$6);
                        }
                    }
                }              
                | PRINT           
                { 
                    Trace("REDUCE < PRINT >")
                    Code_Generator.print_start();

                }
                expression ';'
                { 
                    if($3->get_data_type() == TYPE_STRING){
                        Code_Generator.print_str_end();
                    }
                    else{
                        Code_Generator.print_int_end();
                    }
                }
                | PRINTLN
                { 
                    Trace("REDUCE < PRINTLN >")
                    Code_Generator.print_start();

                } expression ';'         
                { 
                    if($3->get_data_type() == TYPE_STRING){
                        Code_Generator.println_str_end();
                    }
                    else{
                        Code_Generator.println_int_end();
                    }
                }
                | READ ID ';'                    
                { 
                    Trace("REDUCE < READ ID >")  
                    SymInfo* id = symbol_tables.look_up(*$2);
                    if (id == NULL)
                        yyerror(string("ID " + *$2 +" is Not FOUND"));
                }
                | RETURN expression ';'          
                { 
                    Trace("REDUCE < RETURN EXPR > ")
                    isReturn = true;
                    Code_Generator.func_end_inAdvance();
                }
                | RETURN ';'
                { 
                    Trace("REDUCE < RETURN > ")
                    isReturn = true;
                    Code_Generator.func_end_inAdvance();
                }
                ;

expression:     
                '(' expression ')' 
                { 
                    $$ = $2;
                }
                | literal_const
                {
                    $$ = $1;
                    if (!symbol_tables.isGlobalTable() || is_Main_Block)
                    {
                        if($1->get_data_type() == TYPE_STRING){
                            Code_Generator.load_const_str(*($1->get_string()));
                        }
                        else if($1->get_data_type() == TYPE_BOOL){
                            Code_Generator.load_const_int($1->get_bool()? 1:0);
                        }
                        else{
                            Code_Generator.load_const_int($1->get_int());
                        }
                    }
                }
                | function_invocation
                {
                    // Only get function type
                    Data* d = new Data();
                    d->set_data_type($1);
                    $$ = d;
                }
                | ID
                {
                    Trace("REDUCE < ID >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else
                    {
                        // Return ID data.
                        $$ = id->get_data();
                        Data *idData = id->get_data();
                        if (id->get_declare_type() == DEC_CONST)
                        {
                            if (id->get_data_type() == TYPE_INT)
                            {
                                Code_Generator.load_const_int(idData->get_int());
                            }
                            else if (id->get_data_type() == TYPE_STRING)
                            {
                                Code_Generator.load_const_str(*(idData->get_string()));
                            }
                        
                        }
                        else if (id->get_declare_type() == DEC_VAR)
                        {
                            // global
                            if (id->isGlobal())
                            {
                                Code_Generator.load_global_var(id->get_id_name());
                            }
                            // local
                            else
                            {
                                Code_Generator.load_local_var(id->stackID);
                            }
                        }
                    }
                }
                | ID '[' expression ']'
                {
                    Trace("REDUCE < ID[EXPR] >");
                    // Check if ID exist in symbol table.
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else
                    {
                        // Check if index out of range
                        if (id->get_array_length() <= $3->get_int())
                        {
                            yyerror(string("ID " + *$1 + " array index out of range"));
                        }
                        // Declare type must be DEC_ARRAY;
                        if (id->get_declare_type() != DEC_ARRAY)
                        {
                            yyerror(string("ID " + *$1 + " not array type"));
                        }
                        // Return ID[index] data.
                        $$ = id->get_array_data($3->get_int());
                    }
                }
                /* Arithmetic expression */
                | '-' expression %prec UMINUS
                {
                    Trace("REDUCE < - EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($2->get_data_type() == TYPE_INT)
                    {
                        Data *d = new Data(TYPE_INT, $2->get_int() * -1);
                        $$ = d;
                    }
                    else if ($2->get_data_type() == TYPE_FLOAT)
                    {
                        Data *d = new Data(TYPE_FLOAT, $2->get_float() * -1);
                        $$ = d;
                    }
                    else 
                    {
                        yyerror("TYPE ERROR in -exp");
                    }
                    Code_Generator.operation('n');
                }
                | expression '*' expression
                {
                    Trace("REDUCE < EXPR * EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, $1->get_int() * $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, $1->get_float() * $3->get_float());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp * exp");
                        }
                    }
                    Code_Generator.operation('*');
                }
                | expression '/' expression
                {
                    Trace("REDUCE < EXPR / EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, $1->get_int() / $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, $1->get_float() / $3->get_float());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp / exp");
                        }
                    }
                    Code_Generator.operation('/');
                }
                | expression '+' expression
                {
                    Trace("REDUCE < EXPR + EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, $1->get_int() + $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, $1->get_float() + $3->get_float());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp + exp");
                        }
                    }
                    Code_Generator.operation('+');
                }
                | expression '-' expression
                {
                    Trace("REDUCE < EXPR - EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, $1->get_int() - $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            Data *d = new Data(TYPE_FLOAT, $1->get_float() - $3->get_float());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp - exp");
                        }
                    }
                    Code_Generator.operation('-');
                }
                | expression '%' expression
                {
                    Trace("REDUCE < EXPR % EXPR >");
                    // Only calculate the type INT and FLOAT
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            Data *d = new Data(TYPE_INT, $1->get_int() % $3->get_int());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp % exp");
                        }
                    }
                    Code_Generator.operation('%');
                }
                | expression '<' expression
                {
                    Trace("REDUCE < EXPR < EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        // Used to return
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() < $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() < $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            
                            d->set_value($1->get_bool() < $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp < exp");
                        }
                    }
                    Code_Generator.relation("<");
                }
                | expression LE expression
                {
                    Trace("REDUCE < EXPR <= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() <= $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() <= $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() <= $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp <= exp");
                        }
                    }
                    Code_Generator.relation("<=");
                }
                | expression '>' expression
                {
                    Trace("REDUCE < EXPR > EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() > $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() > $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() > $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp > exp");
                        }
                    }
                    Code_Generator.relation(">");
                }
                | expression GE expression
                {
                    Trace("REDUCE < EXPR >= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() >= $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() >= $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() >= $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp >= exp");
                        }
                    }
                    Code_Generator.relation(">=");
                }
                | expression EQ expression
                {
                    Trace("REDUCE < EXPR = EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() == $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() == $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() == $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp = exp");
                        }
                    }
                    Code_Generator.relation("=");
                }
                | expression NEQ expression
                {
                    Trace("REDUCE < EXPR /= EXPR >");
                    // Only calculate the type INT, FLOAT and BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_INT)
                        {
                            d->set_value($1->get_int() != $3->get_int());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_FLOAT)
                        {
                            d->set_value($1->get_float() != $3->get_float());
                            $$ = d;
                        }
                        else if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() != $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp /= exp");
                        }
                    }
                    Code_Generator.relation("/=");
                }
                | NOT expression
                {
                    Trace("REDUCE < LOGICAL_NOT EXPR >");
                    // Only calculate the type BOOL
                    if ($2->get_data_type() == TYPE_BOOL)
                    {
                        Data *d = new Data(TYPE_BOOL, false);
                        d->set_value(!$2->get_bool());
                        $$ = d;
                    }
                    else
                    {
                        yyerror("TYPE ERROR in LOGICAL_NOT exp");
                    }
                    Code_Generator.operation('!');
                }
                | expression AND expression
                {
                    Trace("REDUCE < EXPR LOGICAL_AND EXPR >");
                    // Only calculate the type BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() && $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp LOGICAL_AND exp");
                        }
                    }
                    Code_Generator.operation('&');
                }
                | expression OR expression
                {
                    Trace("REDUCE < EXPR LOGICAL_OR EXPR >");
                    // Only calculate the type BOOL
                    if ($1->get_data_type() != $3->get_data_type())
                    {
                        yyerror("Types of the left/right-hand-side must be matched.");
                    }
                    else {
                        Data *d = new Data(TYPE_BOOL, false);
                        if ($1->get_data_type() == TYPE_BOOL)
                        {
                            d->set_value($1->get_bool() || $3->get_bool());
                            $$ = d;
                        }
                        else
                        {
                            yyerror("TYPE ERROR in exp LOGICAL_OR exp");
                        }
                    }
                    Code_Generator.operation('|');
                }
                ;

literal_const:
                CONST_INT
                {
                    Trace("REDUCE < Literal_Const INT >");
                    Data *d = new Data(TYPE_INT, $1);
                    $$ = d;
                }
                | CONST_FLOAT
                {
                    Trace("REDUCE < Literal_Const FLOAT >");
                    Data *d = new Data(TYPE_FLOAT, $1);
                    $$ = d;
                }
                | CONST_STR
                {
                    Trace("REDUCE < Literal_Const STR >");
                    Data *d = new Data(TYPE_STRING, $1);
                    $$ = d;
                }
                | CONST_BOOL
                {
                    Trace("REDUCE < Literal_Const BOOL >");
                    Data *d = new Data(TYPE_BOOL, $1);
                    $$ = d;
                }
                ;

function_invocation:
                ID 
                {
                    Trace("REDUCE < Func ID >");
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else
                    {
                        if (id->get_declare_type() != DEC_PROCEDURE)
                        {
                            yyerror(string("ID " + *$1 +" function invocation must be declare as PROCEDURE"));
                        }
                        $$ = id->get_return_type();
                        Code_Generator.func_invoke(id);
                    }
                }
                | ID '(' comma_separated_expression ')'
                {
                    Trace("REDUCE < Func ID(EXPR) >");
                    SymInfo* id = symbol_tables.look_up(*$1);
                    if (id == NULL)
                    {
                        yyerror(string("ID " + *$1 +" is Not FOUND"));
                    }
                    else
                    {
                        if (id->get_declare_type() != DEC_PROCEDURE)
                        {
                            yyerror(string("ID " + *$1 +" function invocation must be declare as PROCEDURE"));
                        }
                        // Check if comma_separated_exp type is equal to function args
                        if (id->check_arg_match($3) == false)
                        {
                            yyerror("Function arg type mismatch");
                        }
                        $$ = id->get_return_type();
                        Code_Generator.func_invoke(id);
                    }
                }
                ;
comma_separated_expression:
                expression
                {
                    $$ = new vector<Data*>();
                    $$->push_back($1);
                }
                | expression ',' comma_separated_expression
                {
                    $3->push_back($1);
                    $$ = $3;
                }
                | /* optional */
                {
                    $$ = new vector<Data*>();
                }
                ;

block:
                declartion BEGINN
                {
                    Trace("REDUCE < BLOCK >");
                    // Create a new child table
                    symbol_tables.add_table();
                }
                statements
                { Trace("REDUCE < BLOCK end >"); } END ';'
                {
                    symbol_tables.dump();
                    // Pop the current table.
                    symbol_tables.pop_table();
                }
                ;

block_or_simple_statement:
                block | simple_statement
                ;

condition:
                IF expression THEN
                {
                    Trace("REDUCE < IF EXPR THEN >");
                    Code_Generator.if_start();
                    if ($2->get_data_type() != TYPE_BOOL)
                    {
                        yyerror("IF condition must be boolean");
                    }
                }
                block_or_simple_statement else END IF ';'
                {
                    Code_Generator.if_end();
                }
                ;

else:
                ELSE
                {
                    Code_Generator.else_start();
                } 
                block_or_simple_statement
                | /* without else */
                ;

loop:
                WHILE
                {
                    Code_Generator.while_start();
                } 
                expression 
                {
                    Trace("REDUCE < WHILE (EXPR) >");
                    if ($3->get_data_type() != TYPE_BOOL)
                    {
                        yyerror("WHILE expression must be boolean");
                    }
                    Code_Generator.if_start();
                }
                LOOP block_or_simple_statement END LOOP ';'
                { 
                    Trace("REDUCE < Loop end >");
                    Code_Generator.while_end(); 
                } 
                | FOR '(' ID IN CONST_INT '.' '.' CONST_INT ')' LOOP
                {
                    Trace("REDUCE < FOR >");
                    Code_Generator.load_const_int($5);
                    SymInfo *id = symbol_tables.look_up(*$3);

                    string relation;
                    if ($5 <= $8)
                        relation = "<=";
                    else
                        relation = ">=";
                    if (symbol_tables.isGlobalTable())
                        Code_Generator.for_globalVar_start(id->get_id_name(), relation, $5, $8);                
                    else   
                        Code_Generator.for_localVar_start(id->stackID, relation, $5, $8);
                }
                block_or_simple_statement END LOOP ';'
                { 
                    Trace("REDUCE < Loop end >");
                    SymInfo *id = symbol_tables.look_up(*$3);
                    char op;
                    if ($5 <= $8)
                        op = '+';
                    else
                        op = '-';
                    if (id->isGlobal()) 
                        Code_Generator.for_globalVar_end(id->get_id_name(), op);                       
                    else
                        Code_Generator.for_localVar_end(id->stackID, op);
                } 
                ;

%%

bool insertTableEntry(SymInfo *id)
{
    if (symbol_tables.insert(id) == -1)
    {
        //yyerror("Insert table entry faild: " + id->get_id_name());
        return false;
    }
    return true;
}

void yyerror(string msg)
{
    cout << "yyerror: " << msg << endl;
}

int main(int argc, char* argv[])
{
    /* open the source program file */
    if (argc == 1) {
        yyin = stdin;
    }
    else if (argc == 2) {
        yyin = fopen(argv[1], "r");         /* open input file */
    }
    else {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    string source = string(argv[1]);
    int dot = source.find(".");
    string filename = source.substr(0, dot);
    Code_Generator = CodeGenerator(filename);

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
    else
        cout << "Parsing succeed!" << endl;
    return 0;
}