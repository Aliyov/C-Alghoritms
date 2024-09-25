#include <stdio.h>
#include <stdlib.h>

void generate_combinations(char arr[], char current[], int n, int k, int start, int pos) {
    if (pos >= k) {
        for (int i = 0; i < k; i++) {
            printf("%c ", current[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++) {
        current[pos] = arr[i];
        generate_combinations(arr, current, n, k, i + 1, pos + 1);
    }
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int size = sizeof(arr) / sizeof(arr[0]);

    char current[3];
    
    generate_combinations(arr, current, size, 3, 0, 0);

    return 0;
}

