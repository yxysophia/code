#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>//���� �൱������
#include<math.h>
#include <functional>
using namespace std;

int n = 0;
int arr[100][100];//ÿ����ĸ߶�
int maxlen(int x, int y)
{
	//int Max = 1;
	if (x > 0 && x <= n && y>0 && y <= n)
	{
		int Max = 1;
		//�����λ���ϱߵ㵽�µ��Ϊm����λ�õ��µ������Ϊm+1
		if (arr[x - 1][y] < arr[x][y])//��
			Max = max(maxlen(x - 1, y) + 1, Max);
		if (arr[x + 1][y] < arr[x][y])
			Max = max(maxlen(x + 1, y) + 1, Max);//��
		if (arr[x][y + 1] < arr[x][y])//��
			Max = max(maxlen(x, y + 1) + 1, Max);
		if (arr[x][y - 1] < arr[x][y]) //��
			Max = max(maxlen(x, y - 1) + 1, Max);
		return Max;
	}
	return 0; //ע��ݹ�ʱ��int���ͷ���ʱ��Ҫ�˳��ú�����Ҫ�з���ֵ��ͨ����0���Ը���Ҳ��0
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