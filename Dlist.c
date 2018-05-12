//有头结点双向循环链表
#include"Dlist.h"
#include<assert.h>
void test1()
{
	DlistNode *Dlist = NULL;
	DlistNode *pos1;
	Dlist = DlistInit(Dlist);//双向链表初始化
	DlistPushback(Dlist, 1);//尾插
	DlistPushback(Dlist, 2);
	DlistPushback(Dlist, 3);
	DlistPushback(Dlist, 4);
	DlistPushback(Dlist, 5);
	DlistPushback(Dlist, 6);
	DlistPrint(Dlist);//打印链表
	DlistPopback(Dlist);//尾删
	DlistPopback(Dlist);
	DlistPrint(Dlist);//打印链表
	pos1 = DlistFind(Dlist, 3);//把3的位置找到
	DlistErase(pos1);//把pos1位置删除
	DlistPrint(Dlist);//打印链表
}
void test2()
{
	DlistNode *Dlist = NULL;
	DlistNode *pos2;
	Dlist=DlistInit(Dlist);//双向链表初始化
	DlistPushFront(Dlist, 10);//前插
	DlistPushFront(Dlist, 6);
	DlistPushFront(Dlist, 7);
	DlistPushFront(Dlist, 8);
	DlistPushFront(Dlist, 9);
	DlistPrint(Dlist);//打印链表
	DlistPopFront(Dlist);//前删
	DlistPopFront(Dlist);
	DlistPrint(Dlist);//打印链表
	pos2 = DlistFind(Dlist, 6);//找到6的位置
	DlistInsert(pos2, 11);//在pos2前插入11
	DlistPrint(Dlist);//打印链表
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}
void DlistErase(DlistNode *pos)//把pos位置删除
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

void DlistPopback(DlistNode *head)//尾删
{
	assert(head&&head->next != head);
	////方法一
	// head prev tail
	//DlistNode *tail = head->prev;
	//DlistNode *prev = tail->prev;
	//head->prev = prev;
	//prev->next = head;
	//free(tail);
	////////方法二：直接调用删除函数
	DlistErase(head->prev);//把尾位置删除
}

void DlistPopFront(DlistNode *head)//前删
{
	assert(head&&head->next != head);//不能只有头结点，头结点必须存在
	/////方法一
	// head next nnext
	//DlistNode *next = head->next;
	//DlistNode *nnext = next->next;
	//head->next = nnext;
	//nnext->prev = head;
	//free(next);
	//next = NULL;

	////////方法二：直接调用删除函数
	DlistErase(head->next);//前删
}
DlistNode * DlistFind(DlistNode *head, Datatype x)//找到x的位置
{
	assert(head);
	DlistNode *pos = head->next;//因为head是头结点，head->next是第一个有效结点
	while (pos->data != x)
	{
		pos = pos->next;
	}
	return pos;
}

void DlistInsert(DlistNode *pos, Datatype x)//任意位置插入
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

void DlistPushFront(DlistNode *head, Datatype x)//前插
{
	//DlistNode *first = head->next;
	//DlistNode *newnode = CreatNode(x);//适用只有头结点尾插
	// head newnode first
	//head->next = newnode;
	//newnode->next = first;
	//first->prev = head;
	//newnode->prev = head;
	DlistInsert(head->next, x);
}
void DlistPushback(DlistNode *head, Datatype x)//尾插
{
	DlistNode *tail = (head)->prev;
	/////尾插方法一
	//DlistNode *newnode= CreatNode(x);
	////head tail newnode
	//tail->next = newnode;//适用只有头结点进行尾插
	//newnode->prev = tail;
	//(head)->prev = newnode;
	//newnode->next = head;
	/////尾插方法二：
	DlistInsert(tail->next , x);
}
void DlistPrint(DlistNode *head)//打印链表
{
	DlistNode *cur = head->next;//因为head是头结点，head->next是第一个有效结点
	while (cur != head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("Head\n");
}
void DlistDestory(DlistNode *head)//销毁
{
	DlistNode *cur = head->next;//因为不能销毁头结点
	DlistNode *next;
	while (cur != head)
	{
		next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
}
DlistNode *CreatNode(Datatype x)//新增结点
{
	DlistNode *tmp = (DlistNode *)malloc(sizeof(DlistNode));
	assert(tmp);
	tmp->data = x;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
DlistNode *DlistInit(DlistNode *head)//双向链表初始化
{
	head = CreatNode(4);
	head->next = head;
	head->prev = head;
	return head;
}