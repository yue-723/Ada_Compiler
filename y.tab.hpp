/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LE = 258,
    GE = 259,
    EQ = 260,
    NEQ = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    ASSIGN = 265,
    BEGINN = 266,
    BOOLEAN = 267,
    BREAK = 268,
    CHARACTER = 269,
    CASE = 270,
    CONTINUE = 271,
    CONSTANT = 272,
    DECLARE = 273,
    DO = 274,
    ELSE = 275,
    END = 276,
    EXIT = 277,
    FLOAT = 278,
    FOR = 279,
    IF = 280,
    IN = 281,
    INTEGER = 282,
    LOOP = 283,
    PRINT = 284,
    PRINTLN = 285,
    PROCEDURE = 286,
    PROGRAM = 287,
    RETURN = 288,
    STRING = 289,
    WHILE = 290,
    READ = 291,
    THEN = 292,
    CONST_INT = 293,
    CONST_FLOAT = 294,
    CONST_BOOL = 295,
    CONST_STR = 296,
    ID = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define LE 258
#define GE 259
#define EQ 260
#define NEQ 261
#define AND 262
#define OR 263
#define NOT 264
#define ASSIGN 265
#define BEGINN 266
#define BOOLEAN 267
#define BREAK 268
#define CHARACTER 269
#define CASE 270
#define CONTINUE 271
#define CONSTANT 272
#define DECLARE 273
#define DO 274
#define ELSE 275
#define END 276
#define EXIT 277
#define FLOAT 278
#define FOR 279
#define IF 280
#define IN 281
#define INTEGER 282
#define LOOP 283
#define PRINT 284
#define PRINTLN 285
#define PROCEDURE 286
#define PROGRAM 287
#define RETURN 288
#define STRING 289
#define WHILE 290
#define READ 291
#define THEN 292
#define CONST_INT 293
#define CONST_FLOAT 294
#define CONST_BOOL 295
#define CONST_STR 296
#define ID 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "yacc.y" /* yacc.c:1909  */

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

#line 157 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
