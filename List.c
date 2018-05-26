#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define N 10
typedef int Datatype;
typedef struct sq
{
	Datatype a[N];
	size_t size;//所存数据个数
}Sqlist;
void SqlistInit(Sqlist *Sq);//初始化
void Sqlistpushback(Sqlist *Sq, Datatype x);//尾插
void Sqlistprint(Sqlist *Sq);//打印
void Sqlistpushfront(Sqlist *Sq, Datatype x);//前插
void SqlistInsert(Sqlist *Sq, size_t pos, Datatype x);//任意位置插入，pos是插入的坐标
void Sqlistpopfront(Sqlist *Sq);//前删
void Sqlistpopback(Sqlist *Sq);//后删
void Sqlistdelete(Sqlist *Sq, size_t pos);//任意位置删除
void SqlistModify(Sqlist *Sq, size_t pos, Datatype x);//修改
void SqlistRemove(Sqlist *Sq, Datatype x);//删除第一个遇到的x
void SqlistRemoveAll(Sqlist *Sq, Datatype x);
void SqlistBubbleSort(Sqlist *Sq);//冒泡排序
void SqlistSelectSort(Sqlist *Sq);//选择排序
int SqlistBinarySearch1(Sqlist *Sq, Datatype x);//折半查找 [ ]左闭右闭
int SqlistBinarySearch2(Sqlist *Sq, Datatype x);//折半查找[ )左闭右开

void test1()
{
	Sqlist Sq;
	SqlistInit(&Sq);//初始化
	Sqlistpushback(&Sq, 8);//尾插
	Sqlistpushback(&Sq, 6);
	Sqlistpushback(&Sq,2);
	Sqlistpushfront(&Sq, 4);//前插
	Sqlistpushfront(&Sq, 20);
	Sqlistpushfront(&Sq, 24);
	SqlistInsert(&Sq, 2, 15);//2是插入坐标，15是插入数据
	Sqlistpushback(&Sq, 4);
	Sqlistpushback(&Sq, 12);
	Sqlistprint(&Sq);
	printf("\n");
	Sqlistpopfront(&Sq);
	/*Sqlistpopback(&Sq);*/
	Sqlistdelete(&Sq,3);//删除坐标为4的数据
	SqlistInsert(&Sq, 3, 4);
	SqlistModify(&Sq,2,11);//2是修改坐标
	Sqlistprint(&Sq);
	printf("\n");
    //SqlistRemove(&Sq,4);//4是要删除数字
	/*Sqlistprint(&Sq);
	printf("\n");*/
    SqlistRemoveAll(&Sq, 4);
	Sqlistprint(&Sq);
	printf("\n");
	//SqlistBubbleSort(&Sq);
    SqlistSelectSort(&Sq);
	Sqlistprint(&Sq);
	printf("\n");
	printf("位置是%d\n", SqlistBinarySearch1(&Sq, 22));
	printf("位置是%d\n", SqlistBinarySearch2(&Sq, 20));
}

int Sqlistfind(Sqlist *Sq, Datatype x)
{
	int i = 0;
	for (i = 0; i < Sq->size; i++)
	{
		if (Sq->a[i] == x)
		{
			return i;
		}
	}
	if (i == Sq->size)
		return -1;
}
void Swap(Datatype *l, Datatype *r)
{
	Datatype tmp = *r;
	*r = *l;
	*l= tmp;
}
int main()
{
	test1();
	system("pause");
	return 0;
}
//折半查找分为两种情况
//一个是[ ]，另一个是[ )
int SqlistBinarySearch1(Sqlist *Sq, Datatype x)
{
	int left = 0;
	int right = Sq->size - 1;//此种情况是[ ]
	int mid = 0;
	while (left <= right)//必须是小于等于
	{
		mid = left + (right - left) / 2;
		if (Sq->a[mid] > x)
		{
			right = mid - 1;//由于是[ ],left和right也遵守[ ]
		}
		else if (Sq->a[mid] < x)
		{
			left = mid + 1;
		}
		else
			return mid;
	}
	return -1;
}
//二分查找另一种情况
int SqlistBinarySearch2(Sqlist *Sq, Datatype x)
{
	int left = 0;
	int right = Sq->size ;//此种情况是[ )
	int mid = 0;
	while (left < right)//必须是小于
	{
		mid = left + (right - left) / 2;
		if (Sq->a[mid] > x)
		{
			right = mid;//由于是[ ),right遵守开
		}
		else if (Sq->a[mid] < x)
		{
			left = mid+1 ;//[ )left遵守闭
		}
		else
			return mid;
	}
	return -1;
}

