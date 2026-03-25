#include <stdio.h>
#include "BST.h"
#include <stdlib.h>


//定义BST根节点指针
BSTNode *BST_init(void)
{
    return NULL;
}

//创建BST节点
BSTNode *createBSTNode(int data)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

//插入BST节点
BSTNode *insertBSTNode(BSTNode *root, BSTNode *newnode)
{
    if(root == NULL)
    {
        return newnode;
    }
    else
    {
        if (newnode->data<root->data)
        {
            root->lchild = insertBSTNode(root->lchild, newnode);
        }
        else if (newnode->data>root->data)
        {
            root->rchild = insertBSTNode(root->rchild, newnode);
        }
        else
        {
            printf("数据已存在\n");
            free(newnode);
        }
        return root;
    }
}


//删除BST节点
BSTNode *deleteBSTNode(BSTNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    //要删除的节点在右子树
    if(data>root->data)
    {
        root->rchild = deleteBSTNode(root->rchild, data);
    }
    //要删除的节点在左子树
    else if(data<root->data)
    {
        root->lchild = deleteBSTNode(root->lchild, data);
    }
    //要删除的节点是根节点
    else
    {
        //删除节点有左子树
        if(root->lchild != NULL)
        {
            BSTNode* temp;
            for(temp = root->lchild; temp->rchild != NULL; temp = temp->rchild);
            root->data = temp->data;
            root->lchild = deleteBSTNode(root->lchild, temp->data);
        }
        //删除节点没有左子树,有右子树
        else if(root->rchild != NULL)
        {
            BSTNode* temp;
            for(temp = root->rchild; temp->lchild != NULL; temp = temp->lchild);
            root->data = temp->data;
            root->rchild = deleteBSTNode(root->rchild, temp->data);
            free(temp);
        }
        //删除节点没有左子树,没有右子树
        else
        {
            free(root);
            return NULL;
        }
    }
    return root;
}
