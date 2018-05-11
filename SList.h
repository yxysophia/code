#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>


typedef int Datatype;

typedef struct SListNode
{
	struct SListNode *next;
	Datatype data;
}SListNode;

void SListPushback(SListNode **pphead,Datatype x);
SListNode * CreateSListNode(Datatype x);
void SListPrint(SListNode **pphead);
void SListPushfront(SListNode **pphead, Datatype x);//ǰ��
void SListInsert(SListNode **pphead,SListNode *pos, Datatype x);//ǰ��
SListNode *SListfind(SListNode *phead, Datatype x);//�ҵ�x����λ��
void SListPopback(SListNode **pphead);//βɾ
void SListPopfront(SListNode **pphead);//ǰɾ
void SListErase(SListNode **pphead, Datatype x);//ɾ��
void SListDestory(SListNode **pphead);//����




