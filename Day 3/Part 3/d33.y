%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ALPHA DIGIT
%%

S	: E {printf("Input accepted.\n");exit(0);}
	;
    
E	: A
	| A D
	;
A	: ALPHA
	| A
	;
D	: DIGIT
	| D
	;

%%

#include "lex.yy.c"

main(){
	printf("Enter variable: ");
	yyparse();
}
