#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int HeapDatatype;
typedef struct Heap
{
	HeapDatatype *arry;
	int capacity;
	int size;
}Heap;
void HeapInit(Heap* hp, HeapDatatype* a, int n);//�ѵĳ�ʼ��
void HeapPrint(Heap *hp);//��ӡ��
void BigHeapMake(Heap* hp);//��ѵĴ���
void SmallHeapMake(Heap* hp,int k);//С�ѵĴ���
void HeapAdjustUp(Heap*hp, int child);//���ϵ���
void BigHeapAdjustDown(Heap*hp, int parent);//���µ��ɴ��
void SmallHeapAdjustDown(Heap*hp, int parent,int k);//���µ���С��

void HeapPush(Heap *hp, HeapDatatype data);//������������
void HeapPop(Heap *hp);//��pop
void HeapSort(Heap *hp);//������
void FindTopK(int *a, int k, int n);//��һ������������ǰK����
void HeapFindTopK(Heap *hp, int k, int n);//��һ������������ǰK����,���ö