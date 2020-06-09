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
  
  TokenProcessor tokenProcessor = TokenProcessor();

  void yyerror(const char *s);
%}

%union {
    char* string; //remember to free!!!
}
%token <string> IDENTIFIER INTID LONGID LONGLONGID LONGDOUBLEID DOUBLEID SHORTID CHARID FLOATID


// Constant String-Tokens
%token ENDL CSTRING

// Datatypes
%token POINTER VOID
%token STRUCT

// Statement 
%token IF WHILE

// Right-Side Values
%token INUMBER FNUMBER CHARACTER

%%
// This is the actual grammar that bison will parse.
cfile:
    bodylines {
        cout << "Finished Parsing..." << endl;};
bodylines:
    bodylines bodyline
    | bodyline;
bodyline:
    integer ';' {
        tokenProcessor.processToken(sizeof(int), "Integer found... ");
    }
    | double ';' {
        tokenProcessor.processToken(sizeof(double), "Double found... ");
    }
    | long_double ';' {
        tokenProcessor.processToken(sizeof(long double), "Long Double found... ");
    }
    | floating ';' {
        tokenProcessor.processToken(sizeof(float), "Float found... ");
    }
    | character ';' {
        tokenProcessor.processToken(sizeof(char), "Character found... ");
    }
    | long ';' {
        tokenProcessor.processToken(sizeof(long), "Long found... ");
    }
    | long_long ';' {
        tokenProcessor.processToken(sizeof(long long), "Long Long found... ");
    }
    | short ';' {
        tokenProcessor.processToken(sizeof(short), "Short found... ");
    }
    | struct ';' {
        cout << "struct-datatyp found" << endl;
    }
    | IF {
        cout << "if statement found" << endl;
    }
    | WHILE {
        cout << "While statement found" << endl;
    }
    | pointer ';' {
        tokenProcessor.processToken(sizeof(void*), "Pointer found... ");
    }
//    | ARRAY {
//         cout << " array found" << endl;
//    }

//Funktionsdefinitionen
//TODO: TokenProcessor Anbindung
    | INTID '(' {
        cout << "Funktion erkannt: " << $1 << endl; free($1);
        ;
    }
    | integer {
        ;
    }
    | pointer {
        ;
    }
    | ')' {
        ;
    }

//Ende eines Funktionsrumpfes
//TODO: Unterscheidung zwischen statement und Funktionsdefinition
    | '}' {
        ;
    }

    | ENDL {
        tokenProcessor.incrementLine();
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

//Arrayregeln
//array:
//    IDENTIFIER arraybrackets
//;
//Brauchen wir, da es auch mehrdimensionale Arrays geben kann.
//arraybrackets:
//    '[' ']'
//    | arraybrackets '[' ']'
//;

//Pointerregeln
pointer:
    POINTER
    | POINTER IDENTIFIER
    | POINTER '=' CSTRING
    | POINTER '=' IDENTIFIER
    | POINTER '=' '&' IDENTIFIER
;

//Definitionsregeln für Datentypen
integer:
    INTID
    | INTID '=' INUMBER
    | INTID '=' IDENTIFIER
;
floating:
    FLOATID
    | FLOATID '=' FNUMBER
    | FLOATID '=' IDENTIFIER
;
double:
    DOUBLEID
    | DOUBLEID '=' FNUMBER
    | DOUBLEID '=' IDENTIFIER
;
character:
    CHARID
    | CHARID '=' CHARACTER
    | CHARID '=' IDENTIFIER
;
short:
    SHORTID
    | SHORTID '=' INUMBER
    | SHORTID '=' IDENTIFIER
;
long:
    LONGID
    | LONGID '=' INUMBER
    | LONGID '=' IDENTIFIER
;
long_long:
    LONGLONGID
    | LONGLONGID '=' INUMBER
    | LONGLONGID '=' IDENTIFIER
;
long_double:
    LONGDOUBLEID
    | LONGDOUBLEID '=' FNUMBER
    | LONGDOUBLEID '=' IDENTIFIER
;
struct:
    STRUCT IDENTIFIER
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