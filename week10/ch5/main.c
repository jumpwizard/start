//对于一个给定的数组和k，每插入一个元素，求一次第k大的元素
#include<stdio.h>
#include"SmallHeap.c"
#include"SmallHeap.h"

int k = 3;
//初始化堆
void KthLargest(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        putHeap(a[i]);
    }
    for (i = 0; i < (n-k); i++){
        getHeap();
    }
}

//插入元素后求其第k大值
void add(int x)
{
    putHeap(x);

    getHeap();

    printf("第3大的值是%d",getHeap());

}

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    KthLargest(a,10);
    add(10);
    return 0;
}