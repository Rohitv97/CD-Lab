%{
#include <stdio.h>
%}
%%
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short|unsigned {printf("%s is a keyword\n",yytext);}
[a-zA-Z]*|([a-zA-Z][0-9])* {printf("%s is an identifier\n",yytext);}
[();,"{] {}
%%
int yywrap(){
	return 1;
}
void main(){
	FILE *fh;
	char filename[20];
	printf("Enter the filename: ");
	scanf("%s",filename);
	yyin = fopen(filename,"r");	
	yylex();
    	
} 
