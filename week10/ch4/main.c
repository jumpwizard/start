#include<stdio.h>
#include<stdlib.h>
//#include"BigHeap.h"
#include"BigHeap.c"

//用大根堆求第k个最大的数
int TopK(int a[], int n,int k){
    int i,res;
    for (i = 0; i < n; i++){
        putHeap(a[i]);
    }
    for (i = 0; i < k; i++)
    {
        res = getHeap(); 
    }
    return res;
}


int main()
{
    int Array[10] = {1, 2, 3, 4, 5, 6, 7 ,8 ,9, 0};

    printf("第三个最大的数是%d",TopK(Array, 10, 3));

    return 0;
}