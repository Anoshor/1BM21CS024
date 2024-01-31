%{
#include<stdio.h>
int c=0;
%}
%%
([a-zA-Z0-9])+ {c++;}
\n {printf ("Count is %d", c);}

%%
int yywrap()
{
}
int main()
{
printf("Enter input:");
yylex();
return 0;
}
