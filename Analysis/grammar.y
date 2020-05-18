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
%token INT FLOAT CHAR
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
    | floating {
        tokenProcessor.processFloat();
    }
    | character {
        tokenProcessor.processCharacter();
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