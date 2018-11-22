alpha [A-Za-z]
digit [0-9]
%%
[ \t\n]
{digit}+    {return NUM;}
{alpha}({alpha}|{digit})*    {return ID;}
.    {return yytext[0];}
%%

