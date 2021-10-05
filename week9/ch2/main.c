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

//ͳ��Ҷ������
void CaculateLeafNum(struct BtNode *root,int *p)
{

    if(root==NULL)
    {
        return;
    }
    
    //�ȸ�
    if(root->LChild==NULL && root->RChild==NULL)
    {
        (*p)++;
    }

    //����
    CaculateLeafNum(root->LChild,p);

    //����
    CaculateLeafNum(root->RChild,p);
}

//ͳ�����ĸ߶�
int GetTreeHeight(struct BtNode *root)
{
    int height,lheight,rheight;

    if(root==NULL)
    {
        return 0;
    }

    //��ȡ�������߶�
    lheight = GetTreeHeight(root->LChild);

    //��ȡ�������߶�
    rheight = GetTreeHeight(root->RChild);

    //ȡ�ϴ�ֵ��1
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

//���������������
void Text()
{
    //�����ڵ�
    struct BtNode  NodeA ={'A',NULL,NULL};
    struct BtNode  NodeB ={'B',NULL,NULL};
    struct BtNode  NodeC ={'C',NULL,NULL};
    struct BtNode  NodeD ={'D',NULL,NULL};
    struct BtNode  NodeE ={'E',NULL,NULL};
    struct BtNode  NodeF ={'F',NULL,NULL};
    struct BtNode  NodeG ={'G',NULL,NULL};
    struct BtNode  NodeH ={'H',NULL,NULL};

    //�����ڵ�֮��Ĺ�ϵ
    NodeA.LChild = &NodeB;
    NodeA.RChild = &NodeF;

    NodeB.RChild = &NodeC;

    NodeC.LChild = &NodeD;
    NodeC.RChild = &NodeE;

    NodeF.RChild = &NodeG;

    NodeG.LChild = &NodeH;

    //ͳ��Ҷ������
    int num=0;

    CaculateLeafNum(&NodeA,&num);

    printf("Ҷ�ӵ�����Ϊ��%d \n",num);

    printf("���ĸ߶�Ϊ��%d",GetTreeHeight(&NodeA));
    
}

int main()
{
    Text();

    return 0;
}