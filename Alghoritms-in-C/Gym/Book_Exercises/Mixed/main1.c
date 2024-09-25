#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to evaluate a mathematical expression
int evaluate(char *expression) {
    int len = strlen(expression);
    int num1 = 0, num2 = 0;
    char op = 0;
    int i = 0;

    // Read the first number
    while (i < len && isdigit(expression[i])) {
        num1 = num1 * 10 + (expression[i] - '0');
        i++;
    }

    // Read the operator
    if (i < len) {
        op = expression[i];
        i++;
    }

    // Read the second number
    while (i < len && isdigit(expression[i])) {
        num2 = num2 * 10 + (expression[i] - '0');
        i++;
    }

    // Perform the operation
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 ? num1 / num2 : 0; // Handle division by zero
        default: return 0;
    }
}

// Recursive function to generate all permutations and evaluate them
void generate(char arr[], char current[], int mark[], int n, int pos, int target) {
    if (pos >= n) {
        current[pos] = '\0'; // Null-terminate the current permutation
        int result = evaluate(current);
        if (result == target) {
            printf("Expression: %s = %d\n", current, result);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            mark[i] = 1;
            current[pos] = arr[i];
            generate(arr, current, mark, n, pos + 1, target);
            mark[i] = 0;
        }
    }
}

int main() {
    char arr[] = {'4', '1', '*', '2', '+'};
    int size = sizeof(arr) / sizeof(arr[0]);

    char current[size + 1]; // +1 for null-terminator
    int mark[size];
    memset(mark, 0, sizeof(mark));

    int target = 12;
    generate(arr, current, mark, size, 0, target);

    return 0;
}
