%{
    #include<stdio.h>
    int v=0, c=0;
%}

%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%

int yywrap(){
    return 1;
}

void main(){
    printf("\nEnter a string: ");
	yylex();
    printf("\nVowels: %d", v);
    printf("\nConsonants: %d", c);
}