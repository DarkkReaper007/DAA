#include<stdio.h>
#include<stdlib.h>

void insertionsort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int j = i;
        while( j >0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;

            j = j - 1;
        }
    }
}
void printArray(int A[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int A[] = {12, 11, 13, 5, 6};
    int length = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, length);

    insertionsort(A, length);

    printf("Sorted array: ");
    printArray(A, length);

    return 0;
}