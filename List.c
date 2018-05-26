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
	size_t size;//�������ݸ���
}Sqlist;
void SqlistInit(Sqlist *Sq);//��ʼ��
void Sqlistpushback(Sqlist *Sq, Datatype x);//β��
void Sqlistprint(Sqlist *Sq);//��ӡ
void Sqlistpushfront(Sqlist *Sq, Datatype x);//ǰ��
void SqlistInsert(Sqlist *Sq, size_t pos, Datatype x);//����λ�ò��룬pos�ǲ��������
void Sqlistpopfront(Sqlist *Sq);//ǰɾ
void Sqlistpopback(Sqlist *Sq);//��ɾ
void Sqlistdelete(Sqlist *Sq, size_t pos);//����λ��ɾ��
void SqlistModify(Sqlist *Sq, size_t pos, Datatype x);//�޸�
void SqlistRemove(Sqlist *Sq, Datatype x);//ɾ����һ��������x
void SqlistRemoveAll(Sqlist *Sq, Datatype x);
void SqlistBubbleSort(Sqlist *Sq);//ð������
void SqlistSelectSort(Sqlist *Sq);//ѡ������
int SqlistBinarySearch1(Sqlist *Sq, Datatype x);//�۰���� [ ]����ұ�
int SqlistBinarySearch2(Sqlist *Sq, Datatype x);//�۰����[ )����ҿ�

void test1()
{
	Sqlist Sq;
	SqlistInit(&Sq);//��ʼ��
	Sqlistpushback(&Sq, 8);//β��
	Sqlistpushback(&Sq, 6);
	Sqlistpushback(&Sq,2);
	Sqlistpushfront(&Sq, 4);//ǰ��
	Sqlistpushfront(&Sq, 20);
	Sqlistpushfront(&Sq, 24);
	SqlistInsert(&Sq, 2, 15);//2�ǲ������꣬15�ǲ�������
	Sqlistpushback(&Sq, 4);
	Sqlistpushback(&Sq, 12);
	Sqlistprint(&Sq);
	printf("\n");
	Sqlistpopfront(&Sq);
	/*Sqlistpopback(&Sq);*/
	Sqlistdelete(&Sq,3);//ɾ������Ϊ4������
	SqlistInsert(&Sq, 3, 4);
	SqlistModify(&Sq,2,11);//2���޸�����
	Sqlistprint(&Sq);
	printf("\n");
    //SqlistRemove(&Sq,4);//4��Ҫɾ������
	/*Sqlistprint(&Sq);
	printf("\n");*/
    SqlistRemoveAll(&Sq, 4);
	Sqlistprint(&Sq);
	printf("\n");
	//SqlistBubbleSort(&Sq);
    SqlistSelectSort(&Sq);
	Sqlistprint(&Sq);
	printf("\n");
	printf("λ����%d\n", SqlistBinarySearch1(&Sq, 22));
	printf("λ����%d\n", SqlistBinarySearch2(&Sq, 20));
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
//�۰���ҷ�Ϊ�������
//һ����[ ]����һ����[ )
int SqlistBinarySearch1(Sqlist *Sq, Datatype x)
{
	int left = 0;
	int right = Sq->size - 1;//���������[ ]
	int mid = 0;
	while (left <= right)//������С�ڵ���
	{
		mid = left + (right - left) / 2;
		if (Sq->a[mid] > x)
		{
			right = mid - 1;//������[ ],left��rightҲ����[ ]
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
//���ֲ�����һ�����
int SqlistBinarySearch2(Sqlist *Sq, Datatype x)
{
	int left = 0;
	int right = Sq->size ;//���������[ )
	int mid = 0;
	while (left < right)//������С��
	{
		mid = left + (right - left) / 2;
		if (Sq->a[mid] > x)
		{
			right = mid;//������[ ),right���ؿ�
		}
		else if (Sq->a[mid] < x)
		{
			left = mid+1 ;//[ )left���ر�
		}
		else
			return mid;
	}
	return -1;
}

void SqlistSelectSort(Sqlist *Sq)//ѡ������
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
		//����������������������֣��ұ�����С���֣�
		//����ߺ���С���ֽ�������ô������ֱ�������ߣ�֮���ٺ��ұ߽������൱��û�н���
		{//������Ҫ����С���긳�����ֵ���꣬Ҳ�����ұߣ���ô�ٴν�������û��Ӱ��
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
			printf("����ɾ��\n");
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
		printf("û�и����ݣ��޷�ɾ��\n");
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
		Sqlistdelete(Sq, Sq->size - 1);//ֱ�ӵ���ɾ������
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
		Sqlistdelete(Sq, 0);//ֱ�ӵ���ɾ������
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
	if (Sq->size >= N)//�����ж��Ƿ�����
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
		SqlistInsert(Sq, 0, x);//ֱ�ӵ��ò��뺯��
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
	if (Sq->size >= N)//�����ж��Ƿ�����
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
		SqlistInsert(Sq, Sq->size, x);//ֱ�ӵ��ò��뺯��
	}
}
