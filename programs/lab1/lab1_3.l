%{
#include<stdio.h>
%}
%%
[a-zA-Z_]* {printf("\n %s is stream of characters",yytext);}
[0-9_]* {printf("\n %s is a stream of digits",yytext);}
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
