#include <stdio.h>
//Insertion Sort Algorithm
void print_array(int *A, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void insertion_sort(int *A, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j > 0; j--){
            if (A[j] < A[j - 1]){
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}
int main(){
    int A[] = {5, 4, 3, 2, 1};
    int size = 5;
    print_array(A, size);
    insertion_sort(A, size);
    print_array(A, size);
    return 0;
}