#include <stdio.h>
//Count Sort Algorithm
void print_array(int *arr, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void count_sort(int *A, int size){
    int max = A[0];
    for (int i = 0; i < size; i++){
        if (max < A[i])
            max = A[i];
    }
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < size; i++)
        count[A[i]]++;
    for (int i = 0, j = 0; i <= max; i++){
        while (count[i] != 0){
            A[j] = i;
            count[i]--;
            j++;
        }
    }
}
int main()
{
    int A[] = {12, 4, 1, 6, 9, 15, 2, 6, 18, 13};
    int size = 10;
    print_array(A, size);
    count_sort(A, size);
    print_array(A, size);
    return 0;
}