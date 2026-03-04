// declarations
%{
    #include<stdio.h>
%}

// rules
%%

%%

// input wrap
int yywrap(){
    return 1;
}

// main program
void main(){
	yylex();

}
