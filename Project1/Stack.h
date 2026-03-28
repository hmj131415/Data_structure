//栈操作的头文件
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#ifndef DATA_TYPE
#define DATA_TYPE int
#endif

typedef DATA_TYPE datatype;

//顺序栈的操作

//定义顺序栈的管理结构体
typedef struct seqStack
{
    datatype *data;
    int top;
    int size;
}seqStack;  

//初始化顺序栈
static seqStack * seqStack_init(int size)
{
    seqStack *s = (seqStack *) malloc(sizeof(seqStack));
   if (s!=NULL)
   {
      s->data = (datatype*)calloc(size,sizeof(datatype));
      if (s->data == NULL)
      {
        free(s);
        return NULL;
      }
      s->top = -1;
      s->size = size;
      return s;
   }
   return NULL;
 }

static bool __IsSeqFull(seqStack *s)
{
    return s->top == s->size - 1;
}

//顺序栈的入栈操作
static void seqStack_push(seqStack *s,datatype data)
{
    if (s!=NULL)
    {
            if (__IsSeqFull(s))
        {
            printf("seqStack_push failed,stack is full\n");
            return;
        }
        s->data[++s->top] = data;
    
    }
    return;
}

//判断顺序栈是否为空
static bool __IsSeqEmpty(seqStack *s)
{
    return s->top == -1;
}

//取栈顶
static bool seqStack_top(seqStack *s,datatype *data)
{
    if (s==NULL)
    {
        printf("seqStack_top failed,stack is empty\n");
        return false;
    }
    if (__IsSeqEmpty(s))
    {
        return false;
    }
    *data = s->data[s->top];
    return true;
}

//顺序栈的出栈操作
static bool seqStack_pop(seqStack *s,datatype *data)
{
    
    if (seqStack_top(s,data))
    {
        s->top--;
        return true;
    }
    return false;
}

//遍历顺序栈，并执行操作
static void seqStack_traverse(seqStack *s,void (*fun)(datatype *p))
{
    for (int i = 0;i<=s->top;i++)
    {
        fun(&s->data[i]);
    }
}


//定义链式栈节点的结构体
typedef struct linkStackNode
{
    datatype data;
    struct linkStackNode *next;
}linkStackNode;

//定义链式栈的管理结构体
typedef struct linkStackManage
{
    linkStackNode *top;
    int size;
}linkStackManage;

 //初始化链式栈
static linkStackManage * linkStack_init()
{
    linkStackManage *s = (linkStackManage *) calloc(1,sizeof(linkStackManage));
    if (s!=NULL)
    {
        s->top = NULL;
        s->size = 0;
        return s;
    }
    return NULL;
}


//判断链式栈是否为空
static bool __IsLinkEmpty(linkStackManage *s)
{
    return s->top == NULL;
}

//创建新的链式栈节点
static linkStackNode * createLinkStackNode(datatype data)
{
    linkStackNode *node = (linkStackNode *) calloc(1,sizeof(linkStackNode));
    if (node!=NULL)
    {
        node->data = data;
        node->next = NULL;
        return node;
    }
    return NULL;
}


//链式栈的入栈操作
static bool linkStack_push(linkStackManage *s,linkStackNode *node)
{
    if (node==NULL||s==NULL)
    {
        printf("linkStack_push failed,node or stack is NULL\n");
        return false;
    }
    node->next = s->top;
    s->top = node;
    s->size++;      
    return true;
}

//链式栈的取栈顶操作
static bool linkStack_top(linkStackManage *s,datatype *data)
{
    if (s==NULL||__IsLinkEmpty(s))
    {
        printf("linkStack_top failed,stack is empty\n");
        return false;
    }
    *data = s->top->data;
    return true;
}

//链式栈的出栈操作
static bool linkStack_pop(linkStackManage *s,datatype *data)
{
    if (!linkStack_top(s,data))
    {
        return false;
    }
    linkStackNode *node = s->top;
    s->top = s->top->next;
    *data = node->data;
    node->next = NULL;
    free(node);
    s->size--;
    return true;
}

//遍历链式栈，并执行操作
static void linkStack_traverse(linkStackManage *s,void (*fun)(datatype *p))
{
    linkStackNode *node = s->top;
    while (node!=NULL)
    {
        fun(&node->data);
        node = node->next;
    }
}












