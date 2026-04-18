%{
#include <stdio.h>

int num = 0, op = 0;
%}

%%

// numbers
[0-9]+   { num++; }

// arithmetic operators
[+*/-]   { op++; }

// relational operators not allowed
"<"|">"|"<="|">="|"=="|"!="  { 
    printf("\nInvalid Operator Used\n"); 
    return 0; 
}

// ignore spaces
[ \t\n] ;

// invalid character
.   { 
    printf("\nInvalid Character\n"); 
    return 0; 
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("\nEnter any expression:\n");
    yylex();

    // valid expression condition
    if (num == op + 1)
        printf("\nValid Expression\n");
    else
        printf("\nInvalid Expression\n");

    return 0;
}
