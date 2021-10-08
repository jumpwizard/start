#include<stdio.h>
#include<stdlib.h>

#define HashSize 7

#define NULLkey -999 //定义伪空值

#define Deletekey -888 //定义伪删除值



int m=0;  //哈希表表长

typedef struct   //定义哈希表
{
    int *elem; //基址

    int count;  //当前数据元素个数
} HashTable;

//初始化
void Init(HashTable *hashTable)
{
	int i;
	
    m=HashSize;

    hashTable->elem=(int *)malloc(m * sizeof(int));//申请内存空间

    hashTable->count=m;

    for(i=0;i<HashSize;i++)
    {
        hashTable->elem[i]=NULLkey;
    }
}

//哈希函数（除留余数法）
int Hash(int data)
{
    return data%m;
}

//插入
void Insert(HashTable *hashTable,int data)
{
    int HashAddress=Hash(data);

    while(hashTable->elem[HashAddress]!=NULLkey)
    {
        HashAddress=(HashAddress++)%m;
    }

    hashTable->elem[HashAddress]=data;
}

//查找
int Search(HashTable *hashTable,int data)
{
    int HashAddress=Hash(data);

    while(hashTable->elem[HashAddress]!=data && hashTable->elem[HashAddress]!=NULLkey)
    {
        HashAddress = (HashAddress++)%m;
    }

    return HashAddress;
}

//输出所有表值
void Display(HashTable *hashTable)
{
	int i;
	
    for(i=0;i<m;i++)
    {
        if(hashTable->elem[i]!=NULLkey && hashTable->elem[i]!=Deletekey)
        {
            printf("%d \n",hashTable->elem[i]);
        }
    }
}

int main()
{
	int i;
    int A[]={5,7,6,4,2,1,3};

    HashTable hashTable;

    Init(&hashTable);

    for(i=0;i<HashSize;i++)
    {
        Insert(&hashTable,A[i]);
    }

    Display(&hashTable);



    return 0;
}
