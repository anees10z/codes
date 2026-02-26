// declarations
%{
    #include<stdio.h>
%}

// rules
%%

%%

// imput wrap
int yywrap(){
    return 1;
}

// main program
void main(){
	yylex();
}