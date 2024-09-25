#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ID_SIZE 5
#define NAME_SIZE 20

struct Patient{
    char id[ID_SIZE];
    char surname[NAME_SIZE];
    char title[NAME_SIZE];
    char name[NAME_SIZE];
    int blood;
};

struct Patient *readDonation(int *count){
    char title[NAME_SIZE], name[NAME_SIZE], surname[NAME_SIZE], id[ID_SIZE];
    int blood = 0;
    int cnt = 0;
    *count = 0;
    struct Patient *patients = NULL;

    FILE *fpP = fopen("patines.txt", "r");
    if(fpP == NULL){
        perror("\nCan't open the patients.txt file.\n");
        return EXIT_FAILURE;
    }

    while(fscanf(fpP,"%s%s%s%s",id, title,name,surname) != EOF){
        patients = (struct Patient*)realloc(patients, (cnt+1)*sizeof(struct Patient));

        if (patients == NULL) {
            perror("\nMemory allocation failed.\n");
            fclose(fpP);
            return NULL;
        }

        strcpy(patients[cnt].id, id);
        strcpy(patients[cnt].title, title);
        strcpy(patients[cnt].name, name);
        strcpy(patients[cnt].surname, surname);
        patients[cnt].blood = 0;
        cnt++;
    }

    fclose(fpP);
    *count = cnt;
    return patients;
}

void processData(struct Patient *patients, int count){
    char id[ID_SIZE];
    int blood=0;

    FILE *fpB = fopen("bloods.txt","r");
    if(fpB == NULL){
        perror("\nCan't read bloods.txt file.\n");
        return EXIT_FAILURE;
    }

    while(fscanf(fpB, "%s%d",id,&blood) != EOF){
        for(int i=0; i<count; i++){
            if(strcmp(id,patients[i].id)==0){
                patients[i].blood += blood;
            }
        }
    }

}

void printData(struct Patient *patients, int count){
    for(int i=0; i<count; i++){
        printf("%s %s %s %d\n",patients[i].id,patients[i].name,patients[i].surname,patients[i].blood);
    }
}

int main(){
    int count=0;
    struct Patient *patients = readDonation(&count);

    processData(patients,count);
    printData(patients,count);
    return 0;
}