%{
  #include <cstdio>
  #include <string>
  #include <iostream>
  #include "TokenProcessor.h"
  using namespace std;

  //Enable debugging output
  #define YYDEBUG 1

  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  
  //Instanziierung unseres Token-Prozessors
  TokenProcessor tokenProcessor = TokenProcessor();

  void yyerror(const char *s);
%}

  /*|| Token, deren Wert weitergereicht wird ||
    ||---------------------------------------||*/

%union {
    char* string; //remember to free!!!
    int integer;
}
//Datatypes
%token <string> IDENTIFIER INTID LONGID LONGLONGID LONGDOUBLEID DOUBLEID SHORTID CHARID FLOATID
%token <integer> INUMBER
%token POINTER VOID

// Constant String-Tokens
%token ENDL CSTRING RETURN

// Right-Side Values
%token FNUMBER CHARACTER

%%
// This is the actual grammar that bison will parse.
cfile:
    bodylines {
        cout << "Finished Parsing..." << endl;};
bodylines:
    bodylines bodyline
    | bodyline;
bodyline:

  /*||---------------------------||
    ||  Einfache Deklinationen   ||
    ||---------------------------||*/

    integer {
        tokenProcessor.processToken(sizeof(int), "Integer found... ");
    }
    | double {
        tokenProcessor.processToken(sizeof(double), "Double found... ");
    }
    | long_double {
        tokenProcessor.processToken(sizeof(long double), "Long Double found... ");
    }
    | floating {
        tokenProcessor.processToken(sizeof(float), "Float found... ");
    }
    | character {
        tokenProcessor.processToken(sizeof(char), "Character found... ");
    }
    | long {
        tokenProcessor.processToken(sizeof(long), "Long found... ");
    }
    | long_long {
        tokenProcessor.processToken(sizeof(long long), "Long Long found... ");
    }
    | short {
        tokenProcessor.processToken(sizeof(short), "Short found... ");
    }
    | pointer {
        tokenProcessor.processToken(sizeof(void*), "Pointer found... ");
    }


/*  ||---------------------------||
    ||    Array Deklinationen    ||
    ||---------------------------||*/

    | INTID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(int)*$3+sizeof(void*), "Integer array of length " + to_string($3) + " found... ");
        free($1);
    }
    | DOUBLEID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(double)*$3+sizeof(void*), "Double array of length " + to_string($3) + " found... ");
        free($1);
    }
    | LONGDOUBLEID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(long double)*$3+sizeof(void*), "Long Double array of length " + to_string($3) + " found... ");
        free($1);
    }
    | FLOATID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(float)*$3+sizeof(void*), "Floating array of length " + to_string($3) + " found... ");
        free($1);
    }
    | CHARID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(char)*$3+sizeof(void*), "Character array of length " + to_string($3) + " found... ");
        free($1);
    }
    | LONGID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(long)*$3+sizeof(void*), "Long array of length " + to_string($3) + " found... ");
        free($1);
    }
    | LONGLONGID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(long long)*$3+sizeof(void*), "Long Long array of length " + to_string($3) + " found... ");
        free($1);
    }
    | SHORTID '[' INUMBER ']' {
        tokenProcessor.processToken(sizeof(short)*$3+sizeof(void*), "Short array of length " + to_string($3) + " found... ");
        free($1);
    }


