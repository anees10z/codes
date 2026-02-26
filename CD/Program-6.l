%{
#include <stdio.h>
#include <string.h>

int i = 0, o = 0, k, flag = 0;
char id[10][10], op[10][10];
%}

%%

[0-9]+  { flag++; strcpy(id[i], yytext); i++; }

[+*/-]  { flag--;strcpy(op[o], yytext);o++; }

"<"|">"|"<="|">="|"=="|"!="  { printf("\nEnter valid operators\n"); break; }

.|\n  { return 0; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("\nEnter any expression\n");
    printf("\nEnter only arithmetic operators (+, *, /, -) and numbers (0-9)\n");

    yylex();

    if (flag != 1)
    {
        printf("\nNot a valid expression\n");
    }
    else
    {
        printf("\nValid Expression\n");

        printf("\nOperators are:\n");
        for (k = 0; k < o; k++)
            printf("%s\t", op[k]);

        printf("\nIdentifiers are:\n");
        for (k = 0; k < i; k++)
            printf("%s\t", id[k]);
    }

    return 0;
}