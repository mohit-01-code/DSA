#include <stdio.h>
//Insertion in an array

void insertion_1(int arr[], int size, int element, int index)
{
    //Insertion for unsorted array
    arr[size] = arr[index];
    arr[index] = element;
}

void insertion_2(int arr[], int size, int element, int index)
{
    //Insertion for sorted array
    for (int i = size - 1; i >= index; i--)
    {
        arr[size] = arr[size - 1];
        size -= 1;
    }
    arr[index] = element;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int array_1[100] = {4, 10, 2, 3, 16, 4};
    int size = 6, element = 12, index = 4;
    display(array_1, size);
    insertion_1(array_1, size, element, index);
    size += 1;
    display(array_1, size);
    printf("\n");

    int array_2[50] = {4, 10, 11, 16, 120, 240};
    size = 6, element = 15, index = 3;
    display(array_2, size);
    insertion_2(array_2, size, element, index);
    size += 1;
    display(array_2, size);

    return 0;
}