#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
//Alice和Bob
//int main()
//{
//	int a[1000] = { 0 };
//	int T = 0;
//	scanf("%d", &T);
//	while (T--)
//	{
//		int num = 0;
//		int i = 0;
//		scanf("%d", &num);
//		int len = num;
//		while (len--)
//		{
//			scanf("%d", &a[i]);
//			i++;
//		}
//		
//		int flag = 0;
//		for (int i = 1; i < num; i++)
//		{
//			for (int j = 0; j < num - i; j++)
//			{
//
//				if (a[j] > a[j + 1])
//				{
//					flag = 1;
//					int tmp = a[j];
//					a[j] = a[j + 1];
//					a[j + 1] = tmp;
//				}
//			}
//			if (flag == 0)
//				break;
//		}
//		int mid = num / 2;
//		if (a[mid] % 2 == 0)
//			printf("Alice\n");
//		else
//			printf("Bob\n");		
//	}
//	system("pause");
//	return 0;
//}
////////////////英文转阿拉伯数字

//int main()
//{
//	char str[10] = { 0 };
//	char* letter[11] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten" };
//	while (scanf("%s", str) != EOF)
//	{
//		int i = 0;
//		int num = sizeof(letter) / sizeof(letter[0]);
//		while (num--)
//		{
//			if (strcmp(str, letter[i]) == 0)
//			{
//				printf("%d\n", i );
//				break;
//			}
//			else
//				i++;
//		}
//	}
//	system("pause");
//	return 0;
//}

//花括号匹配
typedef struct Stack
{
	char *array;
	int _capacity;
	int top;
}Stack;
//初始化栈
void StackInit(Stack *st,int capacity)
{
	st->array = (char*)malloc(sizeof(char)*capacity);
	st->top = 0;
	st->_capacity = capacity;
}
//进栈
void StackPush(Stack *st, char data)
{
	if (st->top == st->_capacity)
	{
		//扩容
		st->array = (char*)realloc(st->array, sizeof(char)*st->_capacity * 2);
		st->_capacity = st->_capacity * 2;
	}
	//进栈
	st->array[st->top] = data;
	st->top++;
}
//出栈
void StackPop(Stack *st)
{
	if (st->top == 0)
	{
		return;
	}
	st->top--;
}
//栈为空 0为空 1非空
int StackEmpty(Stack *st)
{
	if (st->top == 0)//空
		return 0;
	return 1;//非空
}
int main()
{
	char str[1000];
	while (fgets(str,1000,stdin))
	{
		Stack st;
		StackInit(&st, 3);
		int i = 0;
		while (StackEmpty(&st) || str[i])
		{

			if (')' == str[i] && StackEmpty(&st))
			{
				StackPop(&st);
			}
			else if (')' == str[i] && StackEmpty(&st) == 0)//没有匹配
			{
				break;
			}
			else if ('(' == str[i])
			{
				StackPush(&st, '(');
			}
			i++;
		}
		if (StackEmpty(&st) == 0 && str[i] == '\0')
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
	return 0;
}

//种树
//int main()
//{
//	int N = 0, M = 0, K = 0;//N代表区域的宽，M代表区域的长，K代表几个区域
//	while (scanf("%d %d %d", &N, &M, &K) && N != 0 && M != 0 && K != 0)
//	{
//		int count = 0;
//		int tree[100][100] = { 0 };
//		while (K--)
//		{
//			int x1, y1, x2, y2;
//			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//			for (int row = x1-1; row < x2; row++)//行
//			{
//				for (int col = y1 - 1; col < y2; col++)//列
//				{
//					if (tree[row][col] == 0)
//					{
//						tree[row][col] = 1;
//						count++;
//					}
//				}
//			}
//		}
//		printf("%d\n", count);
//	}
//	system("pause");
//	return 0;
//}