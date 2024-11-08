#include <stdio.h>

void permutateWithRepetition(char *arr, char *solution, int n, int m, int pos) {
    if (pos >= m) {
        for (int i = 0; i < m; i++) {
            printf("%c ", solution[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        solution[pos] = arr[i];
        permutateWithRepetition(arr, solution, n, m, pos + 1);
    }
}

int main() {
    char arr[] = {'A', 'B', 'C', 'D'};
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of elements in arr
    int m = 3;                             // Desired length of each permutation
    char solution[m];                      // Array to hold one permutation

    permutateWithRepetition(arr, solution, n, m, 0);

    return 0;
}
