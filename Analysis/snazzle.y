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

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  Initially (by default), yystype
// is merely a typedef of "int", but for non-trivial projects, tokens could
// be of any arbitrary data type.  So, to deal with that, the idea is to
// override yystype's default typedef to be a C union instead.  Unions can
// hold all of the types of tokens that Flex could return, and this this means
// we can return ints or floats or strings cleanly.  Bison implements this
// mechanism with the %union directive:
%union {
//  int ival;
  float fval;
  char *sval;
}

// Constant String-Tokens
%token ENDL
%token INT

// Define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the %union:
//%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <sval> IDENTIFIER

%%
// This is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
snazzle:
  snazzle INT     {
      cout << "int gefunden." << endl;
    }
  | snazzle FLOAT  {
      tokenProcessor.processFloat();
    }
  | snazzle STRING {
      tokenProcessor.processString($2); free($2);
    }
  | snazzle ENDL {
        tokenProcessor.incrementLine();
        }
  | INT IDENTIFIER ';'           {
      cout << "int gefunden." << endl;
    }
  | FLOAT          {
      tokenProcessor.processFloat();
    }
  | STRING         {
      tokenProcessor.processString($1); free($1);
    }
  | ENDL           {
      tokenProcessor.incrementLine();
    }
  ;
%%

int main(int, char**) {
  // Open a file handle to a particular file:
  FILE *myfile;
  errno_t err = fopen_s(&myfile, "a.snazzle.file", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open a.snazzle.file!" << endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // Parse through the input:
  yyparse();
  
  cout << endl;

  tokenProcessor.printResults();
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

// Test Commit