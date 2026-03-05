%{
#include <stdio.h>
%}

%%

[A-Z]           { printf("Uppercase letter\n"); }
[a-z]           { printf("Lowercase letter\n"); }
[0-9]           { printf("Number\n"); }
[^a-zA-Z0-9\n]  { printf("Special character\n"); }
\n              { return 0; }

%%

int main()
{
    printf("Enter a character: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
