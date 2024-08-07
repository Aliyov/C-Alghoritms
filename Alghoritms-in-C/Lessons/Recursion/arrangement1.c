#include <stdio.h>
#include <stdlib.h>

#define NUM_VOWELS 5
#define STRING_LENGTH 2

// Function to generate combinations with repetitions
int generate_combinations_with_reps(char *val, char *sol, int *mark, int n, int k, int count, int pos) {
    int i;

    if (pos >= k) {
        for (i = 0; i < k; i++) {
            printf("%c", sol[i]);
        }
        printf("\n");
        return count + 1;
    }

    for (i = 0; i < n; i++) {
        if(mark[i] == 0){
            mark[i] == 1;
            sol[pos] = val[i];
            count = generate_combinations_with_reps(val, sol, mark, n, k, count, pos + 1);
            mark[i] = 0;
        }
    }

    return count;
}

int main() {
    char vowels[NUM_VOWELS] = {'A', 'E', 'I', 'O', 'U'};
    int mark[NUM_VOWELS] = {0};
    char current_combination[STRING_LENGTH];
    int total_combinations;

    // Generate combinations with repetitions allowed
    total_combinations = generate_combinations_with_reps(vowels, current_combination,mark, NUM_VOWELS, STRING_LENGTH, 0, 0);

    printf("Total number of combinations: %d\n", total_combinations);

    return 0;
}
