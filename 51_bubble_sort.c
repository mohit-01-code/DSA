#include <stdio.h>
//Bubble sort algorithm
void print_array(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubble_sort(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void bubble_sort_adaptive(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        int chk_sort = 1;
        printf("Working on pass no. %d\n", i + 1);
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                chk_sort = 0;
            }
        }
        if (chk_sort)
            return;
    }
}
int main(){
    int size = 6;
    int arr[] = {12, 10, 50, 51, 0, 5};
    int arr2[] = {0, 5, 5, 51, 12, 50};
    print_array(arr, size);
    bubble_sort(arr, size);
    print_array(arr, size);
    bubble_sort_adaptive(arr2, size);
    print_array(arr2, size);
    return 0;
}