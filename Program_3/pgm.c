#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[20],stack[20];
int main()
{
	char m[2][3][10]={
		{"aBa","Error","Error"},
		{"n","bB","n"}
	};
	int size[2][3]={3,5,5,1,2,1};
	int i,j,k,n,row,col;
	printf("Enter the input string:");
	scanf("%s",s);
	strcat(s,"$");
	n=strlen(s);
	stack[0]='$';
	stack[1]='A';
	i=1;
	j=0;
	printf("\nStack \t\tInput \n");
	while((stack[i]!='$')&&(s[j]!='$'))
	{
		if(stack[i]==s[j])
		{
			i--;
			j++;
		}
		switch(stack[i])
		{
			case'A':row=0;
				break;
			case'B':row=1;
				break;
		}
		switch(s[j])
		{
			case'a':col=0;
				break;
			case'b':col=1;
				break;
			case'$':col=2;
				break;
		}
		if(m[row][col][0]=='E')
		{
			printf("\nERROR");
			exit(0);
		}
		else if(m[row][col][0]=='n')
			i--;
		else if(m[row][col][0]==s[j])
		{
			for(k=size[row][col]-1;k>=0;k--)
			{
				stack[i]=m[row][col][k];
				i++;
			}
			i--;
		}
		for(k=0;k<=i;k++)
			printf("%c",stack[k]);
		printf("\t \t");
		for(k=j;k<=n;k++)
			printf("%c",s[k]);
		printf("\n");
	}
	if(i<0)
		printf("\nSUCCESS\n");
	else
		printf("\nERROR\n");
	return 0;
}
