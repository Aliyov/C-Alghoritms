#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANAGRAMS 3628800  // 10! (maximum number of distinct anagrams for 10 characters)

// Swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Sort the array of strings to help identify duplicates
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Recursive function to generate all anagrams
void generateAnagrams(char *str, int start, int end, char **results, int *count) {
    if (start == end) {
        results[*count] = strdup(str);  // Store the anagram
        (*count)++;
    } else {
        for (int i = start; i <= end; i++) {
            swap((str + start), (str + i));       // Swap characters
            generateAnagrams(str, start + 1, end, results, count); // Recurse
            swap((str + start), (str + i));       // Backtrack to original configuration
        }
    }
}

int main() {
    char str[11];
    printf("Enter a string (max 10 characters): ");
    scanf("%10s", str);

    int n = strlen(str);
    char *results[MAX_ANAGRAMS];
    int count = 0;

    // Generate all possible anagrams (with duplicates)
    generateAnagrams(str, 0, n - 1, results, &count);

    // Sort and print distinct anagrams
    qsort(results, count, sizeof(char *), compare);
    printf("Distinct anagrams:\n");

    for (int i = 0; i < count; i++) {
        if (i == 0 || strcmp(results[i], results[i - 1]) != 0) {
            printf("%s\n", results[i]); // Print only if distinct from the previous
        }
        free(results[i]); // Free each result
    }

    return 0;
}

