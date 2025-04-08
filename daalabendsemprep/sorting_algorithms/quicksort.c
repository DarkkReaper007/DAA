#include <stdio.h>

// Function to swap two elements
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int j = partition(arr, low, high);
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}


// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

