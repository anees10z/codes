%{
#include<stdio.h>
#include<string.h>

int i=0, o=0, k;
char id[10][10], op[10][10];
%}

%%

[a-zA-Z][a-zA-Z0-9]* { strcpy(id[i++], yytext); }

"<="|">="|"=="|"!="|"<"|">" { strcpy(op[o++], yytext); }

[+*/-] { printf("\nInvalid Operator Used\n"); return 0; }

[ \t\n] ;

. { printf("\nInvalid Character\n"); return 0; }

%%

int yywrap() { return 1; }

int main()
{
    printf("Enter expression:\n");
    yylex();

    if(i==2 && o==1)
        printf("\nValid Expression\n");
    else
        printf("\nInvalid Expression\n");

    return 0;
}