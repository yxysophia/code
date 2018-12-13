#include<stdio.h>
int main()
{
	int milkcount=0,teacount=0,juicecount=0;
	float discount=0.9;
	float total=0;
	printf("\t*************menu*************\n");
	printf("\t*   1.milk 5.00/cup          *\n");
	printf("\t*     2.tea  10.00/cup       *\n");
	printf("\t*    3.juice 15.00/cup       *\n");
	printf("\t******************************\n");
	printf("please input what you want to drink?\n");
	scanf("%d %d %d",&milkcount,&teacount,&juicecount);
	total=milkcount*5+teacount*10+juicecount*15;
	total*=discount;
	printf("\t************invoice***********\n");
	printf("\t*   1.milk 5*%d=%d  *\n",milkcount,5*milkcount);
	printf("\t*   2.tea  10*%d=%d *\n",teacount,10*teacount);
	printf("\t*   3.juice 15*%d=%d *\n",juicecount,15*juicecount);
	
	printf("you should pay %.2f\n",total);
	printf("\t******************************\n");
	return 0;
	 
	
	
}
