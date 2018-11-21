#include<stdio.h>
int main()
{
	 int n;
	 int i,j,m,k,t,cnt;
	 int a[100];
	 while(scanf("%d",&n)!=EOF)
	 {
	 	if(n<1||n>100)
	 	break;
	 	for(i=0;i<n;i++) 
	 	scanf("%d",&a[i]);
	 	m=a[0];
	 	t=0,cnt=0;
	 	for(j=1;j<n;j++)
		 if(a[j]<m){
	 		m = a[j];
	 		t=j;
		}  	
		if(t!=0){
	 	k=a[0];
	 	a[0]=a[t];
	 	a[t]=k;}
	 	for(i=0;i<n;i++){
		 
	    if(cnt==0)
		 {
		 printf("%d",a[i]);
		 cnt++; }
		else
		printf(" %d",a[i]); 
		} printf("\n");
	 } 
	return 0;


}

