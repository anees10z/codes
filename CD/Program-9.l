%{
#include<stdio.h>
int comp = 0;
%}

%%
(and|but|or|because|so)   { comp = 1; }

\n                        { return 0; }

.                         ;

%%

int yywrap() { 
    return 1; 
}

int main()
{
    printf("Enter any sentence:\n");
    yylex();

    if(comp)
        printf("Compound Statement\n");
    else
        printf("Simple Statement\n");

    return 0;
}