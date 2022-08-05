#include <stdio.h>
#include <stdlib.h>
//Array as an Abstract data type

struct MyArray
{ //ADT
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct MyArray *arr, int t_size, int u_size)
{
    arr->total_size = t_size;
    arr->used_size = u_size;
    arr->ptr = (int *)malloc(t_size * sizeof(int));
}

void setArray(struct MyArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter the value of array at index %d : ", i);
        scanf("%d", &(arr->ptr)[i]);
    }
}

void displayArray(struct MyArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("The value of array at index %d : %d\n", i, (arr->ptr)[i]);
    }
}
int main()
{
    struct MyArray arr;
    createArray(&arr, 7, 4);
    setArray(&arr);
    displayArray(&arr);
    return 0;
}