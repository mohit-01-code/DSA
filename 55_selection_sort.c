#include <stdio.h>
//Selection Sort Algorithm
void print_array(int *A, int size){
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void selection_sort(int *A, int size){
    for (int i = 0, k; i < size - 1; i++){
        int minimum = A[i];
        for (int j = i; j < size - 1; j++){
            if (minimum > A[j + 1]){
                minimum = A[j + 1];
                k = j + 1;
            }
        }
        int temp = A[i];
        A[i] = minimum;
        A[k] = temp;
    }
}
int main(){
    int A[] = {5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
    int size = 10;
    print_array(A, size);
    selection_sort(A, size);
    print_array(A, size);
    return 0;
}