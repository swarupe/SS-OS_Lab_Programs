%{
#include<stdio.h>
int count=0;
%}
op[\+\-\*\/\=]
nop[\,\;\""]
letter[a-zA-Z]
digit[0-9]
id {letter}*|({letter}{digit})+
notid({digit}{letter})+
%%
[\t\n]+
("int")|("float")|("char")|("case")|("default")|("if")|("for")|("printf")|("scanf") {printf("%s is a keyword\n",yytext);}
{id} {printf("%s is an identifier\n",yytext);count++;}
"+"|"-"|"*"|"/"|"=" {printf("%s is not an identifier\n",yytext);}
{notid} {printf("%s is not an identifier\n",yytext);}
","|";"|"''" {;}
%%
int main()
{
FILE *fp;
char file[10];
printf("\n enter the filename:");
scanf("%s",file);
fp=fopen(file,"r");
yyin=fp;
yylex();
printf("total identifiers are:%d\n",count);
return 0;
}
yywrap()
{
return 1;
}
