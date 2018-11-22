%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID NUM
%right '='
%left '+''-'
%left '*''/'
%right UMINUS
%%

S	: E {printf("Input accepted.\n");exit(0);}
	;
    
E	: ID'='E
	| E'+'E
	| E'-'E
	| E'*'E
	| E'/'E
	| '('E')'
	| ID
	| NUM
	;
%%

#include "lex.yy.c"

main(){
	printf("Enter the exp: ");
	yyparse();
}
