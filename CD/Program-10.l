%{
#include<stdio.h>
#include<stdlib.h>
%}

%%
[0-9]+     {
                int num = atoi(yytext);
                int n = num;
                int rem, rev = 0;

                while(num > 0)
                {
                    rem = num % 10;
                    rev = rev * 10 + rem;
                    num = num / 10;
                }

                printf("Number entered: %d\n", n);
                printf("Reverse of Number: %d\n", rev);

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