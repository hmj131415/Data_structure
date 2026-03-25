#include "BST.h"

#define TREENODE BSTNode
#include "drawtree.h"

int main()
{
    BSTNode *root = BST_init();
    int n;
    char op;
    printf("请输入操作：正数表示插入，负数表示删除，字母Q或q表示退出\n");
    while (1)
    {
        if (scanf("%d", &n))
        {
            //插入节点
            if (n>=0)
            {
                BSTNode *newnode = createBSTNode(n);
                root = insertBSTNode(root, newnode);
            }
            //删除节点
            else
            {
                root = deleteBSTNode(root, -n);
            }
        }
        else if (scanf("%c", &op) == 1&&(op == 'Q' || op == 'q'))
        {
            printf("退出\n");
            break;
        }
        //绘制BST树
        draw(root);
    }
    return 0;
}