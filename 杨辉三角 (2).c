#include<stdio.h>
int main()
{
	int i,j,cnt,n;
	//int a[30][30];
	while(scanf("%d",&n)!=EOF)
	{
	int a[n][n];

	for(i=0;i<n;i++)
	 {
		a[i][0]=1;
		a[i][i]=1;
	 }
	 for(i=2;i<n;i++)
	 for(j=1;j<i;j++)
	 a[i][j]=a[i-1][j-1]+a[i-1][j];
	 for(i=0;i<n;i++)
	 {
	   cnt=1;
	   for(j=0;j<=i;j++)
	   {
	 
	 	  if(cnt==1)
	 	 {
		   printf("%d",a[i][j]);
		   cnt++;
		 }
		 else
		 printf(" %d",a[i][j]);
	   }
	  printf("\n"); 
     }
     printf("\n");
 }
	  return 0;
	 
}
