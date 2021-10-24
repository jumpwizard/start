#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shellSort(int nums[], int n)
{
    int gap, currentNum, groupStartINdex, currentIndex, preIndex;
    //找到当前数组所需的knuth序列的最大值
    int maxKnuthNumber = 1;
    while (maxKnuthNumber <= n / 3){
        maxKnuthNumber = maxKnuthNumber * 3 + 1;
    }
    //间隔序列，使用knuth序列
    for (gap = maxKnuthNumber; gap > 0; gap = (gap - 1) / 3){
        // 从 gap 开始，按照顺序将每个元素依次向前插入自己所在的组
        for (currentIndex = gap; currentIndex < n; currentIndex++){
            currentNum = nums[currentIndex];
            preIndex = currentIndex - gap;
            //排查后移
            while (preIndex >= 0 && nums[preIndex] > currentNum){
                nums[preIndex + gap] = nums[preIndex];
                preIndex = preIndex - gap;
            }
            //入位
            nums[preIndex + gap] = currentNum;
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
    shellSort(arry, 10);
    for (i = 0; i < 10; i++){
        printf("%d \n", arry[i]);
    }
    return 0;
}