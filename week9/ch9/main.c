#include<stdio.h>
#include<stdlib.h>

int firstUniqChar(char s[], int lenght) {

    //���ù�ϣ��д�ܼ�
    int A[26];//����һ�����鵱��ϣ����Ӧ���26����ĸ
    int i,r;

    memset(A, 0, sizeof(A));//��ʼ��ȫΪ0

    for (i = 0; i < lenght; i++)
    {
        r = s[i] - 'a';
        A[r]++;//ûɨ�赽һ����ĸ������ִ���+1
    }

    for (i = 0; i < lenght; i++){
        r = s[i] - 'a';//����s�е���ĸ˳��ɨ������ִ���
        if (A[r] == 1){//Ϊ1��ֱ�ӷ���
            return i;
        }
    }
    return -1;//û�в鵽�ͷ���-1
}

int main()
{
    char str[8] = {'a','a','b','b','c','d','e','e'};

    printf("��һ�����ظ���ĸ���±��ǣ� %d",firstUniqChar(str,8));

    return 0;
}