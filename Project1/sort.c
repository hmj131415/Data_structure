#include "sort.h"
#include <stdio.h>

//打印数组
void print_arr(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//经典插入排序
void insertsort(int a[], int size)
{
    int com_cnt = 0;
    int move_cnt = 0;
    int i, j;
    if (size <= 1)
    {
        return;
    }
    for (i = 1; i < size; i++)
    {
        int temp = a[i];
        for (j = i-1; j >= 0; j--)
        {
            com_cnt++;
            if (temp>=a[j])
            {
                break;
            }
            else
            {
                a[j+1] = a[j];
                move_cnt++;
            }
        }
        a[j+1] = temp;
        move_cnt++;
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}