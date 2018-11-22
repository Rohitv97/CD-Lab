alpha [A-Za-z]
digit [0-9]
%%
[ \t\n]
{alpha} {return ALPHA;}
{digit} {return DIGIT;}
.    {return yytext[0];}
%%

