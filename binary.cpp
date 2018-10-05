#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int NumberOf1(int n)
//{
//	int count = 0;
//	
//	int i = 0;
//	for (i = 0; i<32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//			count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count=NumberOf1(n);
//	printf("%d\n", count);
//	system("pause");
//	return 0;
//}

//base的exponent次方
//int main()
//{
//	double base = -2;
//	int exponent = -3;
//	int flag = 1;
//	
//	if (exponent<0)
//	{
//		exponent = -exponent;
//		base = 1.0 / base;
//	}
//	double ret = 1.0;
//	int i = 0;
//	for (i = 0; i<exponent; i++)
//	{
//		ret = ret*base;
//	}
//	
//	printf("%lf\n", ret);
//	system("pause");
//	return 0;
//
//}

/////从尾到头打印单链表
typedef struct List
{
	struct List *_next;
	int _data;
}List;
List* BuyNode(int data)
{
	List* newnode = (List*)malloc(sizeof(List));
	newnode->_next = NULL;
	newnode->_data = data;
	return newnode;
}
void pushFront(List**head, int data)//头插
{
	List *newnode = BuyNode(data);
	if (*head == NULL)
	{
		*head = newnode;
		return;
	}
	newnode->_next = *head;
	*head = newnode;
}
void pushback(List** head, int data)//尾插
{
	List *newnode = BuyNode(data);
	if (*head == NULL)
	{
		*head = newnode;
		return;
	}
	List* cur = *head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	cur->_next = newnode;
	return;
}
void PrintFromTailToHead(List *head)//从尾到头打印单链表 //每次都要遍历到相对的尾
{
	if (head == NULL)
		return;
	List*tail = NULL;
	List *cur = head;
	while (head != tail)
	{
		cur = head;
		while (cur->_next != tail)
		{
			cur = cur->_next;
		}
		printf("%d ", cur->_data);
		tail = cur;
	}
}
void FindKthToTail(List *head, unsigned int k) //倒数第k个结点
{
	if (head == NULL)
		return ;
	List *fast = head;
	List *slow = head;
	while (k--)
	{
		if (fast == NULL)
			return ;
		fast = fast->_next;
	}
	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	printf("%d\n", slow->_data);
}
List* ReverseList(List* pHead)//反转链表
{
	if (pHead == NULL || pHead->_next == NULL)
		return pHead;
	List* pre = NULL;
	List* newHead = NULL;
	while (pHead != NULL) {
		List* pNext = pHead->_next;
		if (pNext == NULL)
			newHead=pHead;
		//如果不定义一个新的变量，而是直接返回pHead,将只会返回原链表最后一个结点，
		//因为pHead=pNext,这时最后一个结点和前面结点已经断开
		//定义一个新的变量newHead后，newHead指向phead,而接下来pHead->next指向pre，那么就将整个链表链接在一起
		pHead->_next = pre;
		pre = pHead;
		pHead = pNext;
	}
	return newHead;
	//第二种方法 
	//if (phead == NULL)
	//	return NULL;
	//if (phead->_next == NULL)
	//	return phead;
	////List* newlist = (List*)malloc(sizeof(List));
	//List* newlist = phead;;
	//newlist->_data = phead->_data;
	//newlist->_next = NULL;
	//List* cur = phead->_next;
	//List*newnode = newlist;
	//while (cur)
	//{
	//	//List*newnode = (List*)malloc(sizeof(List));
	//	newnode->_data = cur->_data;
	//	newnode->_next = newlist;
	//	newlist = newnode;
	//	cur = cur->_next;
	//}
	//return newlist;

}
//int main()
//{
//	List *l=NULL;
//	List *new = NULL;
//	pushback(&l, 1);
//	pushback(&l, 2);	
//	pushback(&l, 3);
//	//pushFront(&l, 4);
//	//pushFront(&l, 5);
//	//pushFront(&l, 6);
//	//PrintFromTailToHead(l);
//	//FindKthToTail(l, 2);
//	//PrintFromTailToHead(l);
//	new=ReverseList(l);
//
//	system("pause");
//	return 0;
//}
//变态跳台阶

//int jumpFloor1(int n)
//{
//	int result = 0;
//	
//	if (n == 0 || n == 1)
//	{
//		return 1 ;
//	}
//	int num = n;
//	while (num--)
//	{
//		result = result+ jumpFloor1(n - 1);
//		n--;
//		
//	}
//	return result;
//
//}
//int jumpFloor2(int n)
//{
//	int ret = 1;
//	if (n == 0 || n == 1)
//		return ret;
//	for (int i = 2; i <= n; i++)
//	{
//		ret = ret * 2;
//	}
//	return ret;
//}
//int main()
//{
//	int n = 4;
//	/*scanf("%d", &n);
//	*/
//	int ret=jumpFloor2(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//		
//}


//int main()
//{
//	char* name[5];
//	//指针数组，数组里有5个元素，只是开了5个空间，空间里存的是字符串地址，并没有为字符串开空间，所以在下面要为每个字符串开空间
//	for (int i = 0; i < 5; i++)
//	{
//		char* a = new char[10];  
//		//或者char a[10];
//		scanf("%s", a);
//		name[i] = a;
//	}
//}



/////////////////////////旋转数组里最小元素
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)
//			return 0;
//		int i = 0;
//		while (i < rotateArray.size() - 1)
//		{
//			如果前一个数字比后一个大，那么后一个数字肯定是最小元素
//			如果前一个数字小于等于后一个数字，那么最小数字可能是该数字或者后面数字
//			等于情况   3 4  4   5   1  
//			if (rotateArray[i] <= rotateArray[i + 1])
//				i++;
//			else   // 3  4  5  1  直接返回[2+1]
//				return rotateArray[i + 1];
//		}
//		  3 3 3 3 3   循环出来后，i=4,可以返回[4],也可以返回[3]，但是返回[3]空间复杂度小
//		return rotateArray[i - 1];
//	}
//};
//	class Solution {
//	public:
//		class Solution {
//		public:
//			int minNumberInRotateArray(vector<int> rotateArray) {
//				int len = rotateArray.size();
//				if (len == 0)
//					return 0;
//				int left = 0;
//				int right = len - 1;
//				int mid = 0;
//
//				while (rotateArray[left] >= rotateArray[right])
//				{
//					mid = left + (right - left) / 2;
//					if (right - left == 1)
//					{
//						mid = right;
//						break;
//					}
//					if (rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right])
//					{
//						顺序排序
//						int i = left;
//						while (i<right)
//						{
//							if (rotateArray[i] <= rotateArray[i + 1])
//								i++;
//							else
//								return rotateArray[i + 1];
//						}
//						return  rotateArray[i];
//					}
//					else {  //二分查找
//						if (rotateArray[left] <= rotateArray[mid])
//							left = mid;  //最小元素在mid右边，需要是left=mid,不能是mid+1,因为mid可能是最小元素
//						else
//							 如  3 4 5 1  2  ，当left=2,right=4，mid=3,[mid]是最小元素，所以需要是right=mid,而不是right=mid+1
//							right = mid;
//					}
//				}
//				return rotateArray[mid];
//			}
//		};
//	};
//int main()
//{
//	int a[6] = { 1,2,3,2,4,5,2, };
//	int result = a[0];
//	int count = 1;
//	for (int i = 1; i < 5; i++)
//	{
//		if (count == 0)
//		{
//			result = a[i];
//			count = 1;
//		}
//		else 
//		{
//			if (a[i] == result)
//			{
//				count++;
//			}
//			else
//				count--;
//		}
//	}
//}