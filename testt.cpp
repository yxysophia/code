#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>//容器 相当于数组
#include<math.h>
#include <functional>
using namespace std;

int n = 0;
int arr[100][100];//每个点的高度
int maxlen(int x, int y)
{
	//int Max = 1;
	if (x > 0 && x <= n && y>0 && y <= n)
	{
		int Max = 1;
		//假如该位置上边点到坡底最长为m，该位置到坡底最长距离为m+1
		if (arr[x - 1][y] < arr[x][y])//上
			Max = max(maxlen(x - 1, y) + 1, Max);
		if (arr[x + 1][y] < arr[x][y])
			Max = max(maxlen(x + 1, y) + 1, Max);//下
		if (arr[x][y + 1] < arr[x][y])//右
			Max = max(maxlen(x, y + 1) + 1, Max);
		if (arr[x][y - 1] < arr[x][y]) //左
			Max = max(maxlen(x, y - 1) + 1, Max);
		return Max;
	}
	return 0; //注意递归时，int类型返回时需要退出该函数需要有返回值，通常是0，对该题也是0
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int Maxlen = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			Maxlen = max(Maxlen, maxlen(i, j));
			//printf("%d\n", maxlen(i, j));
		}
	}
	printf("**************\n");
	printf("%d\n", Maxlen);
	//printf("%d\n", maxlen(3, 3));
	system("pause");
	return 0;
}