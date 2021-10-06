#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

struct BtNode//�ڵ�
{
    char ch;
 
    struct BtNode *LChild;//����

    struct BtNode *RChild;//�Һ���

    int flag;//�ڵ��־
};

//�ǵݹ����

void nonRecursion(struct BtNode *root)
{
    //����ջ
    SeqStack myStack = init_SeqStack();

    //����վ
    Push_SeqStack(myStack,root);

    //ջ��Ԫ�ش���0����ջ
    while (size_SeqStack(myStack)>0)
    {
        //ȡջ��Ԫ��
        struct BtNode * topNode=top_SeqStack(myStack);
        //��ջ
        Pop_SeqStack(myStack);

        if(topNode->flag==1)
        {
            printf("%c\n",topNode->ch);
            continue;
        }
        
        //����־λΪ�٣���Ϊ��
        topNode->flag=1;

        //�ж�����������������ջ
        if (topNode->RChild!=NULL)
        {
            Push_SeqStack(myStack,topNode->RChild);
        }
        
        //�ж�����������������ջ
        if (topNode->LChild!=NULL)
        {
            Push_SeqStack(myStack,topNode->LChild);
        }

        //����ջ
        Push_SeqStack(myStack,topNode);
    }

    //�ͷ�վ
    destroy_SeqStack(myStack);
    

}

//����������������
void Text()
{
    //�����ڵ�
    struct BtNode  NodeA ={'A',NULL,NULL,0};
    struct BtNode  NodeB ={'B',NULL,NULL,0};
    struct BtNode  NodeC ={'C',NULL,NULL,0};
    struct BtNode  NodeD ={'D',NULL,NULL,0};
    struct BtNode  NodeE ={'E',NULL,NULL,0};
    struct BtNode  NodeF ={'F',NULL,NULL,0};
    struct BtNode  NodeG ={'G',NULL,NULL,0};
    struct BtNode  NodeH ={'H',NULL,NULL,0};

    //�����ڵ��ϵ
    NodeA.LChild = &NodeB;
    NodeA.RChild = &NodeF;

    NodeB.RChild = &NodeC;

    NodeC.LChild = &NodeD;
    NodeC.RChild = &NodeE;

    NodeF.RChild = &NodeG;

    NodeG.LChild = &NodeH;

    //???????

    nonRecursion(&NodeA);
    
}

int main()
{
    Text();

    return 0;
}
