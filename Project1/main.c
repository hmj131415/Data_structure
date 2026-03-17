#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 20

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* initList() 
{
    Node* head = (Node*)malloc(sizeof(Node));
    if (head==NULL)
    {
        /* code */
        printf("Memory allocation failed\n");
        return NULL;
    }
    head->next = head;
    return head;
}



//创建新节点
Node* creat_new_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node==NULL)
    {
        /* code */
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

//在头节点后面增加节点
void insert_node(Node* head,Node* new_node)
{
    new_node->next = head->next;
    head->next = new_node;
    return;
}

//剔除指定节点
Node *delete_node(Node *head,int data)
{
    //找到要删除结点的上一个结点指针
    Node *temp = head;
    for (; temp->next!=head;temp=temp->next)
    {
        /* code */
        if (temp->next->data == data)
        {
            /* code */
            Node *index = temp->next;
            temp->next = index->next;
            index->next = index;
            return index;
        }
    }
    return NULL;
}

void show_list(Node* head)
{
    Node* p = head->next;
    for (;p!=head; p=p->next)
    {
        /* code */
        printf("%d ", p->data);
    }
    printf("\n");
}

//销毁链表
Node *destroy(Node *head)
{
    if (head==NULL)
    {
        /* code */
        return NULL;
    }
    while (head->next!=head)
    {
        /* code */
        Node *temp = head->next;
        head->next = head->next->next;
        free(temp);
    }
    free(head);
    return NULL;
}

int main() 
{
    Node* head = initList();
    for (int i = 0; i < MAX_SIZE; i++)
    {
        /* code */
        Node* new_node = creat_new_node(i);
        insert_node(head, new_node);
        show_list(head);
    }

    // for (int i = MAX_SIZE-1; i>=0; i--)
    // {
    //     /* code */
    //     Node *p = delete_node(head,i);
    //     if (p==NULL)
    //     {
    //         /* code */
    //         printf("链表中没有要删除的数据");
    //         continue;
    //     }
    //     free(p);
    //     show_list(head);
    // }
    head = destroy(head);
    return 0;
}