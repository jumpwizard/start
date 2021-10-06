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

//�ݹ麯��ʵ�ֱ���
void Traversal(struct BtNode *root)
{
    //�������
    if(root==NULL)
    {
        return ;
    }

    //�ȸ�
    printf("%c \n",root->ch);

    //����
    Traversal(root->LChild);

    //����
    Traversal(root->RChild);
}

void freeTree(struct BtNode *root)
{
    if(root==NULL)
    {
        return;
    }

    //���ͷ�������
    freeTree(root->LChild);

    //���ͷ�������
    freeTree(root->RChild);

    //�ͷŸ��ڵ�
    free(root);
    printf("%c���ͷ���\n",root->ch);
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

    //�������
    Traversal(&NodeA);

    //�ͷŵ�������
    freeTree(&NodeA);
    
}

int main()
{
    Text();

    return 0;
}