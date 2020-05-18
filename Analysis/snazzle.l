%{
  #include "snazzle.tab.h"  // to get the token types from Bison
%}
%option noyywrap
%%
[ \t]             ;
\n                return ENDL;
int               return INT;
[a-zA-Z][a-zA-Z0-9_]+ { yylval.sval = _strdup(yytext); return IDENTIFIER; }
\;                return ';';
[0-9]+\.[0-9]+    { yylval.fval = atof(yytext); return FLOAT; }
[a-zA-Z0-9]+      { yylval.sval = _strdup(yytext); return STRING;
  // We have to strdup yytext because Flex will change it for the next token.
  // Note that this memory must be freed somewhere, so that's why we call
  // free() above in the Bison section.  (Aside: we use free() instead of
  // delete because strdup is a C function that uses malloc, not a C++
  // function that uses new.)
 }
 .                ;
%%