#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {18, 1, 34, 4, 5, 7, 0, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, len - 1);

    printf("Sorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
