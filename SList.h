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
void SListPushfront(SListNode **pphead, Datatype x);//前插
void SListInsert(SListNode **pphead,SListNode *pos, Datatype x);//前插
SListNode *SListfind(SListNode *phead, Datatype x);//找到x所在位置
void SListPopback(SListNode **pphead);//尾删
void SListPopfront(SListNode **pphead);//前删
void SListErase(SListNode **pphead, Datatype x);//删除
void SListDestory(SListNode **pphead);//销毁




