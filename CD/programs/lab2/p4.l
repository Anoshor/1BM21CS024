%{
#include<stdio.h>
%}
%%
[a-zA-Z | 0-9]* {printf("\n%s is alphanumeric",yytext);}
. {printf("\n%s is not alphanumeric",yytext);}
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
