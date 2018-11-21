//筛法求素数  从1开始、在某一个范围内从小到大的正整数，1不是素数，筛掉；
//从该范围内最小的素数开始，筛掉该数的倍数，依次类推，直至筛子为空。 
#include<stdio.h>
int main()
{
   	int i,j,n,m;
   	int a[10000];
	printf("请输入正整数数量n:\n") ;
	scanf("%d",&n);
	a[0]=0;
	for(i=1;i<n;i++)
	a[i]=1;
	for(i=2;i<=n;i++)
	{   
		for(j=2;j*i<=n;j++)
		{m=1;
		m=m*j*i;
		for(i=2;i<=n;i++)
		if(m==a[i])
		a[i]=0;}
    }
    for(i=2;i<=n;i++)
	{
	  if(a[i]==1)
	  printf("%d\t",a[i]);
	 
    }
    return 0;
}

