#include<stdio.h>	
#include<math.h>
int main()
{
	int a,b,sum1,sum2,i,t;
	while(scanf("%d%d",&a,&b)!=EOF)
	{   
	  if(a>b)
	  {
	  	t=a;
	  	a=b;
	  	b=t;
	 }     
	   sum1=0;
	   sum2=0;
		for(i=a;i<=b;i++)
		{   
			if(i%2==0)
			sum1=sum1+pow(i,2); 
			else
			sum2=sum2+pow(i,3);
		 } 
		 printf("%d %d\n",sum1,sum2);
	}
	return 0;
 } 
