#include <stdio.h>

int main(){
    int v1[] = {1, 2, 3, 4, 5};  // Main array
    int v2[] = {2, 3};           // Subarray to search
    int lenv1 = sizeof(v1) / sizeof(v1[0]);  // Length of v1
    int lenv2 = sizeof(v2) / sizeof(v2[0]);  // Length of v2
    int i, j, flag;
    int overlapping = 1;  // Set to 0 for non-overlapping, 1 for overlapping
    
    i = 0;

    printf("\nLenght v1: %d",lenv1);
    printf("\nLenght v2: %d",lenv2);
    while (i <= lenv1 - lenv2) {
        j = 0;
        flag = 1;
        
        // Check if subarray matches starting at index i
        while (j < lenv2 && flag == 1) {
            if (v1[i + j] != v2[j]) {
                flag = 0;
            }
            j++;
        }

        // If the subarray is found
        if (flag == 1) {
            printf("\nSubsequence found at: %d", i);
            
            // Increment i for overlapping or non-overlapping
            if (overlapping == 0) {
                i = i + lenv2;  // Skip the length of the subarray
            } else {
                i++;  // Allow overlapping by moving to the next element
            }
        } else {
            i++;  // Move to the next element
        }
    }

    return 0;
}
