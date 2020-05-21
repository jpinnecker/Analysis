%{
  #include "grammar.tab.h"  // to get the token types from Bison
%}
%option noyywrap
%%
[ \t.]                  ; 
\n                      return ENDL;
\+                      return '+';
struct			        return STRUCT;
short                   return SHORT;
long                    return LONG;
double                  return DOUBLE;
int                     return INT;
char                    return CHAR;
float                   return FLOAT;
[a-zA-Z][a-zA-Z0-9_]*   return IDENTIFIER;
\;                      return ';';
\=                      return '=';
[0-9]+                  return INUMBER;
[0-9]+\.[0-9]+          return FNUMBER;
\'.\'                   return CHARACTER;
[a-zA-Z0-9]+            { yylval.sval = _strdup(yytext); return STRING; }
%%