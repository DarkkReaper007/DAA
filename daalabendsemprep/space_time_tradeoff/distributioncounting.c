#include<stdio.h>
#define MAX 100
void distributionCountingSort(int arr[], int n, int maxVal){
    int count[MAX] = {0};
    int output[n];

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=1; i<= maxVal; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {4,2,2,8,3,3,1};

    int n =sizeof(arr) / sizeof(arr[0]);
    int maxVal = 8;

    printf("Original array");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    distributionCountingSort(arr, n, maxVal);

    printf("\nSorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}