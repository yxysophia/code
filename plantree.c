#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
//Alice��Bob
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
////////////////Ӣ��ת����������

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

//������ƥ��
typedef struct Stack
{
	char *array;
	int _capacity;
	int top;
}Stack;
//��ʼ��ջ
void StackInit(Stack *st, int capacity)
{
	st->array = (char*)malloc(sizeof(char)*capacity);
	st->top = 0;
	st->_capacity = capacity;
}
//��ջ
void StackPush(Stack *st, char data)
{
	if (st->top == st->_capacity)
	{
		//����
		st->array = (char*)realloc(st->array, sizeof(char)*st->_capacity * 2);
		st->_capacity = st->_capacity * 2;
	}
	//��ջ
	st->array[st->top] = data;
	st->top++;
}
//��ջ
void StackPop(Stack *st)
{
	if (st->top == 0)
	{
		return;
	}
	st->top--;
}
//ջΪ�� 0Ϊ�� 1�ǿ�
int StackEmpty(Stack *st)
{
	if (st->top == 0)//��
		return 0;
	return 1;//�ǿ�
}
//int main()
//{
//	char str[1000];
//	while (fgets(str, 1000, stdin))
//	{
//		Stack st;
//		StackInit(&st, 3);
//		int i = 0;
//		while (StackEmpty(&st) || str[i])
//		{
//
//			if (')' == str[i] && StackEmpty(&st))
//			{
//				StackPop(&st);
//			}
//			else if (')' == str[i] && StackEmpty(&st) == 0)//û��ƥ��
//			{
//				break;
//			}
//			else if ('(' == str[i])
//			{
//				StackPush(&st, '(');
//			}
//			i++;
//		}
//		if (StackEmpty(&st) == 0 && str[i] == '\0')
//			printf("Yes\n");
//		else
//			printf("No\n");
//	}
//	system("pause");
//	return 0;
//}
////////////////����
//int main()
//{
//	int N = 0, M = 0, K = 0;//N��������Ŀ�M��������ĳ���K����������
//	while (scanf("%d %d %d", &N, &M, &K) && N != 0 && M != 0 && K != 0)
//	{
//		int count = 0;
//		int tree[100][100] = { 0 };
//		while (K--)
//		{
//			int x1, y1, x2, y2;
//			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//			for (int row = x1-1; row < x2; row++)//��
//			{
//				for (int col = y1 - 1; col < y2; col++)//��
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

//////����������
//int main()
//{
//	char ch;
//	int n = 0;
//	scanf("%c", &ch);
//	while ( ch != '@')
//	{
//		scanf("%d", &n);
//		for (int i = 1; i < n; i++)//��������
//		{
//			for (int j = 1; j <= i - 1 + n; j++)
//			{
//				if (j == n - i + 1 || j == i - 1 + n)
//					printf("%c", ch);//��ӡ�ַ�
//				//����λ�ô�ӡ�ո�
//				else
//					printf(" ");
//			}
//			printf("\n");		
//		}
//		//��ӡ���һ��
//		for (int i = 0; i < 2 * n - 1; i++)
//			printf("%c", ch);
//		getchar();//���������
//		printf("\n");
//		scanf("%c", &ch);
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char ch = -128;
//	char c = ch + 1;
//	char b = ch - 1;
//	printf("%d %d\n", c, b);
//	system("pause");
//	return 0;
//}
int main()
{
	int N, K, M;
	float grade[11] = { 0 };
	float ave[105] = { 0 };
	int top = 0;
	scanf("%d %d %d", &N, &K, &M);
	while (N--)
	{
		//����ɼ��������
		float sum = 0;
		for (int i = 0; i < K; i++)
		{
			scanf("%f", &grade[i]);
			sum += grade[i];
		}
		float min = grade[0];
		float max = grade[0];
		for (int i = 1; i < K; i++)
		{
			if (min > grade[i])
				min = grade[i];
			if (max < grade[i])
				max = grade[i];
		}
		sum = sum - min - max;
		 ave[top] = sum / (K - 2);
		top++;
	}
	//ƽ��������
	for (int i = 1; i < top; i++)
	{
		for (int j = 0; j < top - i; j++)
		{
			if (ave[j] > ave[j + 1])
			{
				float tmp = ave[j];
				ave[j] = ave[j + 1];
				ave[j + 1] = tmp;
			}
		}
	}
	int i = 0;
	for (i =top-M; i<top-1; i++)
		printf("%.3f ", ave[i]);
	printf("%.3f\n", ave[i]);
	system("pause");
	return 0;
}