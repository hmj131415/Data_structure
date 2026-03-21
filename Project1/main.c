#include <stdio.h>

#define DATA_TYPE int  
//顺序栈的操作
#include "Stack.h"

//打印栈
void printStack(datatype *p)
{
    printf("%d ",*p);
}

int main()
{
    //顺序栈的操作
    /*
    //初始化顺序空栈
    seqStack *s = seqStack_init(10);
    if (s == NULL)
    {
        printf("seqStack_init failed\n");
        return -1;
    }
    else
        printf("seqStack_init success\n");

    //入栈并打印栈
    for (int i = 0; i < 10; i++)
    {
        seqStack_push(s,i);
        //打印栈顶
        datatype top;
        seqStack_top(s,&top);
        printf("top data = %d\n",top);
        seqStack_traverse(s,printStack);
        printf("\n");
    }



    //出栈并打印栈
    for (int i = 0; i < 10; i++)
    {
        datatype data;
        seqStack_pop(s,&data);
        printf("pop data = %d\n",data);
        seqStack_traverse(s,printStack);
        printf("\n");
    }
    
    return 0;
    */

    //链式栈的操作

    //初始化空的链式栈
    linkStackManage *s = linkStack_init();
    if (s == NULL)
    {
        printf("linkStack_init failed\n");
        return -1;
    }
    else
        printf("linkStack_init success\n");

    //链式栈的入栈
    for (int i = 0; i < 10; i++)
    {
        linkStackNode *node = createLinkStackNode(i);
        linkStack_push(s,node);
        //打印栈顶
        datatype top;
        linkStack_top(s,&top);
        printf("top data = %d\n",top);
        linkStack_traverse(s,printStack);
        printf("\n");
    }
    
    //链式栈的出栈
    for (int i = 0; i < 10; i++)
    {
        datatype data;
        linkStack_pop(s,&data);
        printf("pop data = %d\n",data);
        linkStack_traverse(s,printStack);
        printf("\n");
    }
   }
