#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void map_read(char *, int [DIM][DIM], int *, int *);
void expand_r(int [DIM][DIM], int, int, int);
void map_write(char *, int [DIM][DIM], int, int, int);

int main(int argc, char *argv[]) {
    int map[DIM][DIM];
    int i, j, nr, nc, n = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    map_read(argv[1], map, &nr, &nc);
    
    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            if (map[i][j] == (-1)) {
                expand_r(map, i, j, ++n);
            }
        }
    }

    map_write(argv[2], map, nr, nc, n);

    return EXIT_SUCCESS;
}

void map_read(char *name, int map[DIM][DIM], int *nr, int *nc) {
    FILE *fp;
    char line[DIM + 2];
    int i, j;

    fp = fopen(name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (fgets(line, DIM + 2, fp) != NULL) {
        j = 0;
        while (j < DIM && (line[j] == '.' || line[j] == '*')) {
            map[i][j] = (line[j] == '*' ? 0 : -1);
            j++;
        }
        i++;
    }
    fclose(fp);

    *nr = i;  // Set number of rows
    *nc = j;  // Set number of columns (assuming all rows have the same length)
}

void expand_r(int map[DIM][DIM], int x, int y, int id) {
    int i, xx, yy;
    const int xoff[] = {1, 0, -1, 0};
    const int yoff[] = {0, 1, 0, -1};

    if (x < 0 || x >= DIM || y < 0 || y >= DIM || map[x][y] != (-1)) {
        return;  // Check for bounds and already visited cells
    }

    map[x][y] = id;

    for (i = 0; i < 4; i++) {
        xx = x + xoff[i];
        yy = y + yoff[i];
        expand_r(map, xx, yy, id);
    }
}

void map_write(char *name, int map[DIM][DIM], int nr, int nc, int n) {
    FILE *fp;
    int i, j;

    fp = fopen(name, "w");  // Open file for writing
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < nr; i++) {
        for (j = 0; j < nc; j++) {
            if (map[i][j] == 0) {
                fprintf(fp, "*");
            } else {
                fprintf(fp, "%d", map[i][j]);
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(stdout, "Regions number: %d\n", n);

    fclose(fp);
}

