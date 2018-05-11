#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int Datatype;
typedef struct node {
	struct node *next;
	Datatype data;
	struct node *random;
}SListNode;
void SListPushback(SListNode **pphead, Datatype x);//β��
SListNode* CreateSList( Datatype x);//�������
void SListprint(SListNode *pphead);//��ӡ����
void SListPrintTailToHead1(SListNode *phead);//��β��ͷ��ӡ����
void SListPrintTailToHead2(SListNode *phead);//�ݹ�˼���β��ͷ��ӡ������
SListNode* FindSList(SListNode *phead,Datatype x);
void SListDelNonTailNode(SListNode *pos);//ɾ����ͷ������ķ�β��㣬���ܱ����õ�����
void SListInsertFrontNode(SListNode *pos, Datatype x);
//����ͷ�������һ�����ǰ����һ����㣬���ܱ����õ�����
SListNode* SListJosephCircle(SListNode *phead, int k);//Լɪ��
SListNode* SListRverse(SListNode *phead);//����
void BubbleSList(SListNode *phead);//ð������
SListNode* SListMerge(SListNode *SL1, SListNode *SL2);//�ϲ�������������
SListNode* SListFindMidNode(SListNode* phead);//����������м��㣬Ҫ��ֻ�ܱ���һ������
SListNode* SListFindTailKNode(SListNode* phead,int k);
//��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
void SListDeTailKNode(SListNode *pos);//ɾ������ĵ�����K�����
SListNode * SListIsCycle(SListNode* phead);//�жϵ������Ƿ����
int SListCyclelen(SListNode* phead, SListNode*meet);//���ĳ���
SListNode *SListEntryNode(SListNode* phead, SListNode*meet);//�ҵ�������ڵ�
int  SListIsCrossNode(SListNode* SL1, SListNode*SL2);//�ж����������Ƿ��ཻ��������������
SListNode *SListCrossNode(SListNode* SL1, SListNode*SL2);//�����ཻ�ĵ�
void UnionSet(SListNode* SL1, SListNode*SL2);//�������������е���