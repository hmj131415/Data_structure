#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[20];
    int age;
}student;
//定义链表存放数据类型为struct student
#define DATATYPE student
#include "list.h"

//定义显示学生信息的函数
void showinfo(student *structdata)
{
    printf("name = %s,age = %d\n",structdata->name,structdata->age);
    return;
}

//显示链表中整数
void showint(int *data)
{
    printf("%d\n",*data);
    return;
}

//定义判断两个学生是否相等的函数

bool equal_student(student data,student finddata)
{
    if(strcmp(data.name,finddata.name) == 0 && data.age == finddata.age)
    {
        return true;
    }
    return false;
}


bool equal_int(int data,int finddata)
{
    if(data == finddata)
    {
        return true;
    }
    return false;
}

int main()
{
    //初始化空链表
    linklist head = initlist();

    //创建学生新节点
    
    student Jack = {"Jack",18};
    student Tom = {"Tom",19};
    student Rose = {"Rose",20};
    linklist newnode1 = createnode(&Jack);
    linklist newnode2 = createnode(&Tom);
    linklist newnode3 = createnode(&Rose);
    


    //将新节点插入到链表末尾
    listaddtail(head,newnode1);
    listaddtail(head,newnode2);
    listaddtail(head,newnode3);
   

    //创建10个整数新节点
    /* for (int i = 0; i < 10; i++)
    {
        linklist newnode = createnode(&i);
        listaddtail(head,newnode);
    } */
    

    //遍历整个链表，每个节点调用showinfo函数显示信息
    listforeach(head,showinfo);

    //查找链表中的指定数据的节点
    linklist p = findnode(head,Tom,equal_student);
    if (p!=NULL)
    {
        printf("找到了\n");
    }
    else
    {
        printf("没有找到\n");
    }

    //删除指定数据的节点
    listdelnode(head,p);
    free(p);
    //遍历整个链表，每个节点调用showinfo函数显示信息
    listforeach(head,showinfo);
    
    return 0;
}