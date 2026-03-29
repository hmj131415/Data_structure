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
    
    int i,j;
    int com_cnt = 0;
    int move_cnt = 0;
    //从第二个元素开始，依次将每个元素插入到前面已经排序好的部分中
    for (i = 1; i < size; i++)
    {
        int temp = arr[i];
        //从已经排序好的部分的最后一个元素开始，依次比较每个元素与temp的大小
        for (j = i-1; j >= 0; j--)
        {
            com_cnt++;
            if (temp>=arr[j])
            {
                break;
            }
            else
            {
                move_cnt++;
                arr[j+1] = arr[j];
            }
        }
        arr[j+1] = temp;
        move_cnt++;
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}

//查找插入位置
int findInsert(int arr[], int len, int key, int *com_cnt)
{
    if (len<1)
    {
        return 0;
    }
    int left = 0;
    int right = len-1;
    int pos = len;
    while (left<=right)
    {
        *com_cnt += 1;
        int mid = left+(right-left)/2;
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
    if (size<=1)
    {
        return;
    }
    
    int i,j;
    int com_cnt = 0;    
    int move_cnt = 0;
    //从第二个元素开始，依次将每个元素插入到前面已经排序好的部分中
    for (i = 1; i < size; i++)
    {
        int temp = arr[i];
        //在已经排序好的部分中，使用二分查找找到temp的插入位置
        int pos = findInsert(arr, i, temp, &com_cnt);
        //将temp插入到已经排序好的部分中
        for (j = i-1; j >= pos; j--)
        {
            move_cnt++;
            arr[j+1] = arr[j];
        }
        arr[pos] = temp;
        move_cnt++;
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}
    
//交换函数
void __swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


//冒泡排序
void bubbleSort(int arr[], int size)
{
    if (size<=1)
    {
        return;
    }
   int i,j;
   int com_cnt = 0;
   int move_cnt = 0;
   //每一轮冒泡排序，将最大的元素冒泡到数组的末尾
   for (i = 0; i < size-1; i++)
   {
        //每一轮冒泡排序，下一次冒泡排序的范围就是当前冒泡排序的范围减一
         for (j = 0; j < size-1-i; j++)
         {
             com_cnt++;
             //比较相邻元素，若前一个大于后一个，则交换位置
             if (arr[j]>arr[j+1])
             {
                 __swap(&arr[j], &arr[j+1]);
                 move_cnt += 3;
             }
         }
   }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}

//冒泡排序优化
void bubbleSortOptimized(int arr[], int size)
{
    if (size<=1)
    {
        return;
    }
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
                __swap(&arr[i], &arr[i+1]);
                move_cnt += 3;
                swapped = true;
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
    if (size<=1)
    {
        return;
    }
    int start;
    int com_cnt = 0;
    int move_cnt = 0;
    for (start = 0; start < size-1; start++)
    {
        int min_index = start;
        for (int i = start+1; i < size; i++)
        {
            com_cnt++;
            if (arr[i]<arr[min_index])
            {
                min_index = i;
            }
        }
        if (min_index != start)
        {
            __swap(&arr[start], &arr[min_index]);
            move_cnt += 3;
        }
    }
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
}



//划分函数
int partition(int arr[], int size, int *com_cnt, int *move_cnt)
{
    int tepm = arr[0];
    int right = size-1, left = 0;
    while (left<right)
    {
        while (arr[right]>=tepm&&left<right)
        {
            *com_cnt += 1;
            right--;
        }
        arr[left] = arr[right];
        *move_cnt += 1;
        while (arr[left]<=tepm&&left<right)
        {
            *com_cnt += 1;
            left++;
        }
        arr[right] = arr[left];
        *move_cnt += 1;
    }
    arr[left] = tepm;
    *move_cnt += 1;
    return left;
}



//快速排序
void quickSort(int arr[], int size, int *com_cnt, int *move_cnt)
{
    if (size<=1)
    {
        return;
    }
    int pivot = partition(arr, size,com_cnt,move_cnt);
    quickSort(arr, pivot,com_cnt, move_cnt);
    quickSort(arr + pivot + 1, size - (pivot + 1), com_cnt, move_cnt);
}

//快速排序计次
void quickSortCount(int arr[], int size)
{
    int com_cnt = 0;
    int move_cnt = 0;
    if (size<=1)
    {
        return;
    }
    quickSort(arr, size,&com_cnt,&move_cnt);
    printf("com_cnt = %d, move_cnt = %d\n", com_cnt, move_cnt);
    return;
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
    if (size<=1)
    {
        return;
    }
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
    // srand((unsigned int)time(NULL));
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

    // //快速排序
    // quickSortCount(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);



    // //希尔排序
    // shellSort(arr, SIZE);
    // traverseArray(arr, SIZE, printArrayElement);

    return 0;
}