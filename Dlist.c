//��ͷ���˫��ѭ������
#include"Dlist.h"
#include<assert.h>
void test1()
{
	DlistNode *Dlist = NULL;
	DlistNode *pos1;
	Dlist = DlistInit(Dlist);//˫�������ʼ��
	DlistPushback(Dlist, 1);//β��
	DlistPushback(Dlist, 2);
	DlistPushback(Dlist, 3);
	DlistPushback(Dlist, 4);
	DlistPushback(Dlist, 5);
	DlistPushback(Dlist, 6);
	DlistPrint(Dlist);//��ӡ����
	DlistPopback(Dlist);//βɾ
	DlistPopback(Dlist);
	DlistPrint(Dlist);//��ӡ����
	pos1 = DlistFind(Dlist, 3);//��3��λ���ҵ�
	DlistErase(pos1);//��pos1λ��ɾ��
	DlistPrint(Dlist);//��ӡ����
}
void test2()
{
	DlistNode *Dlist = NULL;
	DlistNode *pos2;
	Dlist=DlistInit(Dlist);//˫�������ʼ��
	DlistPushFront(Dlist, 10);//ǰ��
	DlistPushFront(Dlist, 6);
	DlistPushFront(Dlist, 7);
	DlistPushFront(Dlist, 8);
	DlistPushFront(Dlist, 9);
	DlistPrint(Dlist);//��ӡ����
	DlistPopFront(Dlist);//ǰɾ
	DlistPopFront(Dlist);
	DlistPrint(Dlist);//��ӡ����
	pos2 = DlistFind(Dlist, 6);//�ҵ�6��λ��
	DlistInsert(pos2, 11);//��pos2ǰ����11
	DlistPrint(Dlist);//��ӡ����
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}
void DlistErase(DlistNode *pos)//��posλ��ɾ��
{
	assert(pos);
	//prev pos next
	DlistNode * prev = pos->prev;
	DlistNode *next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

void DlistPopback(DlistNode *head)//βɾ
{
	assert(head&&head->next != head);
	////����һ
	// head prev tail
	//DlistNode *tail = head->prev;
	//DlistNode *prev = tail->prev;
	//head->prev = prev;
	//prev->next = head;
	//free(tail);
	////////��������ֱ�ӵ���ɾ������
	DlistErase(head->prev);//��βλ��ɾ��
}

void DlistPopFront(DlistNode *head)//ǰɾ
{
	assert(head&&head->next != head);//����ֻ��ͷ��㣬ͷ���������
	/////����һ
	// head next nnext
	//DlistNode *next = head->next;
	//DlistNode *nnext = next->next;
	//head->next = nnext;
	//nnext->prev = head;
	//free(next);
	//next = NULL;

	////////��������ֱ�ӵ���ɾ������
	DlistErase(head->next);//ǰɾ
}
DlistNode * DlistFind(DlistNode *head, Datatype x)//�ҵ�x��λ��
{
	assert(head);
	DlistNode *pos = head->next;//��Ϊhead��ͷ��㣬head->next�ǵ�һ����Ч���
	while (pos->data != x)
	{
		pos = pos->next;
	}
	return pos;
}

void DlistInsert(DlistNode *pos, Datatype x)//����λ�ò���
{
	assert(pos);
	// prev newnode pos 
	DlistNode *prev = pos->prev;
	DlistNode *newnode= CreatNode(x);
	prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = prev;
}

void DlistPushFront(DlistNode *head, Datatype x)//ǰ��
{
	//DlistNode *first = head->next;
	//DlistNode *newnode = CreatNode(x);//����ֻ��ͷ���β��
	// head newnode first
	//head->next = newnode;
	//newnode->next = first;
	//first->prev = head;
	//newnode->prev = head;
	DlistInsert(head->next, x);
}
void DlistPushback(DlistNode *head, Datatype x)//β��
{
	DlistNode *tail = (head)->prev;
	/////β�巽��һ
	//DlistNode *newnode= CreatNode(x);
	////head tail newnode
	//tail->next = newnode;//����ֻ��ͷ������β��
	//newnode->prev = tail;
	//(head)->prev = newnode;
	//newnode->next = head;
	/////β�巽������
	DlistInsert(tail->next , x);
}
void DlistPrint(DlistNode *head)//��ӡ����
{
	DlistNode *cur = head->next;//��Ϊhead��ͷ��㣬head->next�ǵ�һ����Ч���
	while (cur != head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("Head\n");
}
void DlistDestory(DlistNode *head)//����
{
	DlistNode *cur = head->next;//��Ϊ��������ͷ���
	DlistNode *next;
	while (cur != head)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
}
DlistNode *CreatNode(Datatype x)//�������
{
	DlistNode *tmp = (DlistNode *)malloc(sizeof(DlistNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
DlistNode *DlistInit(DlistNode *head)//˫�������ʼ��
{
	head = CreatNode(4);
	head->next = head;
	head->prev = head;
	return head;
}