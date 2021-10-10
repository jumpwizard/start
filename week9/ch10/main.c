#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isAnagram(char s[], int lenght1, char t[], int lenght2) {

    //首先判断字符串长度是否一样
    if (lenght1 != lenght2){
        printf("不是字母异位词");
        return;
    }

    int i,j,r1,r2;
    int Hash[26];//建立哈希表，并初始化
    memset(Hash, 0, sizeof(Hash));

    //遍历s和t，s中的每个字母对应哈希表其位置的+1，t则对应其位置的-1
    for (i = 0; i < lenght1; i++){
        r1 = s[i] - 'a';
        r2 = t[i] - 'a';
        Hash[r1]++;
        Hash[r2]--;
    }

    for (i = 0; i < lenght1; i++){//最后判断哈希表中所有位置是不是都为0
        r1 = s[i] - 'a';
        if (Hash[r1] != 0)
        {
             printf("不是字母异位词");
            return;
        }
    }
     printf("是字母异位词");
}

int main()
{
    char A[] = {'a','n','a','g','r','a','m'};
    char B[] = {'n','a','g','a','r','a','m'};

    isAnagram(A,7,B,7);

    return 0;
}