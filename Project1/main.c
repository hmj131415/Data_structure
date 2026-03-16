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
    head->next = NULL;
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
    new_node->next = NULL;
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
Node *delete_node(Node *list,int data)
{
    Node *p=list;
    Node *temp  = NULL;
    for ( p; p!=NULL;p=p->next)
    {
        /* code */
        if (p->next!=NULL&&p->next->data==data)
        {
            /* code */
            temp = p->next;
            p->next = p->next->next;
            temp->next = NULL; 
            break;
        }
    }
    return temp;
}

void show_list(Node* head)
{
    Node* p = head->next;
    for (;p!=NULL; p=p->next)
    {
        /* code */
        printf("%d ", p->data);
    }
    printf("\n");
}

int main() 
{
    Node* head = initList();
    for (int i = 0; i < MAX_SIZE; i++)
    {
        /* code */
        Node* new_node = creat_new_node(i);
        insert_node(head, creat_new_node(i));
        show_list(head);
    }
    for (int i = MAX_SIZE-1; i>=0; i--)
    {
        /* code */
        Node *p = delete_node(head,i);
        if (p==NULL)
        {
            /* code */
            printf("链表中没有要删除的数据");
            continue;
        }
        free(p);
        show_list(head);
    }
    return 0;
}