void SqlistSelectSort(Sqlist *Sq)//选择排序
{
    int  min = 0;
    int  max = 0;
	int left = 0;
	int right = Sq->size-1;
	int i = 0;
	int j = 0;
	while (left < right)
	{
		max = min = left;
		for (j = left + 1; j <= right; j++)
		{
			if (Sq->a[min]> Sq->a[j])
			{
				min=j;
			}
			if (Sq->a[max] < Sq->a[j])
			{
				max=j;
			}
		}
		Swap(&Sq->a[left], &Sq->a[min]);
		if ((min == right)&&(max == left))
		//特殊情况，当左边是最大数字，右边是最小数字，
		//当左边和最小数字交换后，那么最大数字被换到左边，之后再和右边交换，相当于没有交换
		{//所以需要把最小坐标赋给最大值坐标，也就是右边，那么再次交换，就没有影响
			max = min;
		}
		Swap(&Sq->a[right],&Sq->a[max]);
		left++;
		right--;
	}
}
void SqlistBubbleSort(Sqlist *Sq)
{
	int i = 0;
	int j = 0;
	for (i = 1; i < Sq->size; i++)
	{
		for (j = 0; j < Sq->size - 1; j++)
		{
			if (Sq->a[j] > Sq->a[j + 1])
			{
				Swap(&Sq->a[j], &Sq->a[j + 1]);
			}
		}
	}
}
void SqlistRemoveAll(Sqlist *Sq, Datatype x)
{
	int s1 = 0;
	int s2 = 0;
	size_t count = Sq->size;
	while (s1 < (int)count)
	{
		if (Sq->a[s1] == x)
		{
			s1++;
			Sq->size--;
		}
		else
		{
			Sq->a[s2] = Sq->a[s1];
			s1++;
			s2++;
		}
	}
}
void SqlistModify(Sqlist *Sq, size_t pos,Datatype x)
{
	assert(Sq&&pos < Sq->size);
	Sq->a[pos] = x;
}
void Sqlistdelete(Sqlist *Sq, size_t pos)
{
	assert(Sq);
	if (Sq->size <= 0)
	{
		printf("Sq is empty\n");
	}
	else
	{
		if (pos < 0 || pos > Sq->size - 1)
		{
			printf("不能删除\n");
		}
		else
		{
			while (pos < Sq->size - 1)
			{
				Sq->a[pos] = Sq->a[pos + 1];
				pos++;
			}
			Sq->size--;
		}
	}
}
void SqlistRemove(Sqlist *Sq, Datatype x)
{
	int i = Sqlistfind(Sq, x);
	if (i < 0)
	{
		printf("没有该数据，无法删除\n");
	}
	else
	{
		Sqlistdelete(Sq, i);
	}
}
void Sqlistpopback(Sqlist *Sq) 
{
	if (Sq->size <= 0)
	{
		printf("Sq is empty\n");
	}
	/*else
	{
		Sq->a[Sq->size-1] =0;
	}
	Sq->size--;*/
	else
	{
		Sqlistdelete(Sq, Sq->size - 1);//直接调动删除函数
	}
}
void Sqlistpopfront(Sqlist *Sq)
{
	if (Sq->size <=0)
	{
		printf("Sq is empty\n");
	}
	/*else
	{
		int start = 0;
		while (start <Sq->size -1 )
		{
			Sq->a[start] = Sq->a[start + 1];
			start++;
		}
		Sq->size--;
	}*/
	else
	{
		Sqlistdelete(Sq, 0);//直接调用删除函数
	}
}
void SqlistInsert(Sqlist *Sq, size_t pos, Datatype x)
{
	assert(Sq);
	int end = Sq->size;
	while (end > pos)
	{
		Sq->a[end] = Sq->a[end - 1];
		end--;
	}
	Sq->a[end] = x;
	Sq->size++;
}

void Sqlistpushfront(Sqlist *Sq, Datatype x)
{
	int end = Sq->size;
	if (Sq->size >= N)//插入判断是否已满
	{
		printf("Sq is full\n");
	}
	//else
	//{
	//	while (end > 0)
	//	{
	//		Sq->a[end] = Sq->a[end - 1];
	//		end--;
	//	}
	//	Sq->a[end] = x;
	//	Sq->size++;
	//}
	else
	{
		SqlistInsert(Sq, 0, x);//直接调用插入函数
	}
}
void Sqlistprint(Sqlist *Sq)
{
	int i = 0;
	for (i = 0; i < Sq->size; i++)
	{
		printf("%d ", Sq->a[i]);
	}
}

void SqlistInit(Sqlist *Sq)
{
	memset(Sq->a, 0, sizeof(Datatype)*N);
	Sq->size = 0;
}

void Sqlistpushback(Sqlist *Sq, Datatype x)
{
	if (Sq->size >= N)//插入判断是否已满
	{
		printf("Sq is full\n");
	}
	/*else
	{
		Sq->a[Sq->size] = x;
		Sq->size++;
	}*/
	else
	{
		SqlistInsert(Sq, Sq->size, x);//直接调用插入函数
	}
}
