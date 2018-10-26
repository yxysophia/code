#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<search.h>

int float_cmp(const void *e1, const void *e2)
{
	float *p1 = (float *)e1;
	float *p2 = (float *)e2;
	return (*p1 > *p2 ? 1 : (*p1 <*p2 ? -1 : 0));//三目操作符
}

void swap(void *p1, void *p2, int size)
{
	char *q1 = (char *)p1;
	char *q2 = (char *)p2;
	while (size--)
	{
		*q1 ^= *q2;
		*q2 ^= *q1;
		*q1 ^= *q2;
		q1++;
		q2++;
	}
}

void bubble(void *base, int count, int size, int(*cmp)(void *e1, void *e2))
{
	int i = 0;
	int j = 0;
	char *p = (char *)base;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (cmp(p + j*size, p + (j + 1)*size) > 0)//回调函数直接调，p + j*size为a[j],p + (j + 1)*size为a[j+1]
			{
				swap(p + j*size, p + (j + 1)*size,size);
			}
		}
	}
}

int int_cmp(const void *e1, const void *e2)
{
	int *p1 = (int *)e1;
	int *p2 = (int *)e2;
	return (*p1 > *p2 ? 1 : (*p1 <*p2 ? -1 : 0));
}
int main()
{
	//int a[] = { 2,4,51,1,10,6 };
	float a[] = { 1.2,4.3,6.5,7.8 };
	int i = 0;
	int count = sizeof(a) / sizeof(a[0]);
	bubble(a, count, sizeof(float), float_cmp);//int_cmp为回调函数
	for (i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;

}