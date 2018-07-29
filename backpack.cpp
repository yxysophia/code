#define _CRT_SECURE_NO_WARNINGS 1
#include <functional>
#include<iostream>
#include<stdlib.h>
//简单01背包
const int itemnum = 25;//物品数
const int valunum = 2005;//最大容量
int item[itemnum];
int volu[valunum];
int dp[itemnum][valunum];
int main()
{
	int V = 0, N = 0;//V是体积容量，N是物品数
	scanf("%d %d", &V, &N);
	//物品的体积
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &item[i]);
	}
	//将第一行第一列初始化为0
	for (int i = 0; i <= V; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= V; j++)
		{
			if (item[i] > j)
				dp[i][j] = dp[i - 1][j];//不放该物品
			else //如果当前物品体积小于等于此时最大体积容量，可以装下的最大容量为不放该物品和放该物品容量最大值
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i]] + item[i]);
		}
	}
	printf("%d\n", V - dp[N][V]);
	system("pause");
	return 0;
}
////01价值问题
//表格中国的元素为容量为j的背包的可以装前I个
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
			scanf("%d", &vum[i]); //每个物品体积
		for (int i = 1; i <= M; i++)
			scanf("%d", &value[i]);//每个物品价值
								   //第一行初始化为0
		for (int j = 0; j <= N; j++)
		{
			dp[0][j] = 0;
		}
		//第一列初始化为0
		for (int i = 0; i <= M; i++)
		{
			dp[i][0] = 0;
		}
		//N是容量  M是数量
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
//完全背包
const int maxN = 105;
const int maxM = 105;
int main()
{
	int M, N;
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	int num[maxM] = { 0 };//记录每个物品放多少
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (int i = 1; i <= M; i++)
			scanf("%d", &weight[i]); //每个物品体积
		for (int i = 1; i <= M; i++)
			scanf("%d", &value[i]);//每个物品价值
								   //第一行初始化为0
		for (int j = 0; j <= N; j++)
		{
			dp[0][j] = 0;
		}
		//第一列初始化为0
		for (int i = 0; i <= M; i++)
		{
			dp[i][0] = 0;
		}
		//N是容量  M是数量
		//计算前i件物品恰放入一个容量为j的背包可以获得的最大价值
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (weight[i] <= j)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]); //注意是dp[i][j-weight[i]],因为要考虑放入一个物品i时可能继续放入i
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		//计算每个物品放入的个数
		int j = N;
		for (int i = M; i > 0; i--)
		{
			if (dp[i][j] == dp[i][j - weight[i]] + value[i])
			{
				num[i]++;
				j = j - weight[i];
			}
		}
		//打印前i件物品恰放入一个容量为j的背包可以获得的最大价值
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		//M个物品放入容量为N的背包的最大价值
		printf("%d\n", dp[M][N]);
		//每个物品放入的个数
		for (int i = 1; i <= M; i++)
		{
			printf("%d ", num[i]);
		}
	}
	system("pause");
	return 0;
}
////多重背包
//方法一：转化为01背包
const int maxN = 105;
const int maxM = 105;
int main()
{
	int kind = 0, N = 0; //N是背包容量，kind是物品种类
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	scanf("%d %d", &kind, &N);
	int countnum = 1;//一个的物品数
	for (int i = 0; i < kind; i++)
	{
		int num;//每种物品有num件，
		scanf("%d", &num);
		int weight1, value1;
		scanf("%d %d", &weight1, &value1);
		while (num--)
		{
			weight[countnum] = weight1;
			value[countnum] = value1;
			//输入每种物品的每件物品的体积和价值
			countnum++;
		}
	}
	//第一行初始化为0
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	//第一列初始化为0
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
//方法二：
const int maxN = 105;
const int maxM = 105;
int main()
{
	int kind = 0, N = 0; //N是背包容量，kind是物品种类
	int weight[maxM] = { 0 };
	int value[maxM] = { 0 };
	int dp[maxM][maxN];
	int num[maxM];
	scanf("%d %d", &kind, &N);
	for (int i = 1; i <= kind; i++)
	{
		scanf("%d", &num[i]);//每种物品的数量
		scanf("%d %d", &weight[i], &value[i]);//每种物品的体积和价值
	}
	//第一行初始化为0
	for (int i = 0; i <= N; i++)
		dp[0][i] = 0;
	//第一列初始化为0
	for (int i = 0; i <= kind; i++)
		dp[i][0] = 0;
	for (int i = 1; i <= kind; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (weight[i] <= j)
			{
				int count = min(num[i], j / weight[i]);//取种该物品件数和此时容量允许容纳该物品件数最小值
				for (int k = 1; k <= count; k++)
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k*weight[i]] + k*value[i]);//注意是dp[i - 1][j - k*weight[i]] 
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d\n", dp[kind][N]);
	system("pause");
	return 0;
}

