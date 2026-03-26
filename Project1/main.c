#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//二叉树结构体
typedef struct BSTNode
{
    int data;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
}BSTNode;

//定义BST根节点指针
BSTNode *BST_init(void)
{
    return NULL;
}

//创建BST节点
BSTNode *createBSTNode(int data)
{
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (node == NULL)
    {
        printf("BST节点内存分配失败\n");
        return NULL;
    }
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
        printf("插入失败，节点数据已存在\n");
        free(newnode);
    }
    return root;
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
        BSTNode *temp = root;
        //删除节点
        if(root->lchild == NULL&&root->rchild == NULL)
        {
            //删除根节点
            free(root);
            return NULL;
        }
        else if(root->lchild != NULL)
        {
            for ( temp = root->lchild; temp->rchild != NULL; temp = temp->rchild);
            root->data = temp->data;
            root->lchild = deleteBSTNode(root->lchild, temp->data);
        }
        else
        {
            for ( temp = root->rchild; temp->lchild != NULL; temp = temp->lchild);
            root->data = temp->data;
            root->rchild = deleteBSTNode(root->rchild, temp->data);
        }
    }
    return root;
}

//前序遍历并执行回调函数
void preorderTraversalWithCallback(BSTNode *root, void (*callback)(void *))
{
    if(root == NULL)
    {
        return;
    }
    callback(&(root->data));
    preorderTraversalWithCallback(root->lchild, callback);
    preorderTraversalWithCallback(root->rchild, callback);
}

//中序遍历并执行回调函数
void inorderTraversalWithCallback(BSTNode *root, void (*callback)(void *))
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversalWithCallback(root->lchild, callback);
    callback(&(root->data));
    inorderTraversalWithCallback(root->rchild, callback);
}

//后序遍历并执行回调函数
void postorderTraversalWithCallback(BSTNode *root, void (*callback)(void *))
{
    if(root == NULL)
    {
        return;
    }
    postorderTraversalWithCallback(root->lchild, callback);
    postorderTraversalWithCallback(root->rchild, callback);
    callback(&(root->data));
}

//定义队列节点结构体
typedef struct SeqQueueNode
{
    BSTNode *data;
    struct SeqQueueNode *next;
}SeqQueueNode;


//定义按层遍历队列管理结构体
typedef struct SeqQueue
{
    int size;
    SeqQueueNode *front;
    SeqQueueNode *rear;
}SeqQueue;



//初始化队列
SeqQueue *initSeqQueue(void)
{
    SeqQueue *q = (SeqQueue *)malloc(sizeof(SeqQueue));
    if (q == NULL)
    {
        printf("队列内存分配失败\n");
        return NULL;
    }
    q->size = 0;
    q->front = q->rear = 0;
    return q;
}

//创建新节点
SeqQueueNode *createSeqQueueNode(BSTNode *data)
{
    SeqQueueNode *node = (SeqQueueNode *)malloc(sizeof(SeqQueueNode));
    if (node == NULL)
    {
        printf("队列节点内存分配失败\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

//判断队列是否为空
bool __IsSeqEmpty(SeqQueue *q)
{
    return q->size == 0;
}

//按层便利结构体队列入队
void enqueue(SeqQueue *q, BSTNode *data)
{
    SeqQueueNode *node = createSeqQueueNode(data);
    if (node == NULL)
    {
        return;
    }
    if (__IsSeqEmpty(q))
    {
        q->front=node;
    }
    else
    {
        q->rear->next=node;
    }
    q->rear = node;
    q->size++;
}

//按层便利结构体队列出队
SeqQueueNode *dequeue(SeqQueue *q)
{
    if (__IsSeqEmpty(q))
    {
        return NULL;
    }
    SeqQueueNode *node = q->front;
    q->front = q->front->next;
    q->size--;
    return node;
}

//按层便利
void levelOrderTraversal(BSTNode *root, void (*callback)(void *))
{
    SeqQueue *q = initSeqQueue();
    if (root == NULL)
    {
        printf("树为空\n");
        return;
    }
    //入队根节点
    enqueue(q, root);
    while (!__IsSeqEmpty(q))
    {
        /* code */
        //出队
        SeqQueueNode *node = dequeue(q);
        if (node == NULL)
        {
            break;
        }
        callback(&(node->data->data));
        //入队左子树
        if (node->data->lchild != NULL)
        {
            enqueue(q, node->data->lchild);
        }
        //入队右子树
        if (node->data->rchild != NULL)
        {
            enqueue(q, node->data->rchild);
        }
    }
    return;
}



//销毁BST
void destroyBST(BSTNode *root)
{
    if(root == NULL)
    {
        return;
    }
    destroyBST(root->lchild);
    destroyBST(root->rchild);
    printf("销毁节点：%d\n", root->data);
    free(root);
}

//打印指定位置的节点数据
void printNodeDataAtPosition(void *data)
{
    printf("%d  ", *(int *)data);
}

//主函数
int main(void)
{
    //初始化BST
    BSTNode *root = BST_init();

    printf("输入数字：,正数插入,负数删除,Q或q退出\n");
    int num;
    char cmd;
    while (1)
    {
        scanf("%d", &num);
        if(scanf("%c", &cmd) == 1&&(cmd == 'Q'||cmd == 'q'))
        {
            break;
        }
        else if (num >= 0)
        {
            //插入节点

            //创建节点
            BSTNode *newnode = createBSTNode(num);
            root = insertBSTNode(root, newnode);
        }
        else if (num < 0)
        {
            //删除节点
            root = deleteBSTNode(root, -(num));
        }
    }
    //前序遍历并执行回调函数
    preorderTraversalWithCallback(root, printNodeDataAtPosition);
    printf("\n");
    //中序遍历并执行回调函数
    inorderTraversalWithCallback(root, printNodeDataAtPosition);    
    printf("\n");
    //后序遍历并执行回调函数
    postorderTraversalWithCallback(root, printNodeDataAtPosition);
    printf("\n");
    //按层遍历并执行回调函数
    levelOrderTraversal(root, printNodeDataAtPosition);
    printf("\n");
    
    //销毁BST
    destroyBST(root);
    
    //插入节点
    return 0;
}