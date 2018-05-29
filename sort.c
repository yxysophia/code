#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include"Stack.h"
void print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int *a1,int *a2)
{
	int c = *a1;
	*a1 = *a2;
	*a2 = c;
}
////////////////////////��������
//˼·��endָ�������������λ�ã��������ݱ�[end]�󣬾Ͳ���[end+1],��[end]С��end--��ֱ����[end]�����end<0
void InsertSort(int *a, int n)
{
	assert(a);
	int end = 0;
     //ע��i<n-1
	for (int i = 0; i < n-1; i++)
	{
		end = i;
		int tmp = a[end+1];//��Ҫ���������ݽ��б���
		while (end >= 0 && a[end] > tmp)
		{
			//������������ں�ǰ�������������ݽ��бȽ���С��
			//������end=-1,��ôҲ���Թ�Ϊ[end+1]=[-1+1]=tmp;
			a[end + 1] = a[end];//�������������ƶ�
			end--;
		}
		a[end + 1] = tmp;
	}
}
/////////////////ϣ������
//�����������������������ֱ�Ӳ�������Ч�ʸߣ�
//1.Ԥ����ʹ���ݽӽ����򣬴�����ݾ�������ƶ���С�����ݾ�����ǰ�ƶ�
//2.��gap=1ʱ����Ϊֱ�Ӳ�������
void ShellSort(int *a, int n)
{
	assert(a);
	int end = 0;     
	int gap = n;//���
	while (gap > 1)//�������0��������ѭ��
	{
		gap = gap / 3 + 1;//������Сgap,��1ʹ���һ��Ϊֱ�Ӳ�������
		for (int i = 0; i < n - gap; i++)//�����i+=gap,��Ҫ��һ����ѭ����ѭ��gap��
		{
			end = i;
			int tmp = a[end + gap];//Ҫ�ŵ�����
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];//�����������ƶ�
				end -= gap;
			}
			a[end + gap] = tmp;//endС��0����[end]<tmp��tmp��[end+gap]����
		}
	}
}
//////////////////ѡ������
//˼·Ϊ���ҵ�һ�������ڵ����ֵ����Сֵ�������ֵ���������ұߣ���Сֵ����������ߣ�Ȼ��������С���ظ���������,ֱ��begin=end,������� 
void SelectSort(int *a, int n)
{
	assert(a);
	int begin = 0, end = n-1, max = 0, min = 0;
	while (begin < end)
	{
		min = max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[min] > a[i])
				min = i;
		
			if (a[max] < a[i])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
			max = min;
		//�����������begin��max�غ�
		//[min]��[begin]������begin�������Сֵ����[max]Ҳ�ͱ�Ϊ��Сֵ�����Ե�[begin]��[min]������max=min
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}	
}
//ð������
void BubbleSort(int *a, int n)
{
	assert(a);
	for (int i = 1; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//������򣬽��������ѭ��
			break;
	}
}
void AdjustDown(int *a, int root,int n)//���µ���
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			child++;
		if (child < n && a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//����
void HeapSort(int *a, int n)
{
	assert(a);
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);//����һ��Ԫ�����µ���Ϊ���Ԫ��
	}
	int size = n;
	for (i = 0; i < n; i++)
	{
		Swap(&a[0], &a[size - 1]);//�����Ԫ�غ��������һ��Ԫ�ؽ���
		size--;//������size-1��Ԫ��
		AdjustDown(a, 0, size);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//���ţ�һ������key�����ź�����λ�ã�
//��key��߶���keyС��key�ұ߶���key��
//ע�⣺����end����right,���Ե�[end]<=
//keyʱend--, ���û�� = ��������ѭ������Ϊ[end] == key, endû--����һֱ�����λ�ã�[begin] <= keyʱbegin++����û�� = Ҳ�������ѭ����
//��begin����endʱ����[behin]��[right]��������ʱ[begin]������ֱ�key��
//begin==end:end��begin����������begin���ߣ�Ȼ��end==begin,��ʱ[begin]��key��
int GetMidIndex(int *a, int left, int right)//����ȡ��,�ҵ���������λ��
{
	assert(a);
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])//�����С
	{
		if (a[mid] < a[right])
			return mid;//mid����λ��
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}
int partsort3(int *a, int left, int right)//ǰ��ָ��
{
	assert(a);
	int prev = left - 1;
	int cur = left;
	int key = a[right];
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;	
	}
	Swap(&a[++prev], &a[right]);
	return prev;
}
int partsort2(int *a, int left, int right)//�ڿ�
{
	assert(a);
	int begin = left;
	int end = right;
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			begin++;
		a[end] = a[begin];//[end]�ǿ�
		while (begin < end && a[end] >= key)
			end--;
	   a[begin]=a[end];//[begin]�ǿ�
	}
	a[begin] = key;
	return begin;
}
int partsort1(int *a, int left, int right)//����ָ�뼴hoare�汾
{
	assert(a);
	int begin = left;
	int end = right;
	int mid = GetMidIndex(a, left, right);
	//�ҵ���λ������[right]����������Ϊ��ȫ��������ʱ�临�Ӷȣ�N*logN
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (begin < end)
	{
		//begin�Ҵ�
		while (begin < end && a[begin] <= key)
			begin++;
		//end��С
		while (begin < end && a[end] >= key)
			end--;
		if (begin < end)
			Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[right]);//���ܺ�key��������Ϊkey�Ǿֲ�����
	return begin;
}
void QuickSortNonR(int *a, int left, int right)//���ŷǵݹ�
{
	assert(a);
	if (left >= right)
		return;
	Stack st;
	StackInit(&st);
	int topl;//ջ������
	int topr;//ջ������
	int div = 0;
	//��ջ˳���������
	StackPush(&st, left);
	StackPush(&st, right);
	while (StackEmpty(&st))
	{
		//��ջ���Һ���
		topr = StackTop(&st);
		StackPop(&st);
		topl = StackTop(&st);
		StackPop(&st);
		div = partsort1(a, topl, topr);
		// topr  div-1 div  div+1 topr
		//div�������������ջ���ұ��������ջ������ջ�Ƚ�����������ұ����������������
		if (topl < div - 1)
		{
			StackPush(&st, topl);
			StackPush(&st, div - 1);
		}
		if (div + 1 < topr)
		{
			StackPush(&st, div + 1);
			StackPush(&st, topr);
		}
	}
}
void QuickSort(int *a, int left, int right)
{
	//�ݹ�˼�룺�����ںܶ�����
	assert(a);
	if (left >= right)//ע�⣺�����>������ջ���
		return;
	if (right - left + 1 < 20)//С�����Ż��������ݸ�������������Ҫ��1��С��20ʱ��ֱ�Ӳ�������
	{
		InsertSort(a + left, right - left + 1);
		return;
	}
	int div = partsort1(a, left, right);
	//int div = partsort2(a, left, right);
	//int div = partsort3(a, left, right);
	printf("div:%d\n", div);
	//left div-1
	QuickSort(a, left, div - 1);
	//div+1  right
	QuickSort(a, div + 1, right);
}
////////////////////////////�鲢�����������򣺿����ڴ���������   
//���������Ԫ�����зֳ�����������ȵ������У���ÿһ�������н�������Ȼ�����Ǻϲ���һ������
void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	if (right - left + 1 < 20)
	{
		InsertSort(a + left, right - left + 1);//С�����Ż��������ݸ�������������Ҫ��1��С��20ʱ��ֱ�Ӳ�������
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);//����߻���Ϊ����
	_MergeSort(a, mid + 1, right, tmp);//���ұ߻�������
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	// begin1--end1����������   begin2--end2����������
	//��������������ϲ�Ϊһ����������
	while (begin1 <= end1 && begin2 <= end2)
	{
		//��С�����ݷ���tmp��
		if (a[begin1] <= a[begin2])//���ںű�֤�鲢���ȶ���
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}
	if (begin1 > end1)//˵��begin2-end2��������
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
	else //˵��begin1 - end1��������
	{
		while (begin1 <= end1)
			tmp[index++] = a[begin1++];
	}
	index = left;
	while (index <= right)//����tmpֻ�Ǹ���ʱ���飬��Ҫ�������������·ŵ�����a��
	{
		a[index] = tmp[index];
		index++;
	}
}
void MergeSort(int *a, int n)
{
	assert(a); 
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);//tmp����ʱ����
	free(tmp);
	tmp = NULL;
}
//////////////////////////��������:�ǱȽ�����
//��¼�����������Сֵλ�ó��ִ���
//�������������λ�û�������
void CountSort(int *a, int n)
{
	assert(a);
	int min = a[0];
	int max = a[0];
	int i = 0;
	//�����е����ֵ����Сֵȷ�����鷶Χ
	for (i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i]) 
			max = a[i];
	}
	//��Χ
	int range = max - min + 1;
	int *counts = (int *)malloc(sizeof(int)*range);
	memset(counts, 0, sizeof(int)*range);//��counts[]��ʼ��Ϊ0��ÿ�����ݳ�ʼ������0��
	//��¼Ԫ�س��ֵĴ���
	for (i = 0; i < n; i++)
	{
		counts[a[i] - min]++;//��Сֵ��counts�����һ������������ݽ���Сֵ�����λ�ã���λ�ü�¼���ݳ��ִ���
	}
	int index = 0;
	for (i = 0; i < range; i++)
	{
		while (counts[i])//��Ϊ0��������
		{
			a[index] = min + i;//�����ݷ���a���飺��Сֵ+���λ��
			counts[i]--;
			index++;
		}
	}
}
int main()
{
	int a[20] = { 0 };
	srand((unsigned int)time(0));
	for (int i = 0; i < 20; i++)
	{
		a[i] = rand() % 100;
	}
	int size = sizeof(a) / sizeof(a[0]);
	print(a, size);
	//InsertSort(a, size);
	//ShellSort(a,size);
	//SelectSort(a, size);
	//BubbleSort(a, size);
	//HeapSort(a, size);
	//QuickSortNonR(a, 0, size - 1);
	//QuickSort(a, 0,size-1);
	//MergeSort(a, size);
	CountSort(a, size);
	print(a, size);
	system("pause");
	return 0;

}
//�������ܵıȽϣ�
//ѡ������Ͳ������򣺲�������Ϻ�
//����ʱ�临�Ӷȶ�Ϊ0(n^2),����������Ĳ�������ʱ�临�Ӷ�Ϊ0(n)
//ֱ�Ӳ���������������棬������Ų�����ݣ�ѡ��������Ȼ��0(n^2);
//ð�����򡢲�������ѡ�����򣺲�������Ϻ�
//�� 1 2 3  5  4
//����������5�ο������򣬶�ð����4��5�����������Ҫ���ж��Ƿ���������Ž������򣬼�7��
//�������ԣ��������ݿ����������ڶ���

//�����ȶ��ԵıȽϣ����ȶ���ָ������ͬ��ֵ����������λ�ò��䣩
//���������ȶ�����ȾͲ��ں��棩
//ϣ�����򣺲��ȶ�����gap,��Ծ�����򣬿��ܻ�Ӱ�����λ�ã�
//ѡ�����򣺲��ȶ���3 5  9*  9 2 7--->2  5 7 9 3 9*)
//ð�������ȶ�������������ȣ���������
//���ţ����ȶ���5  4  5*����һ��5�����һ��5*���������λ�÷����仯��
//�������򣺲��ȶ�( 6  7 1 5* 5--->1  5  6 5* 7)
//�鲢�����ȶ�����Ⱦͽ�ǰһ�����ݷ���tmp���飩
