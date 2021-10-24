#include<stdio.h>
#include<stdlib.h>
//#include"BigHeap.h"
#include"BigHeap.c"

//用大根堆求前k个最大的数
void TopK(int a[], int n,int k){
    int i;
    for (i = 0; i < n; i++){
        putHeap(a[i]);
    }
    for (i = 0; i < k; i++)
    {
        printf("%d",getHeap());
    }
}


int main()
{
    int Array[10] = {1, 2, 3, 4, 5, 6, 7 ,8 ,9, 0};

    TopK(Array, 10, 3);

    return 0;
}