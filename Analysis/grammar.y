%{
  #include <cstdio>
  #include <string>
  #include <iostream>
  #include <fstream>
  #include <sys/stat.h>
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
    params ',' param
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

//Definitionsregeln für Datentypen
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

int main(int argc, char* argv[]) {

  FILE* input;
  string pfad;

  if(argc >= 2){
    input = fopen(argv[1], "r");
  } else {
    // the user give the File-pfad to be analysed  
    cout << "Geben Sie den Datei-Pfad an: ";
    do{
        getline(cin, pfad);
    } while(pfad.empty());

    input = fopen(pfad.c_str(), "r");
  }

  // Make sure it is valid:
  if (!input) {
    cout << "I can't open the file!" << endl;
    return 1;
  }

  cout << "Wenn Sie die Ausgabe in eine Datei speichern wollen, geben Sie jetzt bitte einen Pfad an." << endl
       << ": ";
  getline(cin, pfad);

  ofstream output;
  
  //Überprüfung auf Existenz.
  struct stat buffer;
  if(stat(pfad.c_str(), &buffer) == 0){
    cout << "Datei existiert bereits. Ueberschreiben? [J/N] ";
    char antwort = getchar();
    if(antwort == 'Y' || antwort == 'y' || antwort == 'J' || antwort == 'j'){
        output.open(pfad);
        cout.rdbuf(output.rdbuf());
    }
  } else if(!pfad.empty()) {
    output.open(pfad);
    cout.rdbuf(output.rdbuf());
  }

  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = input;
  
  // Parse through the input:
  yyparse();

  tokenProcessor.printResults();
}

void yyerror(const char *s) {
  cout << "Parse error on line: " << tokenProcessor.getLine() << " - Message: " << s << endl;
}

