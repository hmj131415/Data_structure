//如果没有定义DATATYPE，就定义为int
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#ifndef DATATYPE
#define DATATYPE int
#endif

//定义datatype为DATATYPE
typedef DATATYPE datatype;

//定义双循环链表节点为listnode，链表头指针为linklist
typedef struct node
{
    /* data */
    datatype data;
    struct node *next;
    struct node *prev;
}listnode,*linklist;

static linklist initlist()
{
    linklist head = (linklist)malloc(sizeof(listnode));
    if(head == NULL)
    {
        printf("malloc faile d\n");
        return NULL;
    }
    head->next = head;
    head->prev = head;
    return head;
}

//创建一个新节点
static linklist createnode(datatype *data)
{
    linklist newnode = (linklist)malloc(sizeof(listnode));
    if(newnode == NULL)
    {
        printf("malloc faile d\n");
        return NULL;
    }
    newnode->data = *data;
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

//定义将新节点插入到链表末尾的函数
static void listaddtail(linklist head,linklist newnode)
{
    newnode->prev = head->prev;
    newnode->next = head;
    head->prev->next = newnode;
    head->prev = newnode;
}

//定义遍历链表的函数，并执行回调函数
static void listforeach(linklist head,void (*func)(datatype *data))
{
    linklist p = head->next;
    while(p != head)
    {
        func(&(p->data));
        p = p->next;
    }
    return;
}

//找到指定数据的指针
static linklist findnode(linklist head,datatype data,
    bool (*equal)(datatype data,datatype finddata))
{
    linklist p = head->next;
    while(p != head)
    {
        if(equal(p->data,data))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//删除指定位置的节点
static void listdelnode(linklist head,linklist p)
{
    if (p == NULL || head == head->next)
    {
        /* code */
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->prev = p;
    p->next = p;
    return;
}
