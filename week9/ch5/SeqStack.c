#include"SeqStack.h"

//��ʼ��ջ
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

//��ջ
void Push_SeqStack(SeqStack stack,void *data)
{
    //���� ����β��
    if(stack==NULL)
    {
        return ;
    }
    if(data==NULL)
    {
        return ;
    }

    struct SStack *mystack=stack;

    //�ж�ջ�Ƿ�����
    if(mystack->m_size==MAX)
    {
        return;
    }

    //�������β��
    mystack->data[mystack->m_size]=data;
    
    //����ջ��С
    mystack->m_size++;

    return;
}

//��ջ
void Pop_SeqStack(SeqStack stack)
{
    //��ջ���� ����βɾ
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

//����ջ��
void * top_SeqStack(SeqStack stack)
{
    //���� �����������һ��Ԫ��

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

//����ջ��С
int size_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return 0;
    }

    struct SStack *mystack=stack;
    return mystack->m_size;
}

//�ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return -1;//�����ָ�룬�����棬ջҲ�ǿ�
    }

    struct SStack *mystack=stack;

    if(mystack->m_size==0)
    {
        return 1;//�����棬ջΪ��
    }

    return 0;//��Ϊ��
}

//����
void destroy_SeqStack(SeqStack stack)
{
    if(stack==NULL)
    {
        return;
    }
    free(stack);
    stack=NULL;
}
