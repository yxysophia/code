#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
int dink_water(int money)
{
	int total = money;//保底有money个瓶子
	int empty = money;//保底有money个空瓶子
	while (empty > 1)//只要空瓶子数大于1，就可以一直喝
	{
		total = total +empty / 2;
		empty = empty / 2 + empty % 2;
		//当再喝了empty/2瓶汽水，就有empty/2个空瓶子，但还取决于空瓶子是奇数个还是偶数个
	}
	return total;
}
int main()
{
	int money = 0;
	printf("请输入钱数\n");
	scanf("%d", &money);
	int ret = dink_water(money);
	printf("drink:%d\n", ret);
	system("pause");
	return 0;
}