#pragma once
#include<stdio.h>
#define N 100

int Heap[N];//建立一个堆数组，其最大容量是N
int Heap_size = 0;//堆中当前元素的数量

//入堆
void putHeap(int d);//Heap[0]是堆顶

//出堆
int getHeap();
