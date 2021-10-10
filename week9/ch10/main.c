#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void isAnagram(char s[], int lenght1, char t[], int lenght2) {

    //�����ж��ַ��������Ƿ�һ��
    if (lenght1 != lenght2){
        printf("������ĸ��λ��");
        return;
    }

    int i,j,r1,r2;
    int Hash[26];//������ϣ������ʼ��
    memset(Hash, 0, sizeof(Hash));

    //����s��t��s�е�ÿ����ĸ��Ӧ��ϣ����λ�õ�+1��t���Ӧ��λ�õ�-1
    for (i = 0; i < lenght1; i++){
        r1 = s[i] - 'a';
        r2 = t[i] - 'a';
        Hash[r1]++;
        Hash[r2]--;
    }

    for (i = 0; i < lenght1; i++){//����жϹ�ϣ��������λ���ǲ��Ƕ�Ϊ0
        r1 = s[i] - 'a';
        if (Hash[r1] != 0)
        {
             printf("������ĸ��λ��");
            return;
        }
    }
     printf("����ĸ��λ��");
}

int main()
{
    char A[] = {'a','n','a','g','r','a','m'};
    char B[] = {'n','a','g','a','r','a','m'};

    isAnagram(A,7,B,7);

    return 0;
}