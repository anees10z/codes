%{
#include<stdio.h>

int i = 0, o = 0;
%}

%%

// identifier
[a-zA-Z][a-zA-Z0-9]* { i++; }

// relational operators
"<="|">="|"=="|"!="|"<"|">" { o++; }

// invalid operators
[+*/-] { printf("\nInvalid Operator Used\n"); return 0; }

// ignore spaces
[ \t\n] ;

// invalid character
. { printf("\nInvalid Character\n"); return 0; }

%%

int yywrap() { return 1; }

int main()
{
    printf("Enter expression:\n");
    yylex();

    if(i == 2 && o == 1)
        printf("\nValid Expression\n");
    else
        printf("\nInvalid Expression\n");

    return 0;
}
