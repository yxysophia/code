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

//base��exponent�η�
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

/////��β��ͷ��ӡ������
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
void pushFront(List**head, int data)//ͷ��
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
void pushback(List** head, int data)//β��
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
void PrintFromTailToHead(List *head)//��β��ͷ��ӡ������ //ÿ�ζ�Ҫ��������Ե�β
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
void FindKthToTail(List *head, unsigned int k) //������k�����
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
List* ReverseList(List* pHead)//��ת����
{
	if (pHead == NULL || pHead->_next == NULL)
		return pHead;
	List* pre = NULL;
	List* newHead = NULL;
	while (pHead != NULL) {
		List* pNext = pHead->_next;
		if (pNext == NULL)
			newHead=pHead;
		//���������һ���µı���������ֱ�ӷ���pHead,��ֻ�᷵��ԭ�������һ����㣬
		//��ΪpHead=pNext,��ʱ���һ������ǰ�����Ѿ��Ͽ�
		//����һ���µı���newHead��newHeadָ��phead,��������pHead->nextָ��pre����ô�ͽ���������������һ��
		pHead->_next = pre;
		pre = pHead;
		pHead = pNext;
	}
	return newHead;
	//�ڶ��ַ��� 
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
//��̬��̨��

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
//	//ָ�����飬��������5��Ԫ�أ�ֻ�ǿ���5���ռ䣬�ռ��������ַ�����ַ����û��Ϊ�ַ������ռ䣬����������ҪΪÿ���ַ������ռ�
//	for (int i = 0; i < 5; i++)
//	{
//		char* a = new char[10];  
//		//����char a[10];
//		scanf("%s", a);
//		name[i] = a;
//	}
//}



/////////////////////////��ת��������СԪ��
//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)
//			return 0;
//		int i = 0;
//		while (i < rotateArray.size() - 1)
//		{
//			���ǰһ�����ֱȺ�һ������ô��һ�����ֿ϶�����СԪ��
//			���ǰһ������С�ڵ��ں�һ�����֣���ô��С���ֿ����Ǹ����ֻ��ߺ�������
//			�������   3 4  4   5   1  
//			if (rotateArray[i] <= rotateArray[i + 1])
//				i++;
//			else   // 3  4  5  1  ֱ�ӷ���[2+1]
//				return rotateArray[i + 1];
//		}
//		  3 3 3 3 3   ѭ��������i=4,���Է���[4],Ҳ���Է���[3]�����Ƿ���[3]�ռ临�Ӷ�С
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
//						˳������
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
//					else {  //���ֲ���
//						if (rotateArray[left] <= rotateArray[mid])
//							left = mid;  //��СԪ����mid�ұߣ���Ҫ��left=mid,������mid+1,��Ϊmid��������СԪ��
//						else
//							 ��  3 4 5 1  2  ����left=2,right=4��mid=3,[mid]����СԪ�أ�������Ҫ��right=mid,������right=mid+1
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