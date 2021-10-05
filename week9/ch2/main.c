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

//统计叶子数量
void CaculateLeafNum(struct BtNode *root,int *p)
{

    if(root==NULL)
    {
        return;
    }
    
    //先根
    if(root->LChild==NULL && root->RChild==NULL)
    {
        (*p)++;
    }

    //再左
    CaculateLeafNum(root->LChild,p);

    //再右
    CaculateLeafNum(root->RChild,p);
}

//统计树的高度
int GetTreeHeight(struct BtNode *root)
{
    int height,lheight,rheight;

    if(root==NULL)
    {
        return 0;
    }

    //获取左子树高度
    lheight = GetTreeHeight(root->LChild);

    //获取右子树高度
    rheight = GetTreeHeight(root->RChild);

    //取较大值加1
    if(lheight>rheight)
    {
        height=lheight+1;
    }
    else
    {
        height=rheight+1;
    }

    return height;
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

    //统计叶子数量
    int num=0;

    CaculateLeafNum(&NodeA,&num);

    printf("叶子的数量为：%d \n",num);

    printf("树的高度为：%d",GetTreeHeight(&NodeA));
    
}

int main()
{
    Text();

    return 0;
}