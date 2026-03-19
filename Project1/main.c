#include <stdlib.h>
#include <stdio.h>
#include "kernel_list.h"

//定义链表节点结构体
typedef struct node
{
    /* data */
    int data;
    struct list_head list;
}list_node,*linklist;

//初始化链表头结点
linklist list_init()
{
    linklist head = (linklist)malloc(sizeof(list_node));
    if (head!=NULL)
    {
        /* code */
        INIT_LIST_HEAD(&(head->list));
    }
    return head;
}
 
//生成int类型内核节点
linklist generate_int_node(int data)
{
    linklist node = (linklist)malloc(sizeof(list_node));
    if (node!=NULL)
    {
        /* code */
        node->data = data;
        INIT_LIST_HEAD(&(node->list)); 
    }
    return node;
}

//查找指定int节点
linklist find_node(linklist head,int data)
{
    linklist p;
    list_for_each_entry(p, &(head->list), list)
    {
        if (p->data==data)
        {
            return p;
        }
    }
    return NULL; 
}

//从前往后打印链表节点数据
void print_list(linklist head)
{
    struct list_head *pos;
    list_for_each(pos, &(head->list))
    {
        linklist entry = list_entry(pos,list_node,list);   
        printf("%d", entry->data);
    }
    printf("\n");
}

void node_move(linklist head,int move_data,int target_data)
{
    linklist move_node = find_node(head,move_data);
    linklist target_node = find_node(head,target_data);
    if (move_node!=NULL&&target_node!=NULL)
    {
        list_del(&(move_node->list));
        list_add(&(move_node->list), &(target_node->list));
    }
    else
    {
        printf("移动失败，未找到节点%d或节点%d\n",move_data,target_data);
    }
}

int main()
{
    //初始化内核链表头结点
    linklist head = list_init();
    if (head!=NULL)
    {
        /* code */
        printf("list_init success\n");
    }
    else
    {
        printf("list_init failed\n");
    }

    for (int i = 0; i < 10; i++)
    {
        /* code */
        linklist node = generate_int_node(i);
        //在链表头结点后面添加节点node
        // list_add(&(node->list), &(head->list));
        //在链表头结点后面添加节点node
        list_add_tail(&(node->list), &(head->list));
    }
    
    
    struct list_head *pos;

    //从前往后遍历链表，打印节点数据
    print_list(head);
    

    //删除指定循环
    /* char stop;
    int delete_data;
    printf("请输入要删除的节点数据,输入q退出：");
    while (1)
    {
        if (scanf("%c",&stop)==1&&(stop=='q'||stop=='Q'))
        {
            
            break;
        }
        else if (scanf("%d",&delete_data)==1)
        {
            
            linklist p = find_node(head,delete_data);
            if (p!=NULL)
            {
                list_del(&(p->list));
                free(p);
                print_list(head);
            }
            else
            {
                printf("删除失败，未找到节点%d\n",delete_data);
            }
        }
       
    } */
    
    //移动节点（把第一个参数移到第二个参数后面）
    node_move(head,7,1);
    print_list(head);
    return 0;
}

