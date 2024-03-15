%{
#include<stdio.h>
%}
%%
[0-9]*[02468]+ {printf("\n%s is even",yytext);}
[0-9]*[13579]+ {printf("\n%s is odd",yytext);}
. {}
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
