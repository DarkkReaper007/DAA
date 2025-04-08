//bottom up
#include<stdio.h>

void heapifyDown(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapifyDown(arr, n, largest);
    }

    
}

void buildHeap(int arr[], int n){
    for(int i= (n/2) - 1; i>=0; i--){
        heapifyDown(arr, n, i);
    }
}
void heapsort(int arr[], int n){
    buildHeap(arr, n);

    for(int i=n-1; i>= 1; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapifyDown(arr, i ,0);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] =  {5,3,8,4,1,2};
    int n = sizeof(arr)/ sizeof(arr[0]);

    printf("Original array\n");
    printfArray(arr, n);

    heapsort(arr, n);

    printf("Sorted array using heap sort");
    printArray(arr, n);

    return 0;
}