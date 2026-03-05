%{
#include <stdio.h>

int lines = 0;
int chars = 0;
%}

%%

\n      { lines++; chars++; }
.       { chars++; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;

    fp = fopen("input.txt", "r");   // text file name

    if(fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    yyin = fp;
    yylex();

    printf("Number of lines: %d\n", lines);
    printf("Number of characters: %d\n", chars);

    fclose(fp);
    return 0;
}
