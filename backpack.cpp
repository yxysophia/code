#define _CRT_SECURE_NO_WARNINGS 1
#include <functional>
#include<iostream>
#include<stdlib.h>
//��01����
const int itemnum = 25;//��Ʒ��
const int valunum = 2005;//�������
int item[itemnum];
int volu[valunum];
int dp[itemnum][valunum];
int main()
{
	int V = 0, N = 0;//V�����������N����Ʒ��
	scanf("%d %d", &V, &N);
	//��Ʒ�����
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &item[i]);
	}
	//����һ�е�һ�г�ʼ��Ϊ0
	for (int i = 0; i <= V; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= V; j++)
		{
			if (item[i] > j)
				dp[i][j] = dp[i - 1][j];//���Ÿ���Ʒ
			else //�����ǰ��Ʒ���С�ڵ��ڴ�ʱ����������������װ�µ��������Ϊ���Ÿ���Ʒ�ͷŸ���Ʒ�������ֵ
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i]] + item[i]);
		}
	}
	printf("%d\n", V - dp[N][V]);
	system("pause");
	return 0;
}
////01��ֵ����
//����й���Ԫ��Ϊ����Ϊj�ı����Ŀ���װǰI��
const int maxN = 105;
const int maxM = 105;
int main()
{
	int M, N;
	int vum[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (int i = 1; i <= M; i++)
			scanf("%d", &vum[i]); //ÿ����Ʒ���
		for (int i = 1; i <= M; i++)
			scanf("%d", &value[i]);//ÿ����Ʒ��ֵ
								   //��һ�г�ʼ��Ϊ0
		for (int j = 0; j <= N; j++)
		{
			dp[0][j] = 0;
		}
		//��һ�г�ʼ��Ϊ0
		for (int i = 0; i <= M; i++)
		{
			dp[i][0] = 0;
		}
		//N������  M������
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (vum[i] > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vum[i]] + value[i]);
			}
		}
		printf("%d\n", dp[M][N]);
	}
	system("pause");
	return 0;
}
//��ȫ����
const int maxN = 105;
const int maxM = 105;
int main()
{
	int M, N;
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	int num[maxM] = { 0 };//��¼ÿ����Ʒ�Ŷ���
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (int i = 1; i <= M; i++)
			scanf("%d", &weight[i]); //ÿ����Ʒ���
		for (int i = 1; i <= M; i++)
			scanf("%d", &value[i]);//ÿ����Ʒ��ֵ
								   //��һ�г�ʼ��Ϊ0
		for (int j = 0; j <= N; j++)
		{
			dp[0][j] = 0;
		}
		//��һ�г�ʼ��Ϊ0
		for (int i = 0; i <= M; i++)
		{
			dp[i][0] = 0;
		}
		//N������  M������
		//����ǰi����Ʒǡ����һ������Ϊj�ı������Ի�õ�����ֵ
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (weight[i] <= j)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]); //ע����dp[i][j-weight[i]],��ΪҪ���Ƿ���һ����Ʒiʱ���ܼ�������i
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		//����ÿ����Ʒ����ĸ���
		int j = N;
		for (int i = M; i > 0; i--)
		{
			if (dp[i][j] == dp[i][j - weight[i]] + value[i])
			{
				num[i]++;
				j = j - weight[i];
			}
		}
		//��ӡǰi����Ʒǡ����һ������Ϊj�ı������Ի�õ�����ֵ
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		//M����Ʒ��������ΪN�ı���������ֵ
		printf("%d\n", dp[M][N]);
		//ÿ����Ʒ����ĸ���
		for (int i = 1; i <= M; i++)
		{
			printf("%d ", num[i]);
		}
	}
	system("pause");
	return 0;
}
////���ر���
//����һ��ת��Ϊ01����
const int maxN = 105;
const int maxM = 105;
int main()
{
	int kind = 0, N = 0; //N�Ǳ���������kind����Ʒ����
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	scanf("%d %d", &kind, &N);
	int countnum = 1;//һ������Ʒ��
	for (int i = 0; i < kind; i++)
	{
		int num;//ÿ����Ʒ��num����
		scanf("%d", &num);
		int weight1, value1;
		scanf("%d %d", &weight1, &value1);
		while (num--)
		{
			weight[countnum] = weight1;
			value[countnum] = value1;
			//����ÿ����Ʒ��ÿ����Ʒ������ͼ�ֵ
			countnum++;
		}
	}
	//��һ�г�ʼ��Ϊ0
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	//��һ�г�ʼ��Ϊ0
	for (int i = 0; i < countnum; i++)
		dp[i][0] = 0;
	for (int i = 1; i < countnum; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (weight[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[countnum - 1][N]);
	system("pause");
	return 0;
}
//��������
const int maxN = 105;
const int maxM = 105;
int main()
{
	int kind = 0, N = 0; //N�Ǳ���������kind����Ʒ����
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	int num[maxM];
	scanf("%d %d", &kind, &N);
	for (int i = 1; i <= kind; i++)
	{
		scanf("%d", &num[i]);//ÿ����Ʒ������
		scanf("%d %d", &weight[i], &value[i]);//ÿ����Ʒ������ͼ�ֵ
	}
	//��һ�г�ʼ��Ϊ0
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	//��һ�г�ʼ��Ϊ0
	for (int i = 0; i <= kind; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= kind; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (weight[i] <= j)
			{
				int count = min(num[i], j / weight[i]);//ȡ�ָ���Ʒ�����ʹ�ʱ�����������ɸ���Ʒ������Сֵ
				for (int k = 1; k <= count; k++)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k*weight[i]] + k*value[i]);//ע����dp[i - 1][j - k*weight[i]] 
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d\n", dp[kind][N]);
	system("pause");
	return 0;
}

