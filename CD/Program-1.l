
%{
#include<stdio.h>
int l=0, h=0;
%}

%%
[a-z] {printf("\nLower case"); l++;}
[A-Z] {printf("\nUpper case"); h++;}
.     {printf("\nUnknown");}
%%

int yywrap(){
	return 1;
}

void main(){
	printf("\nEnter a string: ");
	yylex();
	printf("\nLowercase: %d", l);
	printf("\nUppercase: %d", h);
}