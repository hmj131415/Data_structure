#include "seqqueue.h"

void printInt(datatype *p)
{
    printf("%d ",*p);
}
int main()
{

    /*
    //循环队列的操作

    //初始化空的循环队列
    seqQueue *queue = initSeqQueue(10);
    if (queue == NULL)
    {
        printf("初始化顺序队列失败\n");
        return -1;
    }
    printf("初始化顺序队列成功\n");

    while (1)   
    {
        printf("请输入操作：数字入队，不是数字出队，q退出\n");
        char op;
        int x;
        if (scanf("%d",&x))
        {
            //入队
            if (enQueue(queue,x))
            {
                printf("入队成功\n");
                //打印队列
                traverseSeqQueue(queue,printInt);
            }
            else
            {
                printf("入队失败\n");
                continue;
            }
            
        }
        else if (scanf("%c",&op))
        {
            if (op == 'q')
            {
                //退出
                break;
            }
            else
            {
                //出队
                int data;
                if (deQueue(queue,&data))
                {
                    printf("出队成功，出队元素为：%d\n",data);
                    //打印队列
                    traverseSeqQueue(queue,printInt);
                }
                else
                {
                    printf("出队失败\n");
                    continue;
                }
            }
        }
    }
    return 0;
    */

    //链式队列的操作

    //初始化空的链式队列
    linkQueueManage *queue = initLinkQueue();
    if (queue == NULL)
    {
        printf("初始化链式队列失败\n");
        return -1;
    }
    printf("初始化链式队列成功\n");

    printf("请输入操作：数字入队，不是数字出队，q退出\n");
    while (1)
    {
        int data;
        char op;

        //入队操作
        if (scanf("%d",&data))
        {
            
            //创建节点
            linkQueueNode *node = createLinkQueueNode(data);
            if (node!=NULL)
            {
                //入队
                if (enLinkQueue(queue,node))
                {
                    printf("入队成功\n");
                    //打印队列
                    traverseLinkQueue(queue,printInt);
                }
                else
                {
                    printf("入队失败\n");
                    continue;
                }
            }
        }
        else if (scanf("%c",&op))
        {
            //退出循环
            if (op=='q'||op=='Q')
            {
                break;
            }
            else
            {
                //出队
                int data;
                if (deLinkQueue(queue,&data))
                {
                    printf("出队成功，出队元素为：%d\n",data);
                    //打印队列
                    traverseLinkQueue(queue,printInt);
                }
                else
                {
                    printf("出队失败\n");
                    continue;
                }
            }
        }
        
        
    }

        
        
    
    
    

}
