%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
[0-9]+     {
                int num = atoi(yytext);

                if(num % 2 == 0)
                    printf("Even Number\n");
                else
                    printf("Odd Number\n");

                return 0;
           }

[a-zA-Z]+  {
                printf("Enter valid number\n");
                return 0;
           } 

\n         { return 0; }
%%

int yywrap() { 
    return 1; 
}

int main()
{
    printf("Enter any number:\n");
    yylex();
    return 0;
} 
