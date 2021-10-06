#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

struct BtNode
{
    char ch;

    struct BtNode *LChild;

    struct BtNode *RChild;
};

//递归函数实现遍历
void Traversal(struct BtNode *root)
{
    //先序遍历
    if(root==NULL)
    {
        return ;
    }

    //先根
    printf("%c \n",root->ch);

    //再左
    Traversal(root->LChild);

    //再右
    Traversal(root->RChild);
}

void freeTree(struct BtNode *root)
{
    if(root==NULL)
    {
        return;
    }

    //先释放左子树
    freeTree(root->LChild);

    //再释放右子树
    freeTree(root->RChild);

    //释放根节点
    free(root);
    printf("%c被释放了\n",root->ch);
}

//创造二叉树并遍历
void Text()
{
    //建立节点
    struct BtNode  NodeA ={'A',NULL,NULL};
    struct BtNode  NodeB ={'B',NULL,NULL};
    struct BtNode  NodeC ={'C',NULL,NULL};
    struct BtNode  NodeD ={'D',NULL,NULL};
    struct BtNode  NodeE ={'E',NULL,NULL};
    struct BtNode  NodeF ={'F',NULL,NULL};
    struct BtNode  NodeG ={'G',NULL,NULL};
    struct BtNode  NodeH ={'H',NULL,NULL};

    //建立节点之间的关系
    NodeA.LChild = &NodeB;
    NodeA.RChild = &NodeF;

    NodeB.RChild = &NodeC;

    NodeC.LChild = &NodeD;
    NodeC.RChild = &NodeE;

    NodeF.RChild = &NodeG;

    NodeG.LChild = &NodeH;

    //先序遍历
    Traversal(&NodeA);

    //释放掉整棵树
    freeTree(&NodeA);
    
}

int main()
{
    Text();

    return 0;
}