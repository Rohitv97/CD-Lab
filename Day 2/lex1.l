%{
#include <stdio.h>
%}
%%
0(10|01)* {printf("Given string is valid");}
.* {printf("Invalid");}
%%
int yywrap(){
	return 1;
}
void main(){
	
	printf("Enter the string: ");
	yylex();
	
}
