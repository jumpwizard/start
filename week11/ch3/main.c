#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertSort(int nums[], int n)
{
    int i, j, currentNumber;
    for (i = 1; i < n; i++){
        currentNumber = nums[i];
        for (j = i - 1; j >= 0; j--){
            if (currentNumber < nums[j]){
                nums[j + 1] = nums[j];
            }
            else{
                nums[j + 1] = currentNumber;
                break;
            }
        }
        nums[j + 1] = currentNumber;
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
    insertSort(arry, 10);
    for (i = 0; i < 10; i++){
        printf("%d \n", arry[i]);
    }
    return 0;
}