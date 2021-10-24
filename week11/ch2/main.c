#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int nums[], int n)
{
    int i, j, p;
    for (i = 0; i < n -1; i++){
        p = i;
        for (j = i + 1; j < n; j++){
            if (nums[p] > nums[j]){
                p = j;
            }
        }
        swap(&nums[p], &nums[i]);
    }
}
int main()
{
    int arry[10];
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++){
        arry[i] = rand();
    }
    selectionSort(arry, 10);
    for (i = 0; i < 10; i++){
        printf("%d \n", arry[i]);
    }
    return 0;
}