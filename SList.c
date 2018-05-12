#include"SList.h"
#include<assert.h>
//复杂链表的复制。一个链表的每个节点，
//有一个指向next指针即下一个指针，还有一个random指针指向这个链表的一个随机节点或者null
//现在要求复制这个链表，返回复制后的新链表
SListNode * SlistComplexCopy(SListNode *SL)
{
	assert(SL);
	SListNode *cur = SL;
	SListNode *next = SL->next;
	SListNode *newnode;
	SListNode *node,*CopySl;
	//将原链表数据依次链接在每个数据后面
	while (cur){
		newnode = CreateSList(cur->data);
		//cur  newnode next
		cur->next = newnode;
		newnode->next = next;
		cur = next;
		if(cur)
		next = cur->next;
	}
	//置random
	cur = SL;
    node = SL->next;
	while (cur)
	{
		if (cur->random == NULL)
			node->random = NULL;
		else
			node->random = cur->random->next;
		cur = node->next;
		if (cur)
			node = cur->next;
	}
	//拆链表
	cur = SL;
	CopySl = node = SL->next;
	next = node->next;
	while (cur){
		cur->next = node->next;
		if (next)
			node->next = next->next;
		else
			node->next = NULL;
		cur = next;
		if (cur){
			node = cur->next;
			next = node->next;
		}
	}
	return CopySl;
}
void SlistComplexCopyPrint(SListNode *CopySl)
{
	SListNode *random;
	SListNode *next;
	while (CopySl)
	{
		printf("%d:", CopySl->data);
		next = CopySl->next;
		random = CopySl->random;
		if (next)
			printf("next:%d  ", next->data);
		else
			printf("next：NULL ");
		if (random)
			printf("random:%d\n", random->data);
		else
			printf("next:NULL ");
		CopySl = CopySl->next;
	}
	printf("\n");
}
void test12()
{
	SListNode *SL=NULL;
	SListNode *CopySl;
	SListPushback(&SL, 1);
	SListPushback(&SL, 2);
	SListPushback(&SL, 3);
	SListPushback(&SL, 4);
	FindSList(SL, 1)->random = FindSList(SL, 3);
	FindSList(SL, 2)->random = FindSList(SL, 1);
	FindSList(SL, 3)->random = FindSList(SL, 3);
	FindSList(SL, 4)->random = NULL;
	SlistComplexCopyPrint(SL);
	CopySl=SlistComplexCopy(SL);
	SlistComplexCopyPrint(CopySl);
}
void test10()
{
	SListNode *SL1 = NULL;
	SListNode *SL2 = NULL;
	SListPushback(&SL1, 1);
	SListPushback(&SL1, 2);
	SListPushback(&SL1, 8);
	SListPushback(&SL1, 9);
	SListPushback(&SL2, 4);
	SListPushback(&SL2, 5);
	SListPushback(&SL2, 6);
	SListPushback(&SL2, 7);
	SListPushback(&SL2, 11);
	FindSList(SL2, 11)->next = FindSList(SL1, 2);//使链表相交
	SListprint(SL1);
	SListprint(SL2);
	printf("%d\n",SListIsCrossNode(SL1, SL2));//判断连个链表是否相交，假设链表不带环
	printf("相交点为:%d\n", SListCrossNode(SL1, SL2)->data);
}
void test9()
{
	SListNode *SL = NULL;
	SListNode * pos1,*pos2;
	SListNode *meet;//相遇点
	SListPushback(&SL, 13);
	SListPushback(&SL, 12);
	SListPushback(&SL, 6);
	/*SListPushback(&SL, 1);*/
	SListPushback(&SL, 2);
	SListprint(SL);
	pos1 = FindSList(SL, 12);
	pos2 = FindSList(SL, 2);
	pos2->next = pos1;//构建环
	meet = SListIsCycle(SL);
	printf("有环相遇点是:%d\n", meet->data);
	printf("环的长度为：%d\n",SListCyclelen(SL,meet));//环的长度
	printf("入口点为：%d\n", SListEntryNode(SL, meet)->data );//找到环的入口点)
}
void test8()
{
	SListNode *SL = NULL;
	SListPushback(&SL, 1);
	SListPushback(&SL, 2);
	SListPushback(&SL, 3);
	SListPushback(&SL, 5);
	SListPushback(&SL, 8);
	SListPushback(&SL, 9);
	SListprint(SL);
	printf("幸存者是：%d\n", SListJosephCircle(SL, 3)->data );//约瑟夫环  1
}
void test7()
{
	SListNode *SL = NULL;
	int k = 2;
	SListNode *pos;
	SListPushback(&SL, 13);
	SListPushback(&SL, 12);
	SListPushback(&SL, 6);
	SListPushback(&SL, 1);
	SListPushback(&SL, 2);
	SListprint(SL);
	printf("中间结点：%d\n",SListFindMidNode(SL)->data );//查找链表的中间结点，要求只能遍历一次链表
	pos = SListFindTailKNode(SL, k);
	printf("倒数第%d个结点：%d\n", k,pos->data);//查找链表的倒数第K个结点，要求只能遍历一次链表)
	SListDeTailKNode(pos);//删除链表的倒数第K个结点
	SListprint(SL);
	
}
void test11()
{
	SListNode *SL1 = NULL;
	SListNode *SL2 = NULL;
	SListPushback(&SL1, 4);
	SListPushback(&SL1, 6);
	SListPushback(&SL1, 7);
	SListPushback(&SL1, 15);
	SListprint(SL1);
	SListPushback(&SL2, 2);
	SListPushback(&SL2, 6);
	SListPushback(&SL2, 7);
	SListPushback(&SL2, 15);
	SListPushback(&SL2, 18);
	SListprint(SL2);
	UnionSet(SL1, SL2);//两个有序链表共有的数
}
void test6()
{
	SListNode *SL1 = NULL;
	SListNode *SL2 = NULL;
	SListNode*SL;
	/*SListPushback(&SL1, 3);*/
	SListPushback(&SL1, 4);
	SListPushback(&SL1, 6);
	SListPushback(&SL1, 7);
	SListPushback(&SL1, 15);
	SListprint(SL1);
	SListPushback(&SL2, 2);
	SListPushback(&SL2, 6);
	SListPushback(&SL2, 7);
	SListPushback(&SL2, 15);
	SListPushback(&SL2, 18);
	SListprint(SL2);
	SL = SListMerge(SL1, SL2);//合并两个有序链表，结果依然有序
	SListprint(SL);
}
void test5()
{
	SListNode *SL = NULL;
	SListPushback(&SL, 13);
	SListPushback(&SL, 12);
	SListPushback(&SL, 6);
	SListPushback(&SL, 1);
	SListPushback(&SL, 2);
	SListprint(SL);
	BubbleSList(SL);//逆置
	SListprint(SL);
}
void test4()
{
	SListNode *SL = NULL;
	SListNode *S;
	SListPushback(&SL, 1);
	SListPushback(&SL, 2);
	SListPushback(&SL, 3);
	SListPushback(&SL, 5);
	SListPushback(&SL, 8);
	SListprint(SL);
    S= SListRverse(SL);//逆置
	SListprint(S);
}
void test3()
{
	SListNode *SL = NULL;
	SListNode *pos;
	SListPushback(&SL, 17);
	SListPushback(&SL, 4);
	SListPushback(&SL, 10);
	SListPushback(&SL, 5);
	SListPushback(&SL, 8);
	SListprint(SL);
	pos = FindSList(SL, 10);
	SListInsertFrontNode(pos, 21);//在无头单链表的pos前插入21，不能遍历该单链表
	SListprint(SL);
}
void test2()
{
	SListNode *SL = NULL;
	SListNode *pos;
	SListPushback(&SL, 17);
	SListPushback(&SL, 16);
	SListPushback(&SL, 10);
	SListPushback(&SL, 9);
	SListPushback(&SL, 8);
	SListprint(SL);
	pos = FindSList(SL, 10);
	SListDelNonTailNode(pos);//删除无头单链表的非尾结点
	SListprint(SL);
}
void test1()
{	
	SListNode *SL = NULL;
	SListPushback(&SL, 17);
	SListPushback(&SL, 4);
	SListPushback(&SL, 10);
	SListPushback(&SL, 5);
	SListPushback(&SL, 8);
	SListprint(SL);
	SListPrintTailToHead1(SL);
	SListPrintTailToHead2(SL);//递归思想从尾到头打印单链表

}
int main()
{
	test12 ();
	system("pause");
	return 0;
}
void UnionSet(SListNode* SL1, SListNode*SL2)//两个有序链表共有的数
{
	printf("相同的数：\n");
	while (SL1&&SL2)
	{
		if (SL1->data < SL2->data)
			SL1 = SL1->next;
		else if(SL1->data >SL2->data )
			SL2 = SL2->next;
		else
		{
			printf("%d ", SL1->data);
			SL1 = SL1->next;
			SL2 = SL2->next;
		}
	}
}
SListNode *SListCrossNode(SListNode* SL1, SListNode*SL2)
{
	int len1 = 0, len2 = 0,len=0;
	SListNode* shortlist;
	SListNode* longlist;
	SListNode*cur1 = SL1;
	SListNode*cur2 = SL2;
	//统计两个链表长度
	while (cur1){
		len1++;
		cur1 = cur1->next;}
	while (cur2){
		len2++;
		cur2 = cur2->next;}
	shortlist = SL1;
	longlist = SL2;
	if (len1 > len2){
		shortlist = SL2;
		longlist = SL1;}
	len = abs(len1 - len2);//表示绝对值
	while (len--)
		longlist = longlist->next;
	while (longlist != shortlist){
		longlist = longlist->next;
		shortlist = shortlist->next;}
	return shortlist;
   /*第二种常规代码比较长度，长的链表先走绝对值之差步*/
	//if (len1 > len2){
	//	len = len1 - len2;
	//	while (len--)
	//		SL1 = SL1->next;}
	//if (len1 < len2) {
	//	len = len2 - len1;
	//	while (len--)
	//		SL2 = SL2->next;}
	///*两个链表一起走*/
	//while (SL1 != SL2 ){
	//	SL1 = SL1->next;
	//	SL2 = SL2->next;}
	//return SL1;
}
int  SListIsCrossNode(SListNode* SL1, SListNode*SL2)//判断连个链表是否相交，假设链表不带环
{
	//两个链表相交，尾一定相等，所以直接判断尾是否相等
	while (SL1)
		SL1 = SL1->next;
	while (SL2)
		SL2 = SL2->next;
	if (SL1 == SL2)
		return 1;
	else
		return 0;
}
SListNode *SListEntryNode(SListNode* phead, SListNode*meet)//找到环的入口点
{
	while (phead != meet)
	{
		phead = phead->next;
		meet = meet->next;
   }
	return meet;
}
int SListCyclelen(SListNode* phead, SListNode*meet)//环的长度
{
	//fast和slow从环里的任意位置开始,依然fast两步，slow一步，
	//再次相遇时slow所经过的结点数就是环的长度
	int len = 0;
	SListNode *fast = meet;
	SListNode *slow = meet;
	while (1)
	{
		slow = slow->next;
		fast = fast->next->next;
		len++;
		if (fast == slow)
			return len;
	}
}
SListNode *SListIsCycle(SListNode* phead)//判断单链表是否带环
{
	//判断是否有环 ：利用两个快慢指针，快指针一次走两步，慢指针一次走一步，
	//如果存在环，两者相遇；如果没有环，快指针会遇到NULL；
	//fast走两步，slow走一步，如果有环，这样会把差距缩小，肯定会相遇
	if (phead == NULL || phead->next == NULL)
		return NULL;
	SListNode *fast = phead;
	SListNode *slow = phead;
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
		if (fast == slow)
			return slow;//相遇点
	}
	return NULL;
}
void SListDeTailKNode(SListNode *pos)//删除链表的倒数第K个结点
{
	//替换删除法
	assert(pos);
	SListNode *cur = pos->next;
	pos->data = cur->data;
	pos->next = cur->next;
	free(cur);
}
//查找链表的倒数第K个结点，要求只能遍历一次链表
SListNode* SListFindTailKNode(SListNode* phead, int k)
{
	//思路是:同样利用快慢指针，快指针先走k-1步，然后，快慢指针各走一步，
	//这样快指针就比慢指针快k-1步，直到快指针为空，slow即为倒数第K个结点
	assert(phead);
	SListNode *slow = phead;
	SListNode *fast = phead;
	while (--k){
		fast->next;
		if (fast)
			fast = fast->next;
		else//就说明链表长度还打不到k,那就无法找到倒数第K个，返回空指针
			return NULL;
	}
	while (fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
SListNode* SListFindMidNode(SListNode* phead)//查找链表的中间结点，要求只能遍历一次链表
{
	//思路是:利用快慢指针，快指针先走两步（奇偶性不同），
	//然后慢指针走一步，快指针走两步，直到快指针为空
	SListNode *slow = phead;
	SListNode *fast = phead;
	if (phead == NULL || phead->next == NULL)//说明链表是空或者只有一个结点
		return phead;
	fast = slow->next->next;
	//在使用->next时一定要判断前者是否为空，上面语句已判断slow->next不为空
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	return slow;//返回的slow是上中位数
}
SListNode* SListMerge(SListNode *SL1, SListNode *SL2)//合并两个有序链表
{
	SListNode*SL;
	SListNode*head;
	//确定合并链表的头
	if (SL1->data < SL2->data){
		head = SL1;
		SL1 = SL1->next;
	}
	else{
		head = SL2;
		SL2 = SL2->next;
	}
	SL = head;
	while (SL1&&SL2)
	{
		//开始比较大小
		if (SL1->data < SL2->data)
		{
			SL->next = SL1;
			SL = SL1;
			SL1 = SL1->next;
		}
		else{
			SL->next = SL2;
			SL = SL2;
			SL2 = SL2->next;}
	}
	//其中一个链表还没有结束，就将其放在SL后
	if (SL1){
		SL->next = SL1;
		SL = SL1;
		SL1 = SL1->next;}
	else{
		SL->next = SL2;
		SL = SL2;
		SL2 = SL2->next;}
	return head;
}
void BubbleSList(SListNode *phead){//冒泡排序
	SListNode *ppre = phead;
	SListNode *pre = ppre->next;
	SListNode *tail = NULL;
	Datatype tmp;
	while (tail != phead->next){
		ppre =phead;
		pre = ppre->next;
		//一趟冒泡
		while (pre != tail){
			if ((ppre->data) > (pre->data)){
				tmp = ppre->data;
				ppre->data = pre->data;
				pre->data = tmp;}
			ppre = pre;
			pre = pre->next;}
		tail = ppre;}
}
SListNode* SListRverse(SListNode *phead)//逆置
{
	SListNode * n1 = phead;
	SListNode *n2;
	SListNode *n3;
	n2 = n1->next;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3)//要判断n3
			n3 = n3->next;
	}
	phead->next = NULL;//将尾设为空
	phead = n1;
	return phead;
}
SListNode* SListJosephCircle(SListNode *phead, int k){//约瑟夫环
	SListNode *tail=phead;
	SListNode *cur = phead;
	int count = k;
	SListNode *tmp=cur;
	SListNode *s;
	while (tail->next)//形成环
		tail = tail->next;
	tail->next = phead;
	while (tmp->next !=tmp){
		count = k;
		while (--count){
			tmp = cur;
			cur = cur->next;}
		s = cur;
		tmp->next = cur->next;
		cur = cur->next;
		free(s);}
	return tmp;
}
//在无头单链表的一个结点前插入一个结点，不能遍历该单链表
void SListInsertFrontNode(SListNode *pos, Datatype x)
{
	assert(pos);
	//替换插入法，将pos后的位置存放pos的数据，pos位置的数据存放x
	SListNode *newnode = CreateSList(pos->data);//将新创建的节点存放pos的数据
	newnode->next = pos->next;
	pos->next = newnode;
	pos->data = x;
}
void SListDelNonTailNode(SListNode *pos)//删除无头单链表的非尾结点
{
	assert(pos);
	SListNode *tmp=pos->next ;
	pos->data = tmp->data;//使用的替换删除法
	pos->next = tmp->next;
	free(tmp);
}
SListNode* FindSList(SListNode *phead,Datatype x)
{
	assert(phead);
	SListNode *pos = phead;
	while (pos->data != x)
	{
		pos = pos->next;
	}
	return pos;
}
void SListPrintTailToHead2(SListNode *phead)////递归思想从尾到头打印单链表
{
	if (phead == NULL)
		return;
	else
	{
		SListPrintTailToHead2(phead->next);//将问题化为子问题
		printf("%d ", phead->data);
	}
	
}
void SListPrintTailToHead1(SListNode *phead)//从尾到头打印单链表
{
	if (phead == NULL)
		return;
	SListNode *tail = NULL;
	//第一次找到链表尾部，将指向链表尾部的数据打印出来，然后把尾部向前移动，依次循环
	SListNode *cur=phead;
	while (tail != phead)
	{
		cur = phead;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d ", cur->data);
		tail = cur;
	}
	printf("\n");
}
SListNode* CreateSList( Datatype x)
{
	SListNode *tmp;
	tmp = (SListNode *)malloc(sizeof(SListNode));
	if (tmp)
	{
		tmp->data = x;
		tmp->next = NULL;
		return tmp;
	}
	else
		return NULL;
	
}
void SListprint(SListNode *pphead)
{
	while (pphead)
	{
		printf("%d->", pphead->data);
		pphead = pphead->next;
	}
	printf("NULL\n");
}
void SListPushback(SListNode **pphead, Datatype x)//尾插
{
	SListNode *newnode;
	SListNode *cur = *pphead;
	newnode= CreateSList(x);
	if ((*pphead) == NULL)
		*pphead = newnode;
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}