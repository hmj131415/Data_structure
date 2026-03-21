#ifndef DATA_TYPE
#define DATA_TYPE int
#endif

typedef DATA_TYPE datatype;

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//定义循环队列的结构体
typedef struct seqQueue
{
    datatype *data;
    int front;
    int rear;
    int size;
}seqQueue;

//初始化循环队列
static seqQueue * initSeqQueue(int size)
{
    //申请管理结构体的内存
    seqQueue *q = (seqQueue *) malloc(sizeof(seqQueue));
    if (q==NULL)
    {
        return NULL;
    }
    //申请队列数据的内存
    q->data = (datatype*)calloc(size+1,sizeof(datatype));
    if (q->data == NULL)
    {
        free(q);
        return NULL;
    }
    q->front = q->rear = 0;
    q->size = size+1;
    return q;
}

//判断循环队列是否为空
static bool __IsSeqEmpty(seqQueue *q)
{
    return q->front == q->rear;
}

//判断循环队列是否为满
static bool __IsSeqFull(seqQueue *q)
{
    return (q->rear+1)%q->size == q->front;
}

//循环队列的入队操作
static bool enQueue(seqQueue *q,datatype data)
{
    if (__IsSeqFull(q))
    {
        return false;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear+1)%q->size;
    return true;
}

//循环队列的出队操作
static bool deQueue(seqQueue *q,datatype *data)
{
    if (__IsSeqEmpty(q))
    {
        return false;
    }
    *data = q->data[q->front];
    q->front = (q->front+1)%q->size;
    return true;
}

//从队头遍历循环队列
static void traverseSeqQueue(seqQueue *q,void(*fun)(datatype *p))
{
    if (__IsSeqEmpty(q))
    {
        printf("循环队列为空\n");
        return;
    }
    int i = q->front;
    while (i != q->rear)
    {
        fun(&q->data[i]);
        i = (i+1)%q->size;
    }
    printf("\n");
}


//链式队列节点的结构体
typedef struct linkQueueNode
{
    datatype data;
    struct linkQueueNode *next;
}linkQueueNode;

//链式队列的管理结构体
typedef struct linkQueueManage
{
    linkQueueNode *front;
    linkQueueNode *rear;
    int size;
}linkQueueManage;

//链式队列的空队列初始化
linkQueueManage *initLinkQueue(void)
{
    linkQueueManage *q = (linkQueueManage *) malloc(sizeof(linkQueueManage));
    if (q==NULL)
    {
        return NULL;
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

//创建新节点
linkQueueNode *createLinkQueueNode(datatype data)
{
    linkQueueNode *node = (linkQueueNode *) malloc(sizeof(linkQueueNode));
    if (node==NULL)
    {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

//判断链式队列是否为空
bool __IsLinkEmpty(linkQueueManage *q)
{
    return q->front == NULL;
}

//循环遍历链式队列，并执行fun函数
void traverseLinkQueue(linkQueueManage *q,void(*fun)(datatype *p))
{
    if (__IsLinkEmpty(q))
    {
        printf("链式队列为空\n");
        return;
    }
    linkQueueNode *p = q->front;
    while (p != NULL)
    {
        fun(&p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

//链式队列的入队操作
bool enLinkQueue(linkQueueManage *q,linkQueueNode *node)
{
    if (__IsLinkEmpty(q))
    {
        q->front =node;
    }
    else
    {
        q->rear->next = node;
    }
    q->rear = node;
    q->size++;
    return true;
}


//链式队列的出队操作
linkQueueNode * deLinkQueue(linkQueueManage *q,datatype *data)
{
    if (__IsLinkEmpty(q))
    {
        return NULL;
    }
    *data = q->front->data;
    linkQueueNode *node = q->front;
    q->front = q->front->next;
    q->size--;
    return node;
}


    
