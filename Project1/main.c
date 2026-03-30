#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 1000000
#define MAX_STR_LEN 20

//顺序查找
int sequentialSearch(int arr[], int capacity, int target)
{
    int count = 0; // 计数器，记录比较次数
    for (int i = 0; i < capacity; i++)
    {
        count++;
        if (arr[i] == target)
        {
            printf("查找成功，目标值在数组中的索引为：%d\n", i);
            printf("比较次数：%d\n", count);
            return i;
        }
    }
    printf("查找失败，比较次数：%d\n", count);
    return -1;
}

//排序函数，使用快速排序算法
void quickSort(int arr[], int len)
{
    if (len <= 1)
    {
        return;
    }
    int left = 0;
    int right = len - 1;
    int temp = arr[0]; // 选择第一个元素作为基准
    while (left<right)
    {
        while (left<right && arr[right]>=temp)
            right--;
        if (left<right)
        {
            arr[left] = arr[right];
        }
        while (left<right && arr[left]<=temp)
            left++;
        if (left<right)
        {
            arr[right] = arr[left];
        }
    }
    int pivotIndex = left;
    arr[pivotIndex] = temp;
    quickSort(arr, pivotIndex);
    quickSort(arr+pivotIndex+1, len-(pivotIndex+1));
}

//二分查找
int binarySearch(int arr[], int capacity, int target)
{
    int count = 0; // 计数器，记录比较次数
    // 二分查找
    int left = 0;
    int right = capacity - 1;
    while (left <= right)
    {
        count++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            printf("查找成功，目标值在数组中的索引为：%d\n", mid);
            printf("比较次数：%d\n", count);
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("查找失败，比较次数：%d\n", count);
    return -1;
}


char *randomString(int maxLength)
{
    int length = rand() % maxLength+1; // 随机生成字符串长度，范围为1到maxLength
    char *str = (char *)calloc((length + 1),sizeof(char)); // 为字符串分配内存
    if (str == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    for (int i = 0; i < length; i++)
    {
        if(rand()%2)
        {
            str[i] = 'a' + rand() % 26; // 生成一个随机小写字母
        }
        else
        {
            str[i] = 'A' + rand() % 26; // 生成一个随机大写字母
        }
    }
    str[length] = '\0'; // 在字符串末尾添加终止符
    return str;
}

//把字符串数组中的元素写入到.txt文件中
void writeToFile(char (*arr)[MAX_STR_LEN+1], int capacity, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("无法打开文件：%s\n", filename);
        return;
    }
    for (int i = 0; i < capacity; i++)
    {
        fprintf(file, "%6d.%s\n", i, arr[i]);
    }
    fclose(file);
}

//按字母首字母创建索引
void createIndex(char strArr[][MAX_STR_LEN+1], int capacity, int **index)
{
    int n[52] = {0}; // 统计每个字母开头的字符串数 
    for (int i = 0; i < capacity; i++)
    {
        int pos = (strArr[i][0] >= 'a' && strArr[i][0] <= 'z') ? strArr[i][0] - 'a' : strArr[i][0] - 'A' + 26; // 将字母转换为索引
        n[pos]++; // 统计每个字母开头的字符串数
    }
    for (int i = 0; i < 52; i++)
    {
        index[i] = (int *)calloc(n[i]+1, sizeof(int)); // 为每个字母开头的字符串数分配内存 // 将每个字母开头的字符串数存储在索引数组的第一个元素中
    }
    for (int i = 0; i < capacity; i++)
    {
        int pos = (strArr[i][0] >= 'a' && strArr[i][0] <= 'z') ? strArr[i][0] - 'a' : strArr[i][0] - 'A' + 26; // 将字母转换为索引
        int k = ++index[pos][0];//
        index[pos][k] = i; // 将字符串在数组中的索引存储在索引数组中
    }    
}


//定义哈希表节点结构体类型
typedef struct node
{
    int data;
    struct node *next;
}hashNode;

//定义哈希表管理结构体类型
typedef struct hashTable
{
    int tableSize;
    hashNode **table_entries;
} hashTable;

//初始化哈希表
hashTable *initHashTable(int tableSize)
{
    hashTable *ht = (hashTable *)malloc(sizeof(hashTable));
    ht->tableSize = tableSize;
    ht->table_entries = (hashNode **)calloc(tableSize, sizeof(hashNode *));
    for (int i = 0; i < tableSize; i++)
    {
        ht->table_entries[i] = NULL;
    }
    return ht;
}

//创造哈希节点
hashNode *createHashNode(int data)
{
    hashNode *node = (hashNode *)malloc(sizeof(hashNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void show(hashTable *ht, unsigned long pos, int data)
{
    struct node *p;

    int i;
    for(i=0; i<ht->tableSize; i++)
    {
        p = ht->table_entries[i];

        printf("table[%d]: ", i);

        if(p != NULL)
        {
            struct node *q = p;
            while(q != NULL)
            {
                printf("%d\t", q->data);
                q = q->next;
            }
        }

        if(pos == i)
        {
            printf("\t <-- %d\n", data);
        }
        else
        {
            printf("\n");
        }
    }
}

//哈希表添加元素
void hash_add(hashTable *ht, int data)
{
    hashNode *node = createHashNode(data);
    //计算哈希值
    int hash_index = data % ht->tableSize;
      show(ht, hash_index, data);
      printf("--------------------\n");
    //如果哈希表该位置为空，直接插入
    if (ht->table_entries[hash_index]==NULL)
    {
        ht->table_entries[hash_index] = node;
        return;
    }
    //如果哈希表该位置不为空，将新节点插入到链表末尾
    hashNode *p = ht->table_entries[hash_index];
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = node;
    return;
}

//哈希表查找元素
int hashSearch(hashTable *ht, int target, hashNode **node)
{
    int hash_index = target % ht->tableSize;
    hashNode *p = ht->table_entries[hash_index];
    while (p!=NULL)
    {
        if (p->data == target)
        {
            *node = p;
            return hash_index;
        }
        p = p->next;
    }
    return -1;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int *arr = (int *)malloc(sizeof(int) * CAPACITY); // 为数组分配内存
    int *sortedArr = (int *)malloc(sizeof(int) * CAPACITY); // 为排序后的数组分配内存

    if (arr == NULL || sortedArr == NULL) 
    {
        printf("内存分配失败\n");
        return 1; // 内存分配失败，退出程序
    }
    //生成100万个随机整数，范围在0到999999之间，并将它们存储在一个数组中；
    for (int i = 0; i < CAPACITY; i++)
    {
        arr[i] = rand() % 1000000;
        sortedArr[i] = arr[i];
    }

    // 先排序
    quickSort(sortedArr, CAPACITY);
    printf("输入要查找的目标值，q退出：");
    char input[20];
    while(1)
    {
        fgets(input, sizeof(input), stdin);
        if(input[0]=='q'&& (input[1]=='\n'||input[1]=='\0'))
        {
            printf("退出程序\n");
            break;
        }
        int target;
        if(sscanf(input, "%d", &target)!=1)
        {
            printf("输入无效");
            continue;
        }
      
        int seqIndex = sequentialSearch(arr, CAPACITY, target);
        if (seqIndex!=-1)
        {
             printf("%d\n", arr[seqIndex]);
        }
        

        //二分查找
        int index = binarySearch(sortedArr, CAPACITY, target);
        if (index!=-1)
        {
            printf("%d\n", sortedArr[index]);
        }
    }
    free(arr); // 释放内存
    free(sortedArr); // 释放内存

    //生成100万个随机字符串，每个字符串长度不超过20个字符；
    char (*strArr)[MAX_STR_LEN+1] = calloc(CAPACITY, sizeof(char) * (MAX_STR_LEN+1)); // 为字符串数组分配内存
    if (strArr==NULL)
    {
        printf("内存分配失败\n");
        return 1; // 内存分配失败，退出程序
    }
    //生成随机字符串并存储在数组中
    for (int i = 0; i < CAPACITY; i++)
    {
        char *str = randomString(MAX_STR_LEN);
        if (str == NULL)
        {
            printf("内存分配失败\n");
            return 1; // 内存分配失败，退出程序
        }
        strncpy(strArr[i], str, MAX_STR_LEN+1); // 将生成的随机字符串复制到数组中
        free(str); // 释放生成的随机字符串的内存
    }
    //将字符串数组中的元素写入到.txt文件中
    writeToFile(strArr, CAPACITY, "strArr.txt");
    int **index = calloc(52, sizeof(int *)); // 定义索引数组
    createIndex(strArr, CAPACITY ,index); // 按字母首字母创建索引

    printf("输入要查找的字符串，q退出：");
    char inputStr[MAX_STR_LEN+1];
    while(1)
    {
        fgets(inputStr, sizeof(inputStr), stdin);
        if(inputStr[0]=='q'&& (inputStr[1]=='\n'||inputStr[1]=='\0'))
        {
            printf("退出程序\n");
            break;
        }
        strtok(inputStr, "\n"); // 去除输入字符串末尾的换行符
        bool done = false;
        int pos = (inputStr[0] >= 'a' && inputStr[0] <= 'z') ? inputStr[0] - 'a' : inputStr[0] - 'A' + 26; // 将字母转换为索引
        for (int i = 1; i <= index[pos][0]; i++)
        {
            if (pos < 0 || pos >= 52) // 输入的字符串首字母不合法
            {
                break;
            }
            if (strcmp(strArr[index[pos][i]], inputStr) == 0)
            {
                done = true;
                printf("查找成功，目标字符串在数组中的索引为：%d\n", index[pos][i]);
                break;
            }
        }
        if (!done)  
        {
            printf("查找失败，未找到目标字符串\n");
        }
    }
    for (int i = 0; i < 52; i++)
    {
        free(index[i]);
    }
    free(index);
    free(strArr); // 释放字符串数组的内存


    hashTable *ht = initHashTable(10);
    //哈希表实现
    for (int i = 0; i < 20; i++)
    {
        int data = rand() % 1000;
        hash_add(ht, data);
    }
    printf("哈希表实现完成，数据已插入\n");
    printf("输入你要查找的目标值，q退出：");
    char hashInput[20];
    while(1)
    {
        fgets(hashInput, sizeof(hashInput), stdin);
        if(hashInput[0]=='q'&& (hashInput[1]=='\n'||hashInput[1]=='\0'))
        {
            printf("退出程序\n");
            break;
        }
        int target;
        if(sscanf(hashInput, "%d", &target)!=1)
        {
            printf("输入无效");
            continue;
        }
        hashNode *node = NULL;
        int index = hashSearch(ht, target, &node);
        if (index!=-1)
        {
            printf("查找成功，目标值在哈希表中的索引为：%d\n", index);
            printf("%d\n", node->data);
        }
        else
        {
            printf("查找失败，未找到目标值\n");
        }
    }
}