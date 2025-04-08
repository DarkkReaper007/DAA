void merge(int arr[], int left[], int n1, int right[], int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1) {
        arr[k++] = left[i++];   
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
}
void mergeSort(int arr[], int n) {
    if (n < 2) return;
    int mid = n / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((n - mid) * sizeof(int));
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
    free(left);
    free(right);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
