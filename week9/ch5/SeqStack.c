#include"SeqStack.h"

//初始化栈
SeqStack init_SeqStack()
{
    struct SStack *myStack = malloc(sizeof(struct SStack));

    if(myStack==NULL)
    {
        return NULL;
    }

    memset(myStack->data,0,sizeof(void *)*MAX);

    myStack->m_size=0;
    
    return myStack;
}

//入栈
void Push_SeqStack(SeqStack stack,void *data)
{
    //本质 数组尾插
    if(stack==NULL)
    {
        return ;
    }
    if(data==NULL)
    {
        return ;
    }

    struct SStack *mystack=stack;

    //判断栈是否已满
    if(mystack->m_size==MAX)
    {
        return;
    }

    //数组进行尾插
    mystack->data[mystack->m_size]=data;
    
    //更新栈大小
    mystack->m_size++;

    return;
}

//出栈
void Pop_SeqStack(SeqStack stack)
{
    //出栈本质 数组尾删
    if(stack==NULL)
    {
        return;
    }

    struct SStack *mystack=stack;

    if(mystack->m_size==0)
    {
        return;
    }

    mystack->data[mystack->m_size-1]=NULL;

    mystack->m_size--;
}

//返回栈顶
void * top_SeqStack(SeqStack stack)
{
    //本质 返回数组最后一个元素

    if(stack==NULL)
    {
        return NULL;
    }

    struct SStack * mystack=stack;

    if(mystack->m_size==0)
    {
        return NULL;
    }

    return mystack->data[mystack->m_size-1];
}

//反回栈大小
int size_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return 0;
    }

    struct SStack *mystack=stack;
    return mystack->m_size;
}

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return -1;//传入空指针，返回真，栈也是空
    }

    struct SStack *mystack=stack;

    if(mystack->m_size==0)
    {
        return 1;//代表真，栈为空
    }

    return 0;//不为空
}

//销毁
void destroy_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return;
    }
    free(stack);
    stack=NULL;
}
