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

//拷贝二叉树
struct BtNode * copyTree(struct BtNode *root)
{
    if(root==NULL)
    {
        return NULL;
    }

    //先拷贝左子树
    struct BtNode *lChild = copyTree(root->LChild);

    //再拷贝右子树
    struct BtNode *rChild = copyTree(root->RChild);

    //创建新节点
    struct BtNode *newNode = malloc(sizeof(struct BtNode));

    //把拷贝的左右子树挂载到新节点上

    newNode->LChild = lChild;
    newNode->RChild = rChild;
    newNode->ch = root->ch;

    //返回结果
    return newNode;
}


//创造二叉树并进行操作
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

    //统计数的高度
    printf("树的高度为：%d \n",GetTreeHeight(&NodeA));

    //遍历拷贝的二叉树
    Traversal(copyTree(&NodeA));

    


    
}

int main()
{
    Text();

    return 0;
}