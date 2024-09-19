#include <stdio.h>

// Function to remove all zeros from the array
int removeZeros(int arr[], int len) {
    int newLen = 0;

    // Traverse the array
    for (int i = 0; i < len; i++) {
        // If the current element is not zero, move it to the front
        if (arr[i] != 0) {
            arr[newLen] = arr[i];
            newLen++;  // Increment the count of non-zero elements
        }
    }

    return newLen;  // Return the new length of the array (ignoring zeros)
}

int main() {
    int arr[] = {0, 15, 5, 0, 25, 0, 0, 5, 15, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Remove all zeros from the array
    int newLen = removeZeros(arr, len);

    // Print the modified array
    printf("Array after removing zeros: ");
    for (int i = 0; i < newLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
