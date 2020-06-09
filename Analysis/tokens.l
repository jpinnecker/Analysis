%{
  #include "grammar.tab.h"  // to get the token types from Bison
  short longcounter = 0;
%}
%option noyywrap
%x COMMENT_SECTION
%x COMMENT_LINE
%x STRING
%x INT_LOGIC
%x SIGNED_LOGIC
%x SHORT_LOGIC
%x CHAR_LOGIC
%x FLOAT_LOGIC
%x DOUBLE_LOGIC
%x LONG_LOGIC
%%

	/*||---------------------------------||
	  ||    Erkennung von Kommentaren    ||
	  ||---------------------------------||*/

"/*"					BEGIN COMMENT_SECTION;
<COMMENT_SECTION>{
"*/"					BEGIN INITIAL;
\n						return ENDL;
.						;
}

"//"					BEGIN COMMENT_LINE;
<COMMENT_LINE>{
.						;
\n						BEGIN INITIAL; return ENDL;
}

\"						BEGIN STRING; return CSTRING;
<STRING>{
\"						BEGIN INITIAL;
.						;
}


	/*||---------------------------------||
	  ||      Datentypenerkennung        ||
	  ||---------------------------------||*/


	/*Hier werden die Regeln zusammengefasst, die für alle Typen gleich gelten*/

<INT_LOGIC,SHORT_LOGIC,CHAR_LOGIC,LONG_LOGIC,DOUBLE_LOGIC,SIGNED_LOGIC,FLOAT_LOGIC>{
[ \t]					;
("const"|"volatile"|"restrict") ;
\n						return ENDL;
}

	/*|| Der Kellerautomat für den Startzustand signed/unsigned ||
	  ||--------------------------------------------------------||*/

unsigned				BEGIN SIGNED_LOGIC;
signed					BEGIN SIGNED_LOGIC;
<SIGNED_LOGIC>{
short					BEGIN SHORT_LOGIC;
char					BEGIN CHAR_LOGIC;
long					longcounter++;
int						;
\*+						longcounter=0; BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	short longs = longcounter;
	longcounter = 0;
	BEGIN INITIAL;
	switch(longs){
		case 0:
			return INTID;
			break;
		case 1:
			return LONGID;
			break;
		case 2:
			return LONGLONGID;
			break;
		default:
			printf("Tokens.l::LongCounter Error!\n");
		}					
	}
}

	/*|| Der Kellerautomat für den Startzustand int ||
	  ||--------------------------------------------||*/

int						BEGIN INT_LOGIC;
<INT_LOGIC>{
short					BEGIN SHORT_LOGIC;
long					longcounter++;
signed					;
unsigned				;
\*+						longcounter=0; BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	short longs = longcounter;
	longcounter = 0;
	BEGIN INITIAL;
	switch(longs){
		case 0:
			return INTID;
			break;
		case 1:
			return LONGID;
			break;
		case 2:
			return LONGLONGID;
			break;
		default:
			printf("Tokens.l::LongCounter Error!\n");
		}					
	}
}

	/*|| Der Kellerautomat für den Startzustand short ||
	  ||----------------------------------------------||*/

short					BEGIN SHORT_LOGIC;
<SHORT_LOGIC>{
int						;
signed					;
unsigned				;
\*+						BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	BEGIN INITIAL;
	return SHORTID;
	}
}

	/*|| Der Kellerautomat für den Startzustand char ||
	  ||---------------------------------------------||*/

char					BEGIN CHAR_LOGIC;
<CHAR_LOGIC>{
signed					;
unsigned				;
\*+						BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	BEGIN INITIAL;
	return CHARID;
	}
}

	/*|| Der Kellerautomat für den Startzustand float ||
	  ||----------------------------------------------||*/

float                   BEGIN FLOAT_LOGIC;
<FLOAT_LOGIC>{
\*+						BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	BEGIN INITIAL;
	return FLOATID;
	}
}

	/*|| Der Kellerautomat für den Startzustand double ||
	  ||-----------------------------------------------||*/

double                  BEGIN DOUBLE_LOGIC;
<DOUBLE_LOGIC>{
long					longcounter=1;
\*+						longcounter=0; BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	short longs = longcounter;
	longcounter = 0;
	BEGIN INITIAL;
	switch(longs){
		case 0:
			return DOUBLEID;
			break;
		case 1:
			return LONGDOUBLEID;
			break;
		default:
			printf("Tokens.l::LongCounter Error!\n");
		}					
	}
}

	/*|| Der Kellerautomat für den Startzustand long ||
	  ||---------------------------------------------||*/

long					BEGIN LONG_LOGIC;
<LONG_LOGIC>{
long					longcounter=2;
double					longcounter=1;
signed					;
unsigned				;
int						;
\*+						longcounter=0; BEGIN INITIAL; return POINTER;
[a-zA-Z_][a-zA-Z0-9_]*  {
	yylval.string = _strdup(yytext);
	short longs = longcounter;
	longcounter = 0;
	BEGIN INITIAL;
	switch(longs){
		case 0:
			return LONGID;
			break;
		case 1:
			return LONGDOUBLEID;
			break;
		case 2:
			return LONGLONGID;
			break;
		default:
			printf("Tokens.l::LongCounter Error!\n");
		}					
	}
}


	/*||---------------------------------||
	  ||        Einzelne Tokens          ||
	  ||---------------------------------||*/


struct			        return STRUCT;

("const"|"volatile"|"restrict") ;
[a-zA-Z_][a-zA-Z0-9_]*  yylval.string = _strdup(yytext); return IDENTIFIER;
\*						return '*';
\&						return '&';
\;                      return ';';
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
\n                      return ENDL;
\+                      return '+';
\-						return '-';
\/						return '/';
while					return WHILE;
if						return IF;
void					return VOID;
[ \t.,]                 ; //Ignorierbare Zeichen
%%