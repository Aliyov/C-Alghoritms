#include <stdio.h>

// Function to shift all zeroes to the right
void shiftZerosToRight(int arr[], int len) {
    int nonZeroIndex = 0;

    // Traverse the array and move all non-zero elements to the front
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    // Fill the rest of the array with zeros
    while (nonZeroIndex < len) {
        arr[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
}

int main() {
    int arr[] = {0, 15, 5, 0, 25, 0, 0, 5, 15, 10};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Shift all zeroes to the right
    shiftZerosToRight(arr, len);

    // Print the modified array
    printf("Array after shifting zeroes to the right: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
