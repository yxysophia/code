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
DlistNode * DlistInit(DlistNode *head);//双向链表初始化
DlistNode * CreatNode(Datatype x);//新增结点
void DlistDestory(DlistNode *head);//销毁
void DlistPushback(DlistNode *head, Datatype x);//尾插
void DlistPushFront(DlistNode *head, Datatype x);//前插
void DlistInsert(DlistNode *pos, Datatype x);//任意位置插入
DlistNode *DlistFind(DlistNode *head, Datatype x);//找到x的位置
void DlistPopFront(DlistNode *head);//前删
void DlistPopback(DlistNode *head);//尾删
void DlistErase(DlistNode *pos);//把pos位置删除
void DlistPrint(DlistNode *head);//打印链表
