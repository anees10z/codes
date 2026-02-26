%{
#include<stdio.h>
int c=0, l=0, s=0, t=0;
%}

%%
[a-zA-Z] {printf("\nCharacters"); c++;}
[\n]       {printf("\nLines"); l++;}
[ ]        {printf("\nSpace"); s++;}
[\t]       {printf("\ntabs"); t++;}
%%

int yywrap(){
	return 1;
}

void main(){
	printf("\nEnter a string: ");
	yylex();
	printf("\nCharacters: %d", c);
	printf("\nLines: %d", l);
	printf("\nSpaces: %d", s);
	printf("\nTabs: %d", t);
}