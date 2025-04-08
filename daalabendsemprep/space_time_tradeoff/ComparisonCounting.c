#include<stdio.h>

void comparisonCountingSort(int arr[], int n){
    int count[n];
    int sorted[n];

    for(int i=0; i<n; i++){
        count[i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j] < arr[i] ||(arr[j] == arr[i] && j<i)){
                count[i]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        sorted[count[i]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = sorted[i];
    }
}
int main(){
    int arr[] = {5,2,9,1,5,6};
    int n =sizeof(arr) / sizeof(arr[0]);

    printf("Original array:");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);

    }
    comparisonCountingSort(arr, n);

    printf("\nSorted array\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}