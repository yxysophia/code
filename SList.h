#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int Datatype;
typedef struct node {
	struct node *next;
	Datatype data;
	struct node *random;
}SListNode;
void SListPushback(SListNode **pphead, Datatype x);//尾插
SListNode* CreateSList( Datatype x);//新增结点
void SListprint(SListNode *pphead);//打印链表
void SListPrintTailToHead1(SListNode *phead);//从尾到头打印链表
void SListPrintTailToHead2(SListNode *phead);//递归思想从尾到头打印单链表
SListNode* FindSList(SListNode *phead,Datatype x);
void SListDelNonTailNode(SListNode *pos);//删除无头单链表的非尾结点，不能遍历该单链表
void SListInsertFrontNode(SListNode *pos, Datatype x);
//在无头单链表的一个结点前插入一个结点，不能遍历该单链表
SListNode* SListJosephCircle(SListNode *phead, int k);//约瑟夫环
SListNode* SListRverse(SListNode *phead);//逆置
void BubbleSList(SListNode *phead);//冒泡排序
SListNode* SListMerge(SListNode *SL1, SListNode *SL2);//合并两个有序链表
SListNode* SListFindMidNode(SListNode* phead);//查找链表的中间结点，要求只能遍历一次链表
SListNode* SListFindTailKNode(SListNode* phead,int k);
//查找链表的倒数第K个结点，要求只能遍历一次链表
void SListDeTailKNode(SListNode *pos);//删除链表的倒数第K个结点
SListNode * SListIsCycle(SListNode* phead);//判断单链表是否带环
int SListCyclelen(SListNode* phead, SListNode*meet);//环的长度
SListNode *SListEntryNode(SListNode* phead, SListNode*meet);//找到环的入口点
int  SListIsCrossNode(SListNode* SL1, SListNode*SL2);//判断连个链表是否相交，假设链表不带环
SListNode *SListCrossNode(SListNode* SL1, SListNode*SL2);//链表相交的点
void UnionSet(SListNode* SL1, SListNode*SL2);//两个有序链表共有的数