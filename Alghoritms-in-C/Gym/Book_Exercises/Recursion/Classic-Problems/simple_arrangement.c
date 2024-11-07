#include <stdio.h>
#include <stdlib.h>

int arrange(int arr[], int size, int solution[], int k, int pos, int count) {
    // Base case: If we have selected k elements, print the solution
    if (count == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return 1; // One valid arrangement
    }

    // Recursive case: Try to select remaining elements
    int total = 0;
    for (int i = pos; i < size; i++) {
        solution[count] = arr[i];  // Choose the element
        total += arrange(arr, size, solution, k, i + 1, count + 1); // Recurse
    }

    return total;
}

int main() {
    int arr[] = {4, 9, 1, 0}; // Correct array declaration
    int size = 4;             // The correct size of the array
    int k = 2;                // How many elements to select in each arrangement
    int solution[2];          // Array to hold the current arrangement
    int total = 0;

    total = arrange(arr, size, solution, k, 0, 0);

    printf("\nTotal arrangements: %d\n", total);
    return 0;
}
