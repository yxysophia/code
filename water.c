#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
int dink_water(int money)
{
	int total = money;//������money��ƿ��
	int empty = money;//������money����ƿ��
	while (empty > 1)//ֻҪ��ƿ��������1���Ϳ���һֱ��
	{
		total = total +empty / 2;
		empty = empty / 2 + empty % 2;
		//���ٺ���empty/2ƿ��ˮ������empty/2����ƿ�ӣ�����ȡ���ڿ�ƿ��������������ż����
	}
	return total;
}
int main()
{
	int money = 0;
	printf("������Ǯ��\n");
	scanf("%d", &money);
	int ret = dink_water(money);
	printf("drink:%d\n", ret);
	system("pause");
	return 0;
}