/*  ||---------------------------||
    ||   Funktionsdefinitionen   ||
    ||---------------------------||*/

    | INTID '(' {
        tokenProcessor.registerFunction(sizeof(int), $1);
        free($1);
    }
    | DOUBLEID '(' {
        tokenProcessor.registerFunction(sizeof(double), $1);
        free($1);
    }
    | LONGDOUBLEID '(' {
        tokenProcessor.registerFunction(sizeof(long double), $1);
        free($1);
    }
    | FLOATID '(' {
        tokenProcessor.registerFunction(sizeof(float), $1);
        free($1);
    }
    | CHARID '(' {
        tokenProcessor.registerFunction(sizeof(char), $1);
        free($1);
    }
    | LONGID '(' {
        tokenProcessor.registerFunction(sizeof(long), $1);
        free($1);
    }
    | LONGLONGID '(' {
        tokenProcessor.registerFunction(sizeof(long long), $1);
        free($1);
    }
    | SHORTID '(' {
        tokenProcessor.registerFunction(sizeof(short), $1);
        free($1);
    }
    | VOID IDENTIFIER '(' {
        tokenProcessor.registerFunction(0, $2);
        free($2);
    }
    

/*  ||---------------------------||
    ||      Funktionsaufruf      ||
    ||---------------------------||*/

    | IDENTIFIER '(' params ')' {
        tokenProcessor.processFunction($1);
        free($1);
    }


    // Rumpfanfang
    | ')' '{' {
        ;
    }
    // Rumpfende
    | '}' {
        ;
    }
    // Ende Parameterliste
    | ')' {
        ;
    }

    | ENDL {
        tokenProcessor.incrementLine();
    }

    | ',' {
        ;
    }
    | ';' {
        ;
    }

//Errorhandling
    | error ';' {
        cout << "Omitting unknown rule on line " << tokenProcessor.getLine() << endl;
    }
    | error ENDL {
        cout << "Omitting unknown rule on line " << tokenProcessor.getLine() << endl;
        tokenProcessor.incrementLine();
    }
;

//Parameterliste
params:
    param ',' param
    | param;
param:
    %empty
    | IDENTIFIER {free($1);}
    | POINTER
;

//Pointerregeln
pointer:
    POINTER IDENTIFIER {free($2);}
    | POINTER '=' CSTRING
    | POINTER '=' IDENTIFIER {free($3);}
    | POINTER '=' '&' IDENTIFIER {free($4);}
;

//Definitionsregeln f�r Datentypen
integer:
    INTID {free($1);}
    | INTID '=' INUMBER {free($1);}
    | INTID '=' IDENTIFIER {free($1); free($3);}
;
floating:
    FLOATID {free($1);}
    | FLOATID '=' FNUMBER {free($1);}
    | FLOATID '=' IDENTIFIER {free($1); free($3);}
;
double:
    DOUBLEID {free($1);}
    | DOUBLEID '=' INUMBER {free($1);}
    | DOUBLEID '=' FNUMBER {free($1);}
    | DOUBLEID '=' IDENTIFIER {free($1); free($3);}
;
character:
    CHARID {free($1);}
    | CHARID '=' CHARACTER {free($1);}
    | CHARID '=' IDENTIFIER {free($1); free($3);}
;
short:
    SHORTID {free($1);}
    | SHORTID '=' INUMBER {free($1);}
    | SHORTID '=' IDENTIFIER {free($1); free($3);}
;
long:
    LONGID {free($1);}
    | LONGID '=' INUMBER {free($1);}
    | LONGID '=' IDENTIFIER {free($1); free($3);}
;
long_long:
    LONGLONGID {free($1);}
    | LONGLONGID '=' INUMBER {free($1);}
    | LONGLONGID '=' IDENTIFIER {free($1); free($3);}
;
long_double:
    LONGDOUBLEID {free($1);}
    | LONGDOUBLEID '=' FNUMBER {free($1);}
    | LONGDOUBLEID '=' IDENTIFIER {free($1); free($3);}
;
%%

int main(int, char**) {
  // Open a file handle to a particular file:
  // TODO: Change the file from hardcoded to one of users choosing
  FILE *myfile;
  errno_t err = fopen_s(&myfile, "../CExampleProgram/Source.c", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open the file!" << endl;
    return 1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // Parse through the input:
  yyparse();

  tokenProcessor.printResults();
}

void yyerror(const char *s) {
  cout << "Parse error on line: " << tokenProcessor.getLine() << " - Message: " << s << endl;
}