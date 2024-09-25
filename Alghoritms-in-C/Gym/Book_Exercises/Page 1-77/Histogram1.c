#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 5, 10, 12, 20, 30, 40, 50, 60, 62, 64, 68, 70, 80, 90, 98};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i, flag, val;
    int classes[10] = {0};  // Initialize classes array with size 10 (since there are 10 classes: 0-9, 10-19, etc.)
    
    // Start checking from the first value
    val = 0;
    
    // Boundary condition: checking if the first element is less than 0 or greater than 100
    if (arr[val] < 0 || arr[val] >= 100) {
        flag = 0;  // Invalid range
    } else {
        // Increment the class counter for the respective range (arr[i] / 10)
        for (i = 0; i < len; i++) {
            if (arr[i] >= 0 && arr[i] < 100) {
                classes[arr[i] / 10]++;
            }
        }
        
        // Debugging output: print the count of numbers in each range of 10s
        for (i = 0; i < 10; i++) {
            printf("Class %d-%d: %d numbers\n", i * 10, i * 10 + 9, classes[i]);
        }
    }

    return 0;
}
