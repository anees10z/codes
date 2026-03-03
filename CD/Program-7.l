%{
#include<stdio.h>
%}

%% 
[a-zA-Z0-9 ]+   {
                    printf("\nLength of the string entered: %d\n", yyleng);
                    return 0;
                }
\n              { return 0; }
%%

int yywrap() { 
    return 1; 
}

int main()
{
    printf("Enter any string:\n");
    yylex();
    return 0;
}
