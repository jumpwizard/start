#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

struct BtNode//节点
{
    char ch;
 
    struct BtNode *LChild;//左孩子

    struct BtNode *RChild;//右孩子

    int flag;//节点标志
};

//非递归遍历

void nonRecursion(struct BtNode *root)
{
    //创建栈
    SeqStack myStack = init_SeqStack();

    //根进站
    Push_SeqStack(myStack,root);

    //栈中元素大于0，入栈
    while (size_SeqStack(myStack)>0)
    {
        //取栈顶元素
        struct BtNode * topNode=top_SeqStack(myStack);
        //出栈
        Pop_SeqStack(myStack);

        if(topNode->flag==1)
        {
            printf("%c\n",topNode->ch);
            continue;
        }
        
        //若标志位为假，改为真
        topNode->flag=1;

        //判断右子树，存在则入栈
        if (topNode->RChild!=NULL)
        {
            Push_SeqStack(myStack,topNode->RChild);
        }
        
        //判断左子树，存在则入栈
        if (topNode->LChild!=NULL)
        {
            Push_SeqStack(myStack,topNode->LChild);
        }

        //根入栈
        Push_SeqStack(myStack,topNode);
    }

    //释放站
    destroy_SeqStack(myStack);
    

}

//创建二叉树并操作
void Text()
{
    //生产节点
    struct BtNode  NodeA ={'A',NULL,NULL,0};
    struct BtNode  NodeB ={'B',NULL,NULL,0};
    struct BtNode  NodeC ={'C',NULL,NULL,0};
    struct BtNode  NodeD ={'D',NULL,NULL,0};
    struct BtNode  NodeE ={'E',NULL,NULL,0};
    struct BtNode  NodeF ={'F',NULL,NULL,0};
    struct BtNode  NodeG ={'G',NULL,NULL,0};
    struct BtNode  NodeH ={'H',NULL,NULL,0};

    //创建节点关系
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
