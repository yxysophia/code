#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int Datatype;
typedef struct DlistNode{
	struct DlistNode *next;
	struct DlistNode *prev;
	Datatype data;
}DlistNode;
DlistNode * DlistInit(DlistNode *head);//˫�������ʼ��
DlistNode * CreatNode(Datatype x);//�������
void DlistDestory(DlistNode *head);//����
void DlistPushback(DlistNode *head, Datatype x);//β��
void DlistPushFront(DlistNode *head, Datatype x);//ǰ��
void DlistInsert(DlistNode *pos, Datatype x);//����λ�ò���
DlistNode *DlistFind(DlistNode *head, Datatype x);//�ҵ�x��λ��
void DlistPopFront(DlistNode *head);//ǰɾ
void DlistPopback(DlistNode *head);//βɾ
void DlistErase(DlistNode *pos);//��posλ��ɾ��
void DlistPrint(DlistNode *head);//��ӡ����
