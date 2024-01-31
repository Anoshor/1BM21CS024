%{
#include<stdio.h>
int vow=0;
int con=0;
%}
%%
[aeiouAEIOU] {vow++;}
[a-zA-Z] {con++;}
\n {printf ("There are %d voweles and %d consonants\n", vow, con);}
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
