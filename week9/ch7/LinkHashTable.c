#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int KeyType;
typedef int ValueType;

int m=10;//表长

typedef enum Status //创建枚举体，定义空缺，存在，被删除三种状态Status
{
    EMPTY,//没有元素
    EXIST,//有元素
    DELETE,//有过元素但被删除
}Status;

//节点
typedef struct HashNode
{
    KeyType key;//节点的地址关键值

    ValueType value;//节点存放数据

    Status status;//节点的状态

}HashNode;

//定义哈希表
typedef struct HashTable
{
    HashNode *table; //表中节点

    int count;//表中元素个数

} HashTable;

//初始化哈希表
void InitHashTable(HashTable *hashTable)
{
    int i=0;


    assert(hashTable);//断言函数，用以检测错误

    hashTable->count=0;

    hashTable->table=(HashNode *)malloc(sizeof(HashNode)*m);

    for(i=0;i<m;i++)
    {
        hashTable->table[i].status=EMPTY;
    }
}

//哈希函数
KeyType HashFunc(KeyType key)
{
    return key%m;
}

//插入数据
void HashTableInsert(HashTable *hashTable,ValueType value)
{
    int key=HashFunc(value);

    while(hashTable->table[key].status!=EMPTY)
    {
        key=(key++)%m;
    }

    hashTable->table[key].value=value;

    hashTable->table[key].key=key;

    hashTable->table[key].status=EXIST;
}

//查找
int HashTableSearch(HashTable *hashTable,ValueType value)
{
    int key=HashFunc(value);

    while(hashTable->table[key].value!=value && hashTable->table[key].status!=EMPTY)
    {
        key=(key++)%m;
    }

    if(hashTable->table[key].value==value)
    {
        return key;
    }
    else
    {
        printf("表内没有该元素");

        return 0;
    }
}

//删除数据
void HashTableDelete(HashTable *hashTable,ValueType value)
{
    int key=HashFunc(value);

    while(hashTable->table[key].value!=value && hashTable->table[key].status!=EMPTY)
    {
        key=(key++)%m;
    }

    if(hashTable->table[key].value==value)
    {
        hashTable->table[key].status=DELETE;
    }
    else
    {
        printf("表内没有该元素");
    }
}

//哈希表的销毁
void HashTableDestroy(HashTable *hashTable)
{
    free(hashTable->table);

    hashTable->table=NULL;

    m=0;
}

//哈希表的输出
void Display(HashTable *hashTable)
{
    int i;

    for(i=0;i<m;i++)
    {
        if(hashTable->table[i].status==EXIST)
        {
            printf("%d",hashTable->table[i].value);
        }
    }

    printf("\n");
}

int main()
{
    int i;

    int A[]={1,2,7,8,9,6,5,4,3,0};

    HashTable hashTable;//定义哈希表

    InitHashTable(&hashTable);//初始化

    for(i=0;i<m;i++)//循环插入
    {
        HashTableInsert(&hashTable,A[i]);
    }
    
    Display(&hashTable);//输出

    HashTableDelete(&hashTable,5);//删除5

    Display(&hashTable);//输出
    
    return 0;
}
