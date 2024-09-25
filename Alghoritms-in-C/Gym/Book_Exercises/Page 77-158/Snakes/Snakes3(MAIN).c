//Here i did not free the dynamic allocation

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // Include for malloc
#include <limits.h>

#define MAX_SIZE 20

typedef struct{
    int visited;
    char value;
} element_t;

element_t **malloc2d(int r, int c) {
    element_t **map;
    map = (element_t **)malloc(r * sizeof(element_t *));
    for (int i = 0; i < r; i++) {
        map[i] = (element_t *)malloc(c * sizeof(element_t));
    }
    return map;
}

void map_read(char *filename, element_t ***mapP, int *nr, int *nc) {
    element_t **map;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("\nCan't open the filename");
        return;
    }

    fscanf(fp, "%d %d", nr, nc);

    map = malloc2d(*nr, *nc);

    for (int i = 0; i < *nr; i++) {
        for (int j = 0; j < *nc; j++) {
            if (fscanf(fp, " %c", &map[i][j].value) != EOF) {
                map[i][j].visited = 0;
            }
        }
    }

    fclose(fp);
    *mapP = map;
}


int length_determination(element_t **map, int rowSize, int colSize, int findedRow, int findedCol) {
    int end = 0;
    int found = 0;
    int r_new = 0;
    int c_new = 0;
    int length = 0;
    
    while (!end) {
        found = 0;
        for (int i = findedRow - 1; i <= findedRow + 1 && found == 0; i++) {
            for (int j = findedCol - 1; j <= findedCol + 1 && found == 0; j++) {
                if (i >= 0 && i < rowSize && j >= 0 && j < colSize) {
                    if (map[i][j].value == '*' && !map[i][j].visited) {
                        found = 1;
                        r_new = i;
                        c_new = j;      
                    }
                }
            }
        }
        if (found) {
            length++;
            findedRow = r_new;
            findedCol = c_new;
            map[findedRow][findedCol].visited = 1;
        } else {
            end = 1;
        }
    }
    return length;
}

int main() {
    element_t **map;
    char filename[MAX_SIZE];

    int R, C;
    int nSnake = 0;
    int length = 0;
    int maxLen = 0;
    int minLen = INT_MAX;

    printf("\nEnter filename: ");
    scanf("%s", filename);

    map_read(filename, &map, &R, &C);
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j].value == '+') {
                nSnake++;
                length = length_determination(map, R, C, i, j);
                if (length > maxLen) {
                    maxLen = length;
                }
                if (length < minLen) {
                    minLen = length;
                }
            }
        }
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < R; i++) {
        free(map[i]);
    }
    free(map);

    printf("\nNumber of snakes: %d", nSnake);
    printf("\nMaximum length of snake: %d", maxLen);
    printf("\nMinimum length of snake: %d", minLen);
    
    return 0;
}
