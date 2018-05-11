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
void HeapInit(Heap* hp, HeapDatatype* a, int n);//堆的初始化
void HeapPrint(Heap *hp);//打印堆
void BigHeapMake(Heap* hp);//大堆的创建
void SmallHeapMake(Heap* hp,int k);//小堆的创建
void HeapAdjustUp(Heap*hp, int child);//向上调整
void BigHeapAdjustDown(Heap*hp, int parent);//向下调成大堆
void SmallHeapAdjustDown(Heap*hp, int parent,int k);//向下调成小堆

void HeapPush(Heap *hp, HeapDatatype data);//向堆里插入数据
void HeapPop(Heap *hp);//堆pop
void HeapSort(Heap *hp);//堆排序
void FindTopK(int *a, int k, int n);//找一组数据里最大的前K个数
void HeapFindTopK(Heap *hp, int k, int n);//找一组数据里最大的前K个数,利用堆