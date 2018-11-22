%{
#include<stdio.h>
extern int yylval;
%}
digit [0-9]
%%
[ \t\n]

{digit}+    {yylval=atoi(yytext);
		return NUM;}
.    return yytext[0];
%%

