//����һ�������������k��ÿ����һ��Ԫ�أ���һ�ε�k���Ԫ��
#include<stdio.h>
#include"SmallHeap.c"
#include"SmallHeap.h"

int k = 3;
//��ʼ����
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

//����Ԫ�غ������k��ֵ
void add(int x)
{
    putHeap(x);

    getHeap();

    printf("��3���ֵ��%d",getHeap());

}

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    KthLargest(a,10);
    add(10);
    return 0;
}