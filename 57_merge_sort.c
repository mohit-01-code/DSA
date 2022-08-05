#include <stdio.h>
//Merge Sort Algorithm
void print_array(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void merge(int *A, int low, int mid, int high){
    int temp[high + 1];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            temp[k] = A[i];
            i++;
            k++;
        }
        else{
            temp[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        temp[k] = A[i];
        i++;
        k++;
    }
    while (j <= high){
        temp[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
        A[i] = temp[i];
}
void merge_sort(int *A, int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}
int main(){
    int A[] = {12, 4, 1, 6, 9, 15, 2, 6, 18, 13};
    int size = 10;
    print_array(A, size);
    merge_sort(A, 0, size - 1);
    print_array(A, size);
    return 0;
}