#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int data;
    struct node *prev;
    struct node *next; 
}Node;

// 初始化双循环链表
Node *list_init(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("list_init: malloc failed\n");
        return NULL;
    }
    head->prev = head;
    head->next = head;
    printf("双循环链表初始化成功: head = %p\n", head);
    return head;
}


// 创建新节点
Node *create_node(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL)
    {
        printf("create_node: malloc failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->prev = newnode;
    newnode->next = newnode;
    return newnode;
}

// 头插法
void insert_Head(Node *head, Node *newnode)
{
    newnode->next = head->next;
    newnode->prev = head;
    head->next = newnode;
    newnode->next->prev = newnode;
}

// 显示链表
void show_list(Node *head)
{
    Node *p = head->next;
    while(p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 尾插法
void insert_Tail(Node *head, Node *newnode)
{
    newnode->prev = head->prev;
    newnode->next = head;
    head->prev->next = newnode;
    head->prev = newnode;
}

// 删除指定数据节点
Node *remove_Node(Node *head, int data)
{
    Node *p = head->next;
    while(p != head)
    {
        if(p->data == data)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->prev = p;
            p->next = p;
            return p;
        }
        p = p->next;
    }
    printf("未找到数据为%d的节点\n", data);
    return NULL;
}

int main(void)
{
    Node *head = list_init();
    for (int i = 0; i < 10; i++)
    {
        /* code */Node *newnode = create_node(i);
        if(newnode != NULL)
        {
            // 头插法
            insert_Head(head, newnode);
        }
        // 最终输出9 8 7 6 5 4 3 2 1 0
        show_list(head);
    }

    for (int i = 1; i < 10; i++)
    {
        /* code */
        Node *newnode = create_node(i);
        if(newnode != NULL)
        {
            // 尾插法
           insert_Tail(head, newnode);
        }
        // 最终输出9 8 7 6 5 4 3 2 1 0 1 2 3 4 5 6 7 8 9
        show_list(head);
    }
    int n;
    char ch;
    printf("输入要删除的节点，输入Q或者q退出：");
    while (1)
    {
        /* code */
        if (scanf("%d",&n)==1)
        {
            /* code */
            // 删除指定数据节点
            Node *remove = remove_Node(head,n);
            if(remove != NULL)
            {
                printf("删除节点成功: %d\n", remove->data);
                show_list(head);
            }
        }
        else if (scanf("%c",&ch)==1)
        {
            /* code */
            if(ch == 'Q' || ch == 'q')
            return 0;
        }
    }
    

    return 0;
}