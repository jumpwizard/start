#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int firstUniqChar(char s[], int lenght) {

    //利用哈希表写很简单
    int A[26];//创建一个数组当哈希表，对应存放26个字母
    int i,r;

    memset(A, 0, sizeof(A));//初始化全为0

    for (i = 0; i < lenght; i++)
    {
        r = s[i] - 'a';
        A[r]++;//没扫描到一个字母，其出现次数+1
    }

    for (i = 0; i < lenght; i++){
        r = s[i] - 'a';//根据s中的字母顺序扫描其出现次数
        if (A[r] == 1){//为1则直接返回
            return i;
        }
    }
    return -1;//没有查到就返回-1
}

int main()
{
    char str[8] = {'a','a','b','b','c','d','e','e'};

    printf("第一个非重复字母的下标是： %d",firstUniqChar(str,8));

    return 0;
}
