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
////////////////////////插入排序
//思路：end指向有序区间结束位置，插入数据比[end]大，就插在[end+1],比[end]小，end--，直至比[end]大或者end<0
void InsertSort(int *a, int n)
{
	assert(a);
	int end = 0;
     //注意i<n-1
	for (int i = 0; i < n-1; i++)
	{
		end = i;
		int tmp = a[end+1];//需要将插入数据进行保存
		while (end >= 0 && a[end] > tmp)
		{
			//如果插入数据在和前面有序区间数据进行比较最小，
			//将会有end=-1,那么也可以归为[end+1]=[-1+1]=tmp;
			a[end + 1] = a[end];//将大的数据向后移动
			end--;
		}
		a[end + 1] = tmp;
	}
}
/////////////////希尔排序
//对于数据量大及数据逆序相对直接插入排序效率高：
//1.预排序：使数据接近有序，大的数据尽量向后移动，小的数据尽量向前移动
//2.当gap=1时，即为直接插入排序
void ShellSort(int *a, int n)
{
	assert(a);
	int end = 0;     
	int gap = n;//间距
	while (gap > 1)//如果大于0，将是死循环
	{
		gap = gap / 3 + 1;//不断缩小gap,加1使最后一次为直接插入排序
		for (int i = 0; i < n - gap; i++)//如果是i+=gap,需要有一个外循环，循环gap次
		{
			end = i;
			int tmp = a[end + gap];//要排的数据
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];//大的数据向后移动
				end -= gap;
			}
			a[end + gap] = tmp;//end小于0或者[end]<tmp，tmp在[end+gap]插入
		}
	}
}
//////////////////选择排序
//思路为：找到一段区间内的最大值和最小值，将最大值放在区间右边，最小值放在区间左边，然后区间缩小，重复上述步骤,直至begin=end,排序结束 
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
		//特殊情况，当begin和max重合
		//[min]和[begin]交换后，begin存的是最小值，那[max]也就变为最小值，所以当[begin]和[min]交换后，max=min
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}	
}
//冒泡排序
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
		if (flag == 0)//如果有序，将不会进入循环
			break;
	}
}
void AdjustDown(int *a, int root,int n)//向下调整
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
//堆排
void HeapSort(int *a, int n)
{
	assert(a);
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);//将第一个元素向下调整为最大元素
	}
	int size = n;
	for (i = 0; i < n; i++)
	{
		Swap(&a[0], &a[size - 1]);//将最大元素和数组最后一个元素交换
		size--;//再排序size-1个元素
		AdjustDown(a, 0, size);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
//快排：一趟排序将key放在排好序后的位置，
//即key左边都比key小，key右边都比key大
//注意：由于end等于right,所以当[end]<=
//key时end--, 如果没有 = 将进入死循环，因为[end] == key, end没--，将一直在这个位置；[begin] <= key时begin++，若没有 = 也会进入死循环。
//当begin等于end时，将[behin]和[right]交换，此时[begin]存的数字比key大
//begin==end:end和begin相遇：由于begin先走，然后end==begin,此时[begin]比key大；
int GetMidIndex(int *a, int left, int right)//三数取中,找到三个数中位数
{
	assert(a);
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])//左比中小
	{
		if (a[mid] < a[right])
			return mid;//mid是中位数
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
int partsort3(int *a, int left, int right)//前后指针
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
int partsort2(int *a, int left, int right)//挖坑
{
	assert(a);
	int begin = left;
	int end = right;
	int key = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			begin++;
		a[end] = a[begin];//[end]是坑
		while (begin < end && a[end] >= key)
			end--;
	   a[begin]=a[end];//[begin]是坑
	}
	a[begin] = key;
	return begin;
}
int partsort1(int *a, int left, int right)//左右指针即hoare版本
{
	assert(a);
	int begin = left;
	int end = right;
	int mid = GetMidIndex(a, left, right);
	//找到中位数，和[right]交换，尽量为完全二叉树，时间复杂度：N*logN
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (begin < end)
	{
		//begin找大
		while (begin < end && a[begin] <= key)
			begin++;
		//end找小
		while (begin < end && a[end] >= key)
			end--;
		if (begin < end)
			Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[right]);//不能和key交换，因为key是局部变量
	return begin;
}
void QuickSortNonR(int *a, int left, int right)//快排非递归
{
	assert(a);
	if (left >= right)
		return;
	Stack st;
	StackInit(&st);
	int topl;//栈顶的左
	int topr;//栈顶的右
	int div = 0;
	//进栈顺序：先左后右
	StackPush(&st, left);
	StackPush(&st, right);
	while (StackEmpty(&st))
	{
		//出栈先右后左
		topr = StackTop(&st);
		StackPop(&st);
		topl = StackTop(&st);
		StackPop(&st);
		div = partsort1(a, topl, topr);
		// topr  div-1 div  div+1 topr
		//div的左边区间先入栈，右边区间后入栈，但是栈先进后出，先排右边区间再排左边区间
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
	//递归思想：适用于很多数据
	assert(a);
	if (left >= right)//注意：必须加>，否则栈溢出
		return;
	if (right - left + 1 < 20)//小区间优化：当数据个数（闭区间需要加1）小于20时，直接插入排序
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
////////////////////////////归并：属于外排序：可以在磁盘上排序   
//将待排序的元素序列分成两个长度相等的子序列，对每一个子序列进行排序，然后将他们合并成一个序列
void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	if (right - left + 1 < 20)
	{
		InsertSort(a + left, right - left + 1);//小区间优化：当数据个数（闭区间需要加1）小于20时，直接插入排序
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);//将左边划分为有序
	_MergeSort(a, mid + 1, right, tmp);//将右边划分语序
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	// begin1--end1是有序区间   begin2--end2是有序区间
	//将两段有序区间合并为一段有序区间
	while (begin1 <= end1 && begin2 <= end2)
	{
		//把小的数据放在tmp中
		if (a[begin1] <= a[begin2])//等于号保证归并是稳定的
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
	if (begin1 > end1)//说明begin2-end2还有数据
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
	else //说明begin1 - end1还有数据
	{
		while (begin1 <= end1)
			tmp[index++] = a[begin1++];
	}
	index = left;
	while (index <= right)//由于tmp只是个临时数组，需要将有序数据重新放到数组a中
	{
		a[index] = tmp[index];
		index++;
	}
}
void MergeSort(int *a, int n)
{
	assert(a); 
	int *tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);//tmp是临时数组
	free(tmp);
	tmp = NULL;
}
//////////////////////////计数排序:非比较排序
//记录数据在相对最小值位置出现次数
//根据数据在相对位置回收数据
void CountSort(int *a, int n)
{
	assert(a);
	int min = a[0];
	int max = a[0];
	int i = 0;
	//找序列的最大值和最小值确定数组范围
	for (i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
		if (max < a[i]) 
			max = a[i];
	}
	//范围
	int range = max - min + 1;
	int *counts = (int *)malloc(sizeof(int)*range);
	memset(counts, 0, sizeof(int)*range);//将counts[]初始化为0，每个数据初始化出现0次
	//记录元素出现的次数
	for (i = 0; i < n; i++)
	{
		counts[a[i] - min]++;//最小值在counts数组第一个，算得是数据较最小值的相对位置，该位置记录数据出现次数
	}
	int index = 0;
	for (i = 0; i < range; i++)
	{
		while (counts[i])//不为0即与数据
		{
			a[index] = min + i;//将数据放入a数组：最小值+相对位置
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
//排序性能的比较：
//选择排序和插入排序：插入排序较好
//两者时间复杂度都为0(n^2),但对于有序的插入排序时间复杂度为0(n)
//直接插入在有序区间后面，不用再挪动数据，选择排序依然是0(n^2);
//冒泡排序、插入排序、选择排序：插入排序较好
//如 1 2 3  5  4
//插入排序是5次可以有序，而冒泡在4和5交换有序后还需要再判断是否有序，语序才结束排序，即7次
//经过测试，大量数据快排性能优于堆排

//排序稳定性的比较：（稳定性指两个相同的值在排序后相对位置不变）
//插入排序：稳定（相等就插在后面）
//希尔排序：不稳定（有gap,跳跃着排序，可能回影响相对位置）
//选择排序：不稳定（3 5  9*  9 2 7--->2  5 7 9 3 9*)
//冒泡排序：稳定（两个数据相等，不交换）
//堆排：不稳定（5  4  5*，第一个5和最后一个5*交换，相对位置发生变化）
//快速排序：不稳定( 6  7 1 5* 5--->1  5  6 5* 7)
//归并排序：稳定（相等就将前一个数据放入tmp数组）
