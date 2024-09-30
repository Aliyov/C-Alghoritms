#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct employee_s{
    char *nameSurname;
    char id[17];
    int numberOfWeeks;
    int **workingDays;
    int numberOfWorkingDays;
    struct employee_s *next;
}employee_s;


void readFile(FILE *fpIn, employee_s *head){
    char name[MAX];
    char surname[MAX];
    char tmp[MAX+MAX];
    char id[17];
    int weeks;

    int num, days;
    employee_s *newNode = (struct employee_s *)malloc(sizeof(struct employee_s));

    while(fscanf(fpIn, "%s %s %s %d", name,surname,id,weeks) != EOF){
        employee_s *newNode = (struct employee_s *)malloc(sizeof(struct employee_s));

        sprintf(tmp, "%s %s", name, surname);
        strcpy(newNode->nameSurname, tmp);
        strcpy(newNode->id, id);
        newNode->numberOfWeeks = weeks;
        newNode->numberOfWorkingDays = 0;
        newNode->next = NULL;

        newNode->workingDays = (int **)malloc(newNode->numberOfWeeks * sizeof(int *));

        for(int i=0; i<newNode->numberOfWeeks; i++){
            fscanf(fpIn, "%d %d", &num, &days);
            newNode->workingDays[i] = (int *)malloc()
        }

    }
}

int main(int argc, char *argv[]){
    FILE *fpIn = fopen(argv[1], "r");
    FILE *fpOut = fopen(argv[2], "w");

    if(fpIn == NULL || fpOut == NULL){
        perror("cant open the file");
        exit(1);
    }

    employee_s *head = NULL;

    readFile(fpIn, head);

    return 0;
}