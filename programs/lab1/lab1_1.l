%{
#include<stdio.h>
%}
%%
int|char|float {printf("\n %s is datatype", yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("\n %s is identifier",yytext);}
[0-9_]* {printf("\n %s is a digit",yytext);}
. {}
%%
int yywrap()
{
}
int main()
{
printf("enter input:");
yylex();
return 0;
}
