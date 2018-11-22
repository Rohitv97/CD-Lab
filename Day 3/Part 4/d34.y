%{
#include <stdio.h>
#include <stdlib.h>
int flag=0;
%}
%token NUM 
%right '='
%left '+''-'
%left '*''/'
%left '('')'

%%
S       :E      {printf("\nResult = %d\n",$$); exit(0);}
        ;
E       :E'+'E	 {$$=$1+$3;}
        |E'-'E	 {$$=$1-$3;}
        |E'*'E	 {$$=$1*$3;}
        |E'/'E	 {$$=$1/$3;}
        
        |'('E')' {$$=$2;}
        | NUM	 {$$=$1;}
        ;


%%
#include "lex.yy.c"

main()
{
//FILE *f;
//fopen("input.txt","r");

printf("Enter Expression to be evaluated: ");
yyparse();


}


