#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 100

//遍历数组
void traverseArray(int arr[], int size,void (*func)(int))
{
    for(int i = 0; i < size; i++)
    {
        func(arr[i]);
    }
    printf("\n");
}

//打印数组元素
void printArrayElement(int d)
{
    printf("%d ", d);
}


//经典插入排序
void insertSort(int arr[], int size)
{
    int i;
    int temp;
    int com_cnt = 0;
    int move_cnt = 0;
    if (size <= 1)
    {
        return;
    }
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        int j;
        for (j = i-1; j >= 0; j--)
        {
            com_cnt++;
            if (temp>=arr[j])
            {
                break;
            }
            else
            {
                arr[j+1] = arr[j];
                move_cnt++;
            }
        }
        arr[j+1] = temp;
        move_cnt++;
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}

//查找插入位置
int findInsert(int arr[], int size, int key)
{
    int left = 0;
    int right = size-1;
    int pos = size;
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (arr[mid]>key)
        {
            pos = mid;
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return pos;
}

//二分插入排序
void binaryInsertSort(int arr[], int size)
{
    int i;
    int pos;
    for ( i = 1; i < size; i++)
    {
        pos = findInsert(arr, i, arr[i]);
        int temp = arr[i];
        for (int j = i-1; j >= pos; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[pos] = temp;
    }
}

//冒泡排序
void bubbleSort(int arr[], int size)
{
   int i,j;
   for ( i = 0; i < size-1; i++)
   {
       for ( j = 0; j < size-1-i; j++)
       {
            //比较相邻元素，若前一个大于后一个，则交换位置
           if (arr[j]>arr[j+1])
           {
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
           }
       }
   }
}

//冒泡排序优化
void bubbleSortOptimized(int arr[], int size)
{
    int i;
    int epoch = 0;
    int com_cnt = 0;
    int move_cnt = 0;
    while (1)
    {
        bool swapped = false;
        for (i = 0; i < size-1-epoch; i++)
        {
            com_cnt++;
            //比较相邻元素，若前一个大于后一个，则交换位置
            if (arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                move_cnt++;
                arr[i+1] = temp;
                move_cnt++;
                swapped = true;
            }
            else
            {
                continue;
            }
        }
        epoch++;
        if (!swapped)
        {
            break;
        }
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}

//选择排序
void selectionSort(int arr[], int size)
{
    int start;
    for (start = 0; start < size-1; start++)
    {
        int min_index = start;
        for (int i = start+1; i < size; i++)
        {
            if (arr[i]<arr[min_index])
            {
                min_index = i;
            }
        }
        if (min_index != start)
        {
            int temp = arr[start];
            arr[start] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

//交换函数
void __swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//划分函数
int partition(int arr[], int length)
{
    int i = 0;
    int j = length-1;
    if (length <= 1)
    {
       return 0;
    }
    while (i<j)
    {
        while (arr[i]<=arr[j]&&i<j)
            j--;
        __swap(&arr[i], &arr[j]);
        while (arr[i]<=arr[j]&&i<j)
            i++;
        __swap(&arr[i], &arr[j]);
    }
    return i;
}

//快速排序
void quickSort(int arr[],int size)
{
    if (size <= 1)
    {
        return;
    }
    //找出基准元素并将数组划分为两部分
    int pivot = partition(arr, size);
    quickSort(arr, pivot);
    quickSort(arr+pivot+1, size-pivot-1);
}

//希尔排序插入函数
void shell_insertSort(int arr[], int gap, int size)
{
    int i, j;
    int temp;
    for (i = gap; i < size; i+=gap)
    {
        temp = arr[i];
        for (j = i-gap; j >= 0; j-=gap)
        {
            if (temp>=arr[j])
            {
                break;
            }
            else
            {
                arr[j+gap] = arr[j];
            }
        }
        arr[j+gap] = temp;
    }
}

//希尔排序
void shellSort(int arr[], int size)
{
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = 0; i < gap; i++)
        {
            //插入排序
            //首地址 arr+i
            //增量 gap
            shell_insertSort(arr+i, gap,size-i);
        }
        
    }
    
}

int main(void)
{
    //生成无序整数数组
    srand((unsigned int)time(NULL));
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000;
    }
    //遍历数组
    traverseArray(arr, SIZE, printArrayElement);

    // //经典插入排序
    // insertSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    // //二分插入排序
    // binaryInsertSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    // //冒泡排序
    // bubbleSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    // //冒泡排序优化
    // bubbleSortOptimized(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    // //选择排序
    // selectionSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    // // //快速排序
    // quickSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    //希尔排序
    shellSort(arr, SIZE);
    traverseArray(arr, SIZE, printArrayElement);

    return 0;
}