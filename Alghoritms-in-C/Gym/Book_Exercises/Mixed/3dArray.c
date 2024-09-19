#include <stdio.h>

int main() {
    int x, y, z;

    // Dimensions of the 3D array
    printf("Enter dimensions (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    int array[x][y][z];  // Declare 3D array

    // Input integers from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("Element at [%d][%d][%d]: ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    // Print the array
    printf("\nThe 3D array is:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                printf("Element at [%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
            }
        }
    }

    return 0;
}
