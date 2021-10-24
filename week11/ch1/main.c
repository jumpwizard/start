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

void Bubble(int nums[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (nums[j] >= nums[j + 1]){
                swap(&nums[j], &nums[j+1]);
            }
        }
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
    Bubble(arry, 10);
    for (i = 0; i < 10; i++){
        printf("%d \n", arry[i]);
    }
    return 0;
}