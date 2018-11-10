#include<stdio.h>
int main()
{
	int m=6;
	int i,j,N;
	char a[20];
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%s",a);
		 printf("%d",m); 
		 for(j=6;j<11;j++)
		 printf("%c",a[j]);
		// putchar(a[j]);
		printf("\n");	
    } 
	 return 0;
 } 
