#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct value_s{
    int num;
    char element[N];
}value_t;

int multiplication(value_t value[], char solution[], int n, int pos, int count){
    if(pos >= n){
        printf("{ ");
        for(int i=0; i<n; i++){
            printf("%c ",solution[i]);
        }
        printf("}\n");
        return count+1;
    }

    for(int i=0; i<value[pos].num; i++){
        solution[pos] = value[pos].element[i];
        count = multiplication(value, solution, n, pos+1, count);
    }
    return count;
}

int main(int argc, char *argv[]){
    value_t value[3];
    char solution[3];
    int n = 3, pos = 0, count = 0;
    int total;

    value[0].num = 2;
    value[0].element[0] = 'A';
    value[0].element[1] = 'B';

    value[1].num = 2;
    value[1].element[0] = '0';
    value[1].element[1] = '1';

    value[2].num = 3;
    value[2].element[0] = 'X';
    value[2].element[1] = 'Y';
    value[2].element[2] = 'Z';

    total = multiplication(value, solution, n, pos, count);
    printf("\nTotal: %d, total");


    return 0;
}