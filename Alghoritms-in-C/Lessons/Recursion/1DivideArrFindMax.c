#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function prototypes
void mergeSort(int arr[], int lb, int rb);
void merge(int arr[], int lb, int mid, int rb);
void printArr(int arr[], int len);

void mergeSort(int arr[], int lb, int rb) {
    if (lb >= rb) {
        return;
    }
    int mid = (lb + rb) / 2;

    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, rb);
    merge(arr, lb, mid, rb);
}

void merge(int arr[], int lb, int mid, int rb) {
    int size = rb - lb + 1;
    int *b = (int *)malloc(size * sizeof(int)); // Correct allocation size
    if (b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int i = lb;
    int j = mid + 1;
    int k = 0; // Use a separate index for the temporary array

    while (i <= mid && j <= rb) {
        if (arr[i] <= arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= rb) {
        b[k++] = arr[j++];
    }

    // Copy the sorted elements back into the original array
    for (int m = 0; m < size; m++) {
        arr[lb + m] = b[m];
    }

    free(b); // Free the allocated memory
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Add newline for better formatting
}

int main() {
    int arr[] = {2, 3, 6, 1, 8, 0, 7, 4};
    int len = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, len - 1);
    printf("Sorted array: ");
    printArr(arr, len);
    return 0;
}
