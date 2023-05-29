%{

using namespace std;

#include "y.tab.hpp"

int Opt_T = 0;
int Opt_S = 0;

#define MAX_LINE_LENG 256
#define LIST strcat(buf, yytext)
#define token(t) { LIST; if(Opt_T) printf("<%s>\n", #t);return t ;}
#define tokenChar(t) { LIST; if(Opt_T) printf("<'%c'>\n", t); }
#define tokenInteger(t,i) { LIST; if(Opt_T) printf("<%s: %d>\n", #t, i); }
#define tokenString(t,s) { LIST; if(Opt_T) printf("<%s: %s>\n", #t, s); }

int linenum = 1;
char buf[MAX_LINE_LENG];

%}

DELIMITER               [,:.;()\[\]]
ARITHMETIC              [\-\%\+\*\/]
RELATIONAL              [<>]
IDENTIFIER              [A-Za-z][A-Za-z0-9]*
INTEGER                 [0-9]+
FLOAT                    {INTEGER}\.{INTEGER}?([Ee](-+)?{INTEGER})?
STRING                  \"(\"\"|[^\"\n])*\"
SINGLE_COMMENT          "--"[^\n]*
BEGIN_COMMENT           "{"
END_COMMENT             "}"

%x COMMENT

%%
 /* two-character token */
":="                  {token(ASSIGN); }
"="                   {token(EQ); }
"<="                  {token(LE); }
">="                  {token(GE); }
"/="                  {token(NEQ); }

 /* keyword */
and                   { token(AND); }
or                    { token(OR); }
not                   { token(NOT); }
begin                 { token(BEGINN); }
boolean               { token(BOOLEAN); }
break                 { token(BREAK); }
character             { token(CHARACTER); }
case                  { token(CASE); }
continue              { token(CONTINUE); }
constant              { token(CONSTANT); }
declare               { token(DECLARE); }
do                    { token(DO); }
else                  { token(ELSE); }
end                   { token(END); }
exit                  { token(EXIT); }
float                 { token(FLOAT); }
for                   { token(FOR); }
if                    { token(IF); }
in                    { token(IN); }
integer               { token(INTEGER); }
loop                  { token(LOOP); }
print                 { token(PRINT); }
println               { token(PRINTLN); }
procedure             { token(PROCEDURE); }
program               { token(PROGRAM); }
return                { token(RETURN); }
string                { token(STRING); }
while                 { token(WHILE); }
read                  { token(READ); }
then                  { token(THEN); }

 /* single character token */
{DELIMITER}  |
{ARITHMETIC} |
{RELATIONAL}            { tokenChar(yytext[0]); return yytext[0]; }

true			              {
                          tokenString(BOOLEAN,yytext);
                          yylval.bval = true;
                          return CONST_BOOL;
                        }

false			              {
                          tokenString(BOOLEAN,yytext);
                          yylval.bval = false;
                          return CONST_BOOL;
                        }
{IDENTIFIER}            {
                          tokenString(IDENTIFIER, yytext);
                          yylval.sval = new string(yytext);
                          return ID;
                        }

{INTEGER}               {
                          tokenInteger(INTEGER, atoi(yytext));
                          yylval.ival = atoi(yytext);
                          return CONST_INT;
                        }

{FLOAT}                  {
                          tokenString(FLOAT, yytext);
                          yylval.fval = atof(yytext);
                          return CONST_FLOAT;
                        }
{STRING}                {
                          char s[MAX_LINE_LENG] = {0};
                          int idx = 0;
                          for (int i = 1; i < yyleng - 1; ++i) {
                            if (yytext[i] == '"') ++i;
                            s[idx++] = yytext[i];
                          }
                          tokenString(STRING, s);
                          yylval.sval = new string(s);
                          return CONST_STR;
                        }
 /* comment */
{SINGLE_COMMENT}        { LIST; }

{BEGIN_COMMENT}         {
                          BEGIN COMMENT;
                          LIST;
                        }
<COMMENT>{END_COMMENT}  {
                          BEGIN INITIAL;
                          LIST;
                        }

<COMMENT>\n             {
                          LIST;
                          if(Opt_S) printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }

<COMMENT>.              {
                          LIST;
                        }

\n                      {
                          LIST;
                          if(Opt_S) printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }

[ \t]*                  { LIST; }

.                       {
                          LIST;
                          printf("%d:%s\n", linenum, buf);
                          printf("bad character:'%s'\n",yytext);
                          exit(-1);
                        }

%%