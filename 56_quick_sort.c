#include <stdio.h>
//Quick Sort Algorithm
void print_array(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1, j = high;
    int temp;
    do{
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quick_sort(int arr[], int low, int high){
    if (low < high){
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}
int main(){
    int A[] = {1, 2, 3, 9, 4, 4, 8, 7, 5, 6};
    int size = 10;
    print_array(A, size);
    quick_sort(A, 0, 9);
    print_array(A, size);
    return 0;
}