%{
#include<stdio.h>
%}
%%
[0-9_]* {printf("\n%s is a digit",yytext);}
. {printf("\n%s is not a digit",yytext);}
%%
int yywrap()
{
}
int main()
{
printf("enter input : ");
yylex();
return 0;
}
