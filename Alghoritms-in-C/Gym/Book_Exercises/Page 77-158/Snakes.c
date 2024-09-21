#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct{
    char value;
    int visited;
}element_t;

element_t **malloc2d(int r, int c){
    int i;
    element_t **mat;
    mat = (element_t **)malloc(r * sizeof(element_t*));

    for(int i=0; i<r; i++){
        mat[i] = (element_t *)malloc(c * sizeof(element_t));
    }

    return mat;
}

void map_read (char *fname, element_t ***mapP, int *nr, int *nc){
    element_t **map;
    char c;
    FILE *fp;
    int i,j;

    fp = fopen(fname, "r");
    fscanf(fp, "%d %d", nr, nc);
    fscanf(fp ,"%c", &c);

    map = malloc2d(*nr, *nc);

    for(int i=0; i<*nr; i++){
        for(int j=0; j<*nc; j++){
            if(fscanf(fp, "%c", &map[i][j].value) != EOF){
                map[i][j].visited = 0;
            }
        }
        fscanf(fp, "%c", &c);
    }

    fclose(fp);
    *mapP = map;
}


int length_evaluate(element_t **map, int nr, int nc, int r, int c){
    int end=0, length = 1, found, r_new, c_new, i,j;

    map[r][c].visited = 1;

    while(!end){
        found = 0;
        for(i=r-1; i<=r+1 && found == 0; i++){
            for(j=c-1; j<c+1 && found == 0; j++){
                if(i>=0 && i<nr && j>=0 && j<nc){
                    if(map[i][j].value == '*' && !map[i][j].visited){
                        found = 1;
                        r_new = i;
                        c_new = j;
                    }
                }
            }
        }
        if(found){
            length++;
            r = r_new;
            c = c_new;
            map[r][c].visited = 1;
        }else{
            end = 1;
        }
    }
    return length;
}


int main(int argc, char *argv[]){
    element_t **map;
    int nSnake = 0, minLen = INT_MAX, maxLen=0;
    int nr, nc, i, j, length;

    map_read(argv[1], &map, &nr, &nc);

    for(int i=0; i<nr; i++){
        for(int j=0; j<nc; j++){
            if(map[i][j].value == '+'){
                nSnake++;
                length = length_evaluate(map, nr, nc, i, j);
                if(length < minLen){
                    minLen = length;
                }
                if(length > maxLen){
                    maxLen = length;
                }
            }
        }
    }



    return 0;
}