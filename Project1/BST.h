#ifndef __BST_H__
#define __BST_H__

//定义BST节点结构体
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
}BSTNode;

BSTNode *BST_init(void);
BSTNode *createBSTNode(int data);
BSTNode *insertBSTNode(BSTNode *root, BSTNode *newnode);
BSTNode *deleteBSTNode(BSTNode *root, int data);

#endif
