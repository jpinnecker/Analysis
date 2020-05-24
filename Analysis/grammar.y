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
%token IDENTIFIER ENDL 

// Datatypes
%token UNSIGNED SIGNED VOID ARRAY
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
    | struct {
        cout << "struct-datatyp found" << endl;
    }
    | VOID  {
        cout << "function without return variable found" << endl;
    }
    | IF {
        cout << "if statement found" << endl;
    }
    | WHILE {
        cout << "While statement found" << endl;
    }
//    | ARRAY {
//         cout << " array found" << endl;
//    }
    | ENDL {
        tokenProcessor.incrementLine();
    };
datatype:
    integer
    | floating
    | character
    | double
    | long_double
    | short
    | long_long
    | long;
integer:
    SIGNED IDENTIFIER ';'
    | SIGNED IDENTIFIER '=' INUMBER ';'
    | SIGNED INT IDENTIFIER ';'
    | SIGNED INT IDENTIFIER '=' INUMBER ';'
    | INT IDENTIFIER ';'
    | INT IDENTIFIER  '=' INUMBER ';'
    | UNSIGNED IDENTIFIER ';'
    | UNSIGNED IDENTIFIER '=' INUMBER ';'
    | UNSIGNED INT IDENTIFIER ';'
    | UNSIGNED INT IDENTIFIER '=' INUMBER ';';
floating:
    FLOAT IDENTIFIER ';'
    | FLOAT IDENTIFIER '=' FNUMBER ';';
character:
    CHAR IDENTIFIER ';'
    | CHAR IDENTIFIER '=' CHARACTER ';'
    | SIGNED CHAR IDENTIFIER ';'
    | SIGNED CHAR IDENTIFIER '=' CHARACTER ';'
    | UNSIGNED CHAR IDENTIFIER ';'
    | UNSIGNED CHAR IDENTIFIER '=' CHARACTER ';';
double:
    DOUBLE IDENTIFIER ';'
    | DOUBLE IDENTIFIER '=' FNUMBER ';';
long_double:
    | LONG DOUBLE IDENTIFIER ';'
    | LONG DOUBLE IDENTIFIER '=' INUMBER ';';
short:
    SHORT IDENTIFIER ';'
    | SHORT IDENTIFIER '=' INUMBER ';'
    | SIGNED SHORT IDENTIFIER ';'
    | SIGNED SHORT IDENTIFIER '=' INUMBER ';'
    | UNSIGNED SHORT IDENTIFIER ';'
    | UNSIGNED SHORT IDENTIFIER '=' INUMBER ';'
    | SHORT INT IDENTIFIER ';'
    | SHORT INT IDENTIFIER '=' INUMBER ';'
    | SIGNED SHORT INT IDENTIFIER ';'
    | SIGNED SHORT INT IDENTIFIER '=' INUMBER ';'
    | UNSIGNED SHORT INT IDENTIFIER ';'
    | UNSIGNED SHORT INT IDENTIFIER '=' INUMBER ';';
long:
    LONG IDENTIFIER ';'
    | LONG IDENTIFIER '=' INUMBER ';'
    | SIGNED LONG IDENTIFIER ';'
    | SIGNED LONG IDENTIFIER '=' INUMBER ';'
    | UNSIGNED LONG IDENTIFIER ';'
    | UNSIGNED LONG IDENTIFIER '=' INUMBER ';'
    | LONG INT IDENTIFIER ';'
    | LONG INT IDENTIFIER '=' INUMBER ';'
    | SIGNED LONG INT IDENTIFIER ';'
    | SIGNED LONG INT IDENTIFIER '=' INUMBER ';'
    | UNSIGNED LONG INT IDENTIFIER ';'
    | UNSIGNED LONG INT IDENTIFIER '=' INUMBER '=';
long_long:
    | LONG LONG IDENTIFIER ';'
    | LONG LONG IDENTIFIER '=' INUMBER ';'
    | SIGNED LONG LONG IDENTIFIER ';'
    | SIGNED LONG LONG IDENTIFIER '=' INUMBER ';'
    | UNSIGNED LONG LONG IDENTIFIER ';'
    | UNSIGNED LONG LONG IDENTIFIER '=' INUMBER ';'
    | LONG LONG INT IDENTIFIER ';'
    | LONG LONG INT IDENTIFIER '=' INUMBER ';'
    | SIGNED LONG LONG INT IDENTIFIER ';'
    | SIGNED LONG LONG INT IDENTIFIER '=' INUMBER ';'
    | UNSIGNED LONG LONG INT IDENTIFIER ';'
    | UNSIGNED LONG LONG INT IDENTIFIER '=' INUMBER ';';

struct:
    STRUCT IDENTIFIER ';'
    | STRUCT IDENTIFIER '=' INUMBER ';';
//ARRAY:
//    [int|double|float|char|short] IDENTIFIER [] ';';
%%

int main(int, char**) {
  // Open a file handle to a particular file:
  FILE *myfile;
  errno_t err = fopen_s(&myfile, "code.c", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open the file!" << endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // Parse through the input:
  yyparse();

  tokenProcessor.printResults();
}

void yyerror(const char *s) {
  cout << "Parse error on line: " << tokenProcessor.getLine() << " - Message: " << s << endl;
  exit(-1);
}