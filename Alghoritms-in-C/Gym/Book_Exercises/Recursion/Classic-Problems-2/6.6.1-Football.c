#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATCHES 100
#define MAX_RESULTS 10

int readMatches(char *filename, char matches[MAX_MATCHES][MAX_RESULTS]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int numMatches = 0;
    while (fgets(matches[numMatches], MAX_RESULTS, file)) {
        matches[numMatches][strcspn(matches[numMatches], "\n")] = '\0';
        numMatches++;
    }
    fclose(file);
    return numMatches;
}

void generateCombinations(char matches[MAX_MATCHES][MAX_RESULTS], char *current, int matchIndex, int numMatches) {
    if (matchIndex == numMatches) {
        printf("%s\n", current);
        return;
    }

    for (int i = 0; matches[matchIndex][i] != '\0'; i++) {
        current[matchIndex] = matches[matchIndex][i];  
        generateCombinations(matches, current, matchIndex + 1, numMatches); 
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    char matches[MAX_MATCHES][MAX_RESULTS];
    int numMatches = readMatches(filename, matches);

    char current[MAX_MATCHES + 1];
    current[numMatches] = '\0';

    
    generateCombinations(matches, current, 0, numMatches);

    return 0;
}
