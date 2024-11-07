//unfinished
#include <stdio.h>
#include <stdlib.h>
#define DIM 20

void readMap(char *filename, int map[DIM][DIM], int *numRows, int *numCols);

int main(int argc, char *argv[]){
    int map[DIM][DIM];
    int numRows, numCols, regionId = 0;

    if(argc != 3){
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    readMap(argv[1], map, &numRows, &numCols);

    for(int row=0; row<numRows; row++){
        for(int col=0; col<numCols; col++){
            if(map[row][col] == -1){
                expandRegion(map, row, col, ++regionId);
            }
        }
    }

    writeMap(argv[2], map, numRows, numCols, regionId);

    return 0;
}

void readMap(char *filename, int map[DIM][DIM], int *numRows, int *numCols){
    FILE *file;
    char line[DIM+2];
    int row = 0, col;

    file = fopen(filename, "r");
    
    if(file == NULL){
        perror("\nError opening file\n");
        exit(EXIT_FAILURE);
    } 

    while(fgets(line, DIM+2, file) != NULL){
        col = 0;
        while(col < DIM && (line[col] == '.' || line[col] == '*')){
            if(line[col] == '*'){
                map[row][col] = 0;
            }else{
                map[row][col] = -1;
            }
            col++;
        }
        row++;
    }

    fclose(file);
    *numRows = row;
    *numCols = col;
}

void expandRegion(int map[DIM][DIM], int row, int col, int regionId){
    const int rowOffset[] = {1, 0, -1, 0};
    const int colOffset[] = {0, 1, 0, -1};

    if(row < 0 || row >= DIM || col < 0 || col >= DIM || map[row][col] != -1){
        return;
    }

    map[row][col] = regionId;

    for(int i=0; i < 4; i++){
        int newRow = row + rowOffset[i];
        int newCol = col + colOffset[i];
        expandRegion(map, newRow, newCol, regionId);
    }
}