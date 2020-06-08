%{
  #include "grammar.tab.h"  // to get the token types from Bison
%}
%option noyywrap
%%
[ \t.]                  ; 
\n                      return ENDL;
\+                      return '+';
\-						return '-';
\/						return '/';
while					return WHILE;
if						return IF;
void					return VOID;
signed					return SIGNED;
unsigned			    return UNSIGNED;
struct			        return STRUCT;
short                   return SHORT;
long                    return LONG;
double                  return DOUBLE;
int                     return INT;
char                    return CHAR;
float                   return FLOAT;
[a-zA-Z][a-zA-Z0-9_]*   return IDENTIFIER;
\*						return '*';
\&						return '&';
\;                      return ';';
\,						return ',';
\!						return '!';
\<						return '<';
\>						return '>';
\=                      return '=';
\(						return '(';
\)						return ')';
\{						return '{';
\}						return '}';
[0-9]+                  return INUMBER;
[0-9]+\.[0-9]+f?        return FNUMBER;
\'.\'                   return CHARACTER;
%%