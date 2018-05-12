#include"SList.h"
#include<assert.h>
//��������ĸ��ơ�һ�������ÿ���ڵ㣬
//��һ��ָ��nextָ�뼴��һ��ָ�룬����һ��randomָ��ָ����������һ������ڵ����null
//����Ҫ��������������ظ��ƺ��������
SListNode * SlistComplexCopy(SListNode *SL)
{
	assert(SL);
	SListNode *cur = SL;
	SListNode *next = SL->next;
	SListNode *newnode;
	SListNode *node,*CopySl;
	//��ԭ������������������ÿ�����ݺ���
	while (cur){
		newnode = CreateSList(cur->data);
		//cur  newnode next
		cur->next = newnode;
		newnode->next = next;
		cur = next;
		if(cur)
		next = cur->next;
	}
	//��random
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
	//������
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
			printf("next��NULL ");
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
	FindSList(SL2, 11)->next = FindSList(SL1, 2);//ʹ�����ཻ
	SListprint(SL1);
	SListprint(SL2);
	printf("%d\n",SListIsCrossNode(SL1, SL2));//�ж����������Ƿ��ཻ��������������
	printf("�ཻ��Ϊ:%d\n", SListCrossNode(SL1, SL2)->data);
}
void test9()
{
	SListNode *SL = NULL;
	SListNode * pos1,*pos2;
	SListNode *meet;//������
	SListPushback(&SL, 13);
	SListPushback(&SL, 12);
	SListPushback(&SL, 6);
	/*SListPushback(&SL, 1);*/
	SListPushback(&SL, 2);
	SListprint(SL);
	pos1 = FindSList(SL, 12);
	pos2 = FindSList(SL, 2);
	pos2->next = pos1;//������
	meet = SListIsCycle(SL);
	printf("�л���������:%d\n", meet->data);
	printf("���ĳ���Ϊ��%d\n",SListCyclelen(SL,meet));//���ĳ���
	printf("��ڵ�Ϊ��%d\n", SListEntryNode(SL, meet)->data );//�ҵ�������ڵ�)
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
	printf("�Ҵ����ǣ�%d\n", SListJosephCircle(SL, 3)->data );//Լɪ��  1
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
	printf("�м��㣺%d\n",SListFindMidNode(SL)->data );//����������м��㣬Ҫ��ֻ�ܱ���һ������
	pos = SListFindTailKNode(SL, k);
	printf("������%d����㣺%d\n", k,pos->data);//��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������)
	SListDeTailKNode(pos);//ɾ������ĵ�����K�����
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
	UnionSet(SL1, SL2);//�������������е���
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
	SL = SListMerge(SL1, SL2);//�ϲ������������������Ȼ����
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
	BubbleSList(SL);//����
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
    S= SListRverse(SL);//����
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
	SListInsertFrontNode(pos, 21);//����ͷ�������posǰ����21�����ܱ����õ�����
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
	SListDelNonTailNode(pos);//ɾ����ͷ������ķ�β���
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
	SListPrintTailToHead2(SL);//�ݹ�˼���β��ͷ��ӡ������

}
int main()
{
	test12 ();
	system("pause");
	return 0;
}
void UnionSet(SListNode* SL1, SListNode*SL2)//�������������е���
{
	printf("��ͬ������\n");
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
	//ͳ������������
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
	len = abs(len1 - len2);//��ʾ����ֵ
	while (len--)
		longlist = longlist->next;
	while (longlist != shortlist){
		longlist = longlist->next;
		shortlist = shortlist->next;}
	return shortlist;
   /*�ڶ��ֳ������Ƚϳ��ȣ������������߾���ֵ֮�*/
	//if (len1 > len2){
	//	len = len1 - len2;
	//	while (len--)
	//		SL1 = SL1->next;}
	//if (len1 < len2) {
	//	len = len2 - len1;
	//	while (len--)
	//		SL2 = SL2->next;}
	///*��������һ����*/
	//while (SL1 != SL2 ){
	//	SL1 = SL1->next;
	//	SL2 = SL2->next;}
	//return SL1;
}
int  SListIsCrossNode(SListNode* SL1, SListNode*SL2)//�ж����������Ƿ��ཻ��������������
{
	//���������ཻ��βһ����ȣ�����ֱ���ж�β�Ƿ����
	while (SL1)
		SL1 = SL1->next;
	while (SL2)
		SL2 = SL2->next;
	if (SL1 == SL2)
		return 1;
	else
		return 0;
}
SListNode *SListEntryNode(SListNode* phead, SListNode*meet)//�ҵ�������ڵ�
{
	while (phead != meet)
	{
		phead = phead->next;
		meet = meet->next;
   }
	return meet;
}
int SListCyclelen(SListNode* phead, SListNode*meet)//���ĳ���
{
	//fast��slow�ӻ��������λ�ÿ�ʼ,��Ȼfast������slowһ����
	//�ٴ�����ʱslow�������Ľ�������ǻ��ĳ���
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
SListNode *SListIsCycle(SListNode* phead)//�жϵ������Ƿ����
{
	//�ж��Ƿ��л� ��������������ָ�룬��ָ��һ������������ָ��һ����һ����
	//������ڻ����������������û�л�����ָ�������NULL��
	//fast��������slow��һ��������л���������Ѳ����С���϶�������
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
			return slow;//������
	}
	return NULL;
}
void SListDeTailKNode(SListNode *pos)//ɾ������ĵ�����K�����
{
	//�滻ɾ����
	assert(pos);
	SListNode *cur = pos->next;
	pos->data = cur->data;
	pos->next = cur->next;
	free(cur);
}
//��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode* phead, int k)
{
	//˼·��:ͬ�����ÿ���ָ�룬��ָ������k-1����Ȼ�󣬿���ָ�����һ����
	//������ָ��ͱ���ָ���k-1����ֱ����ָ��Ϊ�գ�slow��Ϊ������K�����
	assert(phead);
	SListNode *slow = phead;
	SListNode *fast = phead;
	while (--k){
		fast->next;
		if (fast)
			fast = fast->next;
		else//��˵�������Ȼ��򲻵�k,�Ǿ��޷��ҵ�������K�������ؿ�ָ��
			return NULL;
	}
	while (fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
SListNode* SListFindMidNode(SListNode* phead)//����������м��㣬Ҫ��ֻ�ܱ���һ������
{
	//˼·��:���ÿ���ָ�룬��ָ��������������ż�Բ�ͬ����
	//Ȼ����ָ����һ������ָ����������ֱ����ָ��Ϊ��
	SListNode *slow = phead;
	SListNode *fast = phead;
	if (phead == NULL || phead->next == NULL)//˵�������ǿջ���ֻ��һ�����
		return phead;
	fast = slow->next->next;
	//��ʹ��->nextʱһ��Ҫ�ж�ǰ���Ƿ�Ϊ�գ�����������ж�slow->next��Ϊ��
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}
	return slow;//���ص�slow������λ��
}
SListNode* SListMerge(SListNode *SL1, SListNode *SL2)//�ϲ�������������
{
	SListNode*SL;
	SListNode*head;
	//ȷ���ϲ������ͷ
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
		//��ʼ�Ƚϴ�С
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
	//����һ������û�н������ͽ������SL��
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
void BubbleSList(SListNode *phead){//ð������
	SListNode *ppre = phead;
	SListNode *pre = ppre->next;
	SListNode *tail = NULL;
	Datatype tmp;
	while (tail != phead->next){
		ppre =phead;
		pre = ppre->next;
		//һ��ð��
		while (pre != tail){
			if ((ppre->data) > (pre->data)){
				tmp = ppre->data;
				ppre->data = pre->data;
				pre->data = tmp;}
			ppre = pre;
			pre = pre->next;}
		tail = ppre;}
}
SListNode* SListRverse(SListNode *phead)//����
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
		if (n3)//Ҫ�ж�n3
			n3 = n3->next;
	}
	phead->next = NULL;//��β��Ϊ��
	phead = n1;
	return phead;
}
SListNode* SListJosephCircle(SListNode *phead, int k){//Լɪ��
	SListNode *tail=phead;
	SListNode *cur = phead;
	int count = k;
	SListNode *tmp=cur;
	SListNode *s;
	while (tail->next)//�γɻ�
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
//����ͷ�������һ�����ǰ����һ����㣬���ܱ����õ�����
void SListInsertFrontNode(SListNode *pos, Datatype x)
{
	assert(pos);
	//�滻���뷨����pos���λ�ô��pos�����ݣ�posλ�õ����ݴ��x
	SListNode *newnode = CreateSList(pos->data);//���´����Ľڵ���pos������
	newnode->next = pos->next;
	pos->next = newnode;
	pos->data = x;
}
void SListDelNonTailNode(SListNode *pos)//ɾ����ͷ������ķ�β���
{
	assert(pos);
	SListNode *tmp=pos->next ;
	pos->data = tmp->data;//ʹ�õ��滻ɾ����
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
void SListPrintTailToHead2(SListNode *phead)////�ݹ�˼���β��ͷ��ӡ������
{
	if (phead == NULL)
		return;
	else
	{
		SListPrintTailToHead2(phead->next);//�����⻯Ϊ������
		printf("%d ", phead->data);
	}
	
}
void SListPrintTailToHead1(SListNode *phead)//��β��ͷ��ӡ������
{
	if (phead == NULL)
		return;
	SListNode *tail = NULL;
	//��һ���ҵ�����β������ָ������β�������ݴ�ӡ������Ȼ���β����ǰ�ƶ�������ѭ��
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
void SListPushback(SListNode **pphead, Datatype x)//β��
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