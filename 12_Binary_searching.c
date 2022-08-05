#include <stdio.h>
//Binary searching
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int arr[], int size, int element)
{
    //Binary searching
    int low = 0, high = size - 1, mid;

    while (high != low)
    {
        if (arr[low] == element)
        {
            return low;
        }
        if (arr[high] == element)
        {
            return high;
        }
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
            // high--;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
            // low++;
        }
    }
    return -1;
}
int main()
{
    int array[100] = {4, 5, 12, 90, 100, 101, 120};
    int size = 7, element = 101, searchIndex;
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