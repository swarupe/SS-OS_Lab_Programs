#include<stdio.h>
#include<stdlib.h>
void FIFO(char[],char[],int,int);
void lru(char [],char[],int,int);
void opt(char [],char[],int,int);
int main()
{
	int ch,YN,i,l,f;
	char F[10],s[25];
	printf("\n\n\tEnter the no of empty frames:");
	scanf("%d",&f);
	printf("\n\n\tEnter the length of the strings:");
	scanf("%d",&l);
	printf("\n\n\t enter the string:");
	scanf("%s",s);
	for(i=0;i<f;i++)
		F[i]=-1;
	do{
		printf("\n\n\t*********MENU***********");
		printf("\n\n\t1:FIFO\n\n\t2:LRU\n\n\t3:EXIT");
		printf("\n\n\tEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			for(i=0;i<f;i++)
			{
				F[i]=-1;
			}
			FIFO(s,F,l,f);
			break;
		case 2:
			for(i=0;i<f;i++)
			{
				F[i]=-1;
			}
			lru(s,F,l,f);
			break;
		case 4:
			exit(0);
		}
		printf("\n\n\tDo you want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0:");
		scanf("%d",&YN);
	}while(YN);
	return(0);
}
void FIFO(char s[],char F[],int l,int f)
{
	int i,j=0,k,flag=0,cnt=0;
	printf("\n\tPAGE\t FRAMES\tFAULTS");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
				flag=1;
		}
		if(flag==0)
		{
			printf("\n\t%c\t",s[i]);
			F[j]=s[i];
			j++;
			for(k=0;k<f;k++)
			{
				printf("%c",F[k]);
			}
			printf("\tpage-fault%d",cnt);
			cnt++;
		}
		else
		{
			flag=0;
			printf("\n\t%c\t",s[i]);
			for(k=0;k<f;k++)
			{
				printf("%c",F[k]);
			}
			printf("\tNo page-fault");
		}
		if(j==f)
			j=0;
	}
}
void lru(char s[],char F[],int l,int f)
{
	int i,j=0,k,m,flag=0,cnt=0,top=0;
	printf("\n\tPAGE\t FRAMES\tFAULTS");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		{
			if(F[k]==s[i])
			{
				flag=1;
				break;
			}
		}
		printf("\n \t%c\t",s[i]);
		if(j!=f&&flag!=1)
		{
			F[top]=s[i];
			j++;
			if(j!=f)
				top++;
		}
		else {
			if(flag!=1)
			{
				for(k=0;k<top;k++)
				{
					F[k]=F[k+1];
				}
				F[top]=s[i];
			}
			if(flag==1)
			{
				for(m=k;m<top;m++)
				{
					F[m]=F[m+1];
				}
				F[top]=s[i];
			}
		}
		for(k=0;k<f;k++)
		{
			printf("%c",F[k]);
		}
		if(flag==0)
		{
			printf("\tPage-fault%d",cnt);
			cnt++;
		}
		else
			printf("\t NO page fault");
		flag=0;
	}
}


