%{
  #include <cstdio>
  #include <iostream>
  #include "TokenProcessor.h"
  using namespace std;

  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
  
  TokenProcessor tokenProcessor = TokenProcessor();

  void yyerror(const char *s);
%}

// Constant String-Tokens
%token IDENTIFIER ENDL UNKNOWN

// Datatypes
%token UNSIGNED SIGNED VOID
%token INT FLOAT CHAR DOUBLE LONG SHORT STRUCT

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
    | struct {
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

//Funktionsdefinition
//TODO: Mehrere Datentypen
//TODO: Über den Fall 'Void' hinaus erweitern.
//TODO: TokenProcessor Anbindung
    | integer '(' datatype ')' '{' {
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
    | error ';' {
        cout << "Omitting error on line " << tokenProcessor.getLine() << endl;
    }
;
pointer:
    datatype '*' IDENTIFIER
    | datatype '*' IDENTIFIER '=' IDENTIFIER
    | datatype '*' IDENTIFIER '=' '&' IDENTIFIER
;
datatype:
    INT
    | SIGNED
    | FLOAT
    | CHAR
    | DOUBLE
    | LONG DOUBLE
    | SHORT
    | LONG LONG
    | LONG
    | VOID
;
integer:
    SIGNED IDENTIFIER
    | SIGNED IDENTIFIER '=' INUMBER
    | SIGNED IDENTIFIER '=' IDENTIFIER
    | SIGNED INT IDENTIFIER
    | SIGNED INT IDENTIFIER '=' INUMBER
    | SIGNED INT IDENTIFIER '=' IDENTIFIER
    | INT IDENTIFIER
    | INT IDENTIFIER  '=' INUMBER
    | INT IDENTIFIER '=' IDENTIFIER
    | UNSIGNED IDENTIFIER
    | UNSIGNED IDENTIFIER '=' INUMBER
    | UNSIGNED IDENTIFIER '=' IDENTIFIER
    | UNSIGNED INT IDENTIFIER
    | UNSIGNED INT IDENTIFIER '=' INUMBER
    | UNSIGNED INT IDENTIFIER '=' IDENTIFIER
;
floating:
    FLOAT IDENTIFIER
    | FLOAT IDENTIFIER '=' FNUMBER
    | FLOAT IDENTIFIER '=' IDENTIFIER
;
double:
    DOUBLE IDENTIFIER
    | DOUBLE IDENTIFIER '=' FNUMBER
    | DOUBLE IDENTIFIER '=' IDENTIFIER
;
character:
    CHAR IDENTIFIER
    | CHAR IDENTIFIER '=' CHARACTER
    | CHAR IDENTIFIER '=' IDENTIFIER
    | SIGNED CHAR IDENTIFIER
    | SIGNED CHAR IDENTIFIER '=' CHARACTER
    | SIGNED CHAR IDENTIFIER '=' IDENTIFIER
    | UNSIGNED CHAR IDENTIFIER
    | UNSIGNED CHAR IDENTIFIER '=' CHARACTER
    | UNSIGNED CHAR IDENTIFIER '=' IDENTIFIER
;
long_double:
    LONG DOUBLE IDENTIFIER
    | LONG DOUBLE IDENTIFIER '=' FNUMBER
    | LONG DOUBLE IDENTIFIER '=' IDENTIFIER
;
short:
    SHORT IDENTIFIER
    | SHORT IDENTIFIER '=' INUMBER
    | SHORT IDENTIFIER '=' IDENTIFIER
    | SIGNED SHORT IDENTIFIER
    | SIGNED SHORT IDENTIFIER '=' INUMBER
    | SIGNED SHORT IDENTIFIER '=' IDENTIFIER
    | UNSIGNED SHORT IDENTIFIER
    | UNSIGNED SHORT IDENTIFIER '=' INUMBER
    | UNSIGNED SHORT IDENTIFIER '=' IDENTIFIER
    | SHORT INT IDENTIFIER
    | SHORT INT IDENTIFIER '=' INUMBER
    | SHORT INT IDENTIFIER '=' IDENTIFIER
    | SIGNED SHORT INT IDENTIFIER
    | SIGNED SHORT INT IDENTIFIER '=' INUMBER
    | SIGNED SHORT INT IDENTIFIER '=' IDENTIFIER
    | UNSIGNED SHORT INT IDENTIFIER
    | UNSIGNED SHORT INT IDENTIFIER '=' INUMBER
    | UNSIGNED SHORT INT IDENTIFIER '=' IDENTIFIER
;
long:
    LONG IDENTIFIER
    | LONG IDENTIFIER '=' INUMBER
    | LONG IDENTIFIER '=' IDENTIFIER
    | SIGNED LONG IDENTIFIER
    | SIGNED LONG IDENTIFIER '=' INUMBER
    | SIGNED LONG IDENTIFIER '=' IDENTIFIER
    | UNSIGNED LONG IDENTIFIER
    | UNSIGNED LONG IDENTIFIER '=' INUMBER
    | UNSIGNED LONG IDENTIFIER '=' IDENTIFIER
    | LONG INT IDENTIFIER
    | LONG INT IDENTIFIER '=' INUMBER
    | LONG INT IDENTIFIER '=' IDENTIFIER
    | SIGNED LONG INT IDENTIFIER
    | SIGNED LONG INT IDENTIFIER '=' INUMBER
    | SIGNED LONG INT IDENTIFIER '=' IDENTIFIER
    | UNSIGNED LONG INT IDENTIFIER
    | UNSIGNED LONG INT IDENTIFIER '=' INUMBER
    | UNSIGNED LONG INT IDENTIFIER '=' IDENTIFIER
;
long_long:
    LONG LONG IDENTIFIER
    | LONG LONG IDENTIFIER '=' INUMBER
    | LONG LONG IDENTIFIER '=' IDENTIFIER
    | SIGNED LONG LONG IDENTIFIER
    | SIGNED LONG LONG IDENTIFIER '=' INUMBER
    | SIGNED LONG LONG IDENTIFIER '=' IDENTIFIER
    | UNSIGNED LONG LONG IDENTIFIER
    | UNSIGNED LONG LONG IDENTIFIER '=' INUMBER
    | UNSIGNED LONG LONG IDENTIFIER '=' IDENTIFIER
    | LONG LONG INT IDENTIFIER
    | LONG LONG INT IDENTIFIER '=' INUMBER
    | LONG LONG INT IDENTIFIER '=' IDENTIFIER
    | SIGNED LONG LONG INT IDENTIFIER
    | SIGNED LONG LONG INT IDENTIFIER '=' INUMBER
    | SIGNED LONG LONG INT IDENTIFIER '=' IDENTIFIER
    | UNSIGNED LONG LONG INT IDENTIFIER
    | UNSIGNED LONG LONG INT IDENTIFIER '=' INUMBER
    | UNSIGNED LONG LONG INT IDENTIFIER '=' IDENTIFIER
;
struct:
    STRUCT IDENTIFIER ';'
;
//ARRAY:
//    datatype IDENTIFIER '[' INUMBER ']' ';';
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