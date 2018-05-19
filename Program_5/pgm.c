#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char tset[4][3][3]={{"-","B","?"},
{"+","C","D"},
{"*","0","1"},
{"=","A","2"}
};
int main()
{
int row,col;
for(row=0;row<4;row++)
{
col=2;
if(tset[row][col][0]=='?')
{
printf("\n LD RO,%s%s",tset[row][0],tset[row][1]);
}
else
{
if(tset[row][0][0]=='+')
{
printf("\nLD R1,%s",tset[row][1]);
printf("\nLD R2,%s",tset[row][2]);
printf("\n ADD R1,R1,R2");
}
else
{
if(tset[row][0][0]=='*')
{
printf("\n MUL R1,R1,R0");
}
else 
{
printf("\nST %s,R0",tset[row][1]);
}
}
}
}
printf("\n");
return 0;
}
