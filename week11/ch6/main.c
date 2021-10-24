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

int partition(int nums[], int start, int end){
    //随机选择基数并将其放置首位
    int index = start + rand() % (end - start + 1);
    swap(&nums[index], &nums[start]);

    int pivot = nums[start];
    int left = start + 1;
    int right = end;
    while (left <= right){
        while (left <= right && nums[right] >= pivot){
            right--;
        }
        while (left <= right && nums[left] <= pivot){
                left++;
        }
        if (left < right){
            swap(&nums[left], &nums[right]);
            right--;
            left++;
        }
    }
    swap(&nums[right], &nums[start]);
    return right;
}

void quick_sort(int nums[], int left, int right)
{
    if (left >= right)
        return;
    int mid = partition(nums, left, right);
    quick_sort(nums, left, mid - 1);
    quick_sort(nums, mid + 1, right);
}

int main()
{
    int arry[10];
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++){
        arry[i] = rand();
    }
    quick_sort(arry, 0, 9);
    for (i = 0; i < 10; i++){
        printf("%d \n", arry[i]);
    }
    return 0;
}