#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256  // Assuming ASCII character set

// Function to check if two words are anagrams
int areAnagrams(char word1[], char word2[]) {
    // If lengths of words are not the same, they cannot be anagrams
    if (strlen(word1) != strlen(word2)) {
        return 0;
    }

    // Arrays to store character counts of both words
    int count1[MAX] = {0}, count2[MAX] = {0};
    int i;

    // Convert to lowercase and count frequencies of each character in both words
    for (i = 0; word1[i] && word2[i]; i++) {
        count1[tolower(word1[i])]++;  // Count characters in word1
        count2[tolower(word2[i])]++;  // Count characters in word2
    }

    // Compare the frequency counts for both words
    for (i = 0; i < MAX; i++) {
        if (count1[i] != count2[i]) {
            return 0;  // Not anagrams
        }
    }

    return 1;  // Words are anagrams
}

int main() {
    char word1[100], word2[100];

    // Input the two words
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    // Check if the words are anagrams
    if (areAnagrams(word1, word2)) {
        printf("The words '%s' and '%s' are anagrams.\n", word1, word2);
    } else {
        printf("The words '%s' and '%s' are not anagrams.\n", word1, word2);
    }

    return 0;
}
