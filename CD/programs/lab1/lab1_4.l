%{
#include<stdio.h>
%}
%%
[a-zA-Z_] {printf("\n %s is a character",yytext);}
[0-9_] {printf("\n %s is a digit",yytext);}
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
