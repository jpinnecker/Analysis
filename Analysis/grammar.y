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

%union {
  char *sval;
}

%token <sval> STRING

// Constant String-Tokens
%token IDENTIFIER ENDL 

// Datatypes
%token UNSIGNED SIGNED VOID ARRAY
%token INT FLOAT CHAR DOUBLE LONG SHORT STRUCT

// Statement 
%token IF  WHILE

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
        tokenProcessor.processInteger();
    }
    | double {
         cout << "double found." << endl;
    }
    | floating {
        tokenProcessor.processFloat();
    }
    | character {
        tokenProcessor.processCharacter();
    }
    | long {
         cout << "long found." << endl;
    }
    | short {
         cout << "short found." << endl;
    }
    | struct {
         cout << "struct-datatyp found" << endl;
    }
    | unsigned {
         cout << "unsigned datatyp found" << endl;
    }
    | signed  {
         cout << "signed datatyp found" << endl;
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
    | ARRAY {
         cout << " array found" << endl;
    }
    | STRING {
        tokenProcessor.processString($1); free($1);
    }
    | ENDL {
        tokenProcessor.incrementLine();
    };
integer:
    INT IDENTIFIER ';'
    | INT IDENTIFIER  '=' INUMBER ';';
floating:
    FLOAT IDENTIFIER ';'
    | FLOAT IDENTIFIER '=' FNUMBER ';';
character:
    CHAR IDENTIFIER ';'
    | CHAR IDENTIFIER '=' CHARACTER ';';
double:
    DOUBLE IDENTIFIER ';'
    | DOUBLE IDENTIFIER '=' FNUMBER ';';
short:
    SHORT IDENTIFIER ';'
    | SHORT IDENTIFIER '=' INUMBER ';';
long:
    LONG IDENTIFIER ';'
    | LONG IDENTIFIER '=' INUMBER ';';
struct:
    STRUCT IDENTIFIER ';'
    | STRUCT IDENTIFIER '=' INUMBER ';';
unsigned:
    UNSIGNED;
signed:
    SIGNED;
ARRAY:
    [int|double|float|char|short] IDENTIFIER [] ';'
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