#include <stdio.h>
//Linear searching
int search(int arr[], int size, int element)
{
    //Linear searching
    for (int i = 0; i <= size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
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
    int size = 7, element = 8, searchIndex;
    display(array, size);
    searchIndex = search(array, size, element);
    if (searchIndex == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("%d is at index : %d\n", element, searchIndex);
    }

    return 0;
}