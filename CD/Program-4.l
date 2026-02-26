%{
    #include<stdio.h>
%}

%%
while|for|if|else|do|return|continue|break { printf("\nKeyword\n"); }
[a-z]* { printf("\nNot a keyword\n"); }
%%


int yywrap(){
    return 1;
}


void main(){
    printf("Enter a string: ");
	yylex();
}