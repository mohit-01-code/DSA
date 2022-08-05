#include <stdio.h>
//Deletion in an Array
void deletion(int arr[], int size, int index)
{
    for (int i = index; i <= size; i++)
    {
        arr[index] = arr[index + 1];
        index++;
    }
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
    int array[100] = {12, 2, 4, 16, 8, 90, 40};
    int size = 7, index = 4;
    display(array, size);
    deletion(array, size, index);
    size -= 1;
    display(array, size);
    return 0;
}