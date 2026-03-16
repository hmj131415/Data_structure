#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int capacity;
    int last_index;
} sequence_list;

sequence_list* sequence_list_init(int capacity) {
    sequence_list* list = (sequence_list*)malloc(sizeof(sequence_list));
    if (list == NULL)
    {
        /* code */
        return NULL;
    }
    list->data = (int*)malloc(sizeof(int) * capacity);
    if (list->data == NULL)
    {
        /* code */
        free(list);
        return NULL;
    }
    list->capacity = capacity;
    list->last_index = -1;
    return list;
}

void show_sequence_list(sequence_list* list) {
    if (list == NULL) {
        printf("Sequence list is NULL.\n");
        return;
    }
    printf("Sequence List: ");
    for (int i = 0; i <= list->last_index; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

bool isfull(sequence_list* list) {
    return list->last_index >= list->capacity - 1;
}

bool isempty(sequence_list* list) {
    return list->last_index == -1;
}

bool insert(sequence_list* list, int data ,int inserted_data) 
{
    if (isfull(list))
    {
        /* code */
        printf("Sequence list is full. Cannot insert %d.\n", data);
        return false;
    }
    //查找被插入位置的前一个元素
    int inserted_index = -1;
    if (isempty(list))
    {
        /* code */
        list->data[0] = data;
        list->last_index++;
        return true;
    }
    for (int i = 0; i <= list->last_index; i++)
    {
        /* code */
        if (list->data[i] == inserted_data)
        {
            /* code */
            //找到被插入位置的前一个元素
            inserted_index = i;
            break;
        }
    }
    if (inserted_index==-1)
    {
        /* code */
        printf("Inserted data %d not found. Cannot insert %d.\n", inserted_data, data);
        return false;
    }
    //将被插入位置的后一个元素及其后面的元素向后移动一位
    for (int i = list->last_index; i >= inserted_index; i--)
    {
        /* code */
        list->data[i+1] = list->data[i];
    }
    //在被插入位置插入新元素
    list->data[inserted_index] = data;
     list->last_index++;
    return true;
}

bool delete(sequence_list* list, int data) 
{
    if (isempty(list)) {
        printf("Sequence list is empty. Cannot delete %d.\n", data);
        return false;
    }
    int delete_index = -1;
    for (int i = 0; i <= list->last_index; i++) 
    {
        if (list->data[i] == data) 
        {
            delete_index = i;
            break;
        }
    }
    if (delete_index == -1) {
        printf("Data %d not found. Cannot delete.\n", data);
        return false;
    }
    for (int i = delete_index; i < list->last_index; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->last_index--;
    return true;
}

int main() 
{
    sequence_list* list = sequence_list_init(20);
    if (list == NULL) 
    {
        printf("Failed to initialize sequence list.\n");
        return 1;
    }
    printf("Sequence list initialized with capacity %d.\n", list->capacity);

    for(int i =0;i <=10;i++)
    {
        if (!insert(list, i, i-1)) 
        {
            printf("Failed to insert %d into sequence list.\n", i);
            show_sequence_list(list);
        }
        show_sequence_list(list);   
    }   
    for (int i = 10; i >=0; i--)
    {
        /* code */
        if (!delete(list, i)) 
        {
            printf("Failed to delete %d from sequence list.\n", i);
        }
        show_sequence_list(list);
    }
    return 0;
}