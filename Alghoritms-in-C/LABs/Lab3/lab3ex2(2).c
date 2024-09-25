#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 50
#define MAX_ID 16

typedef struct person{
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    char id[MAX_ID];
    char date[10];
    int salary;
    struct person *next;
    struct person *prev;
}person;

person *storeList(FILE *fp , person **head){
    char pName[NAME_LENGTH],pSurname[NAME_LENGTH],pID[MAX_ID],pDate[10];
    int pSalary;
    char name_surname[NAME_LENGTH];

    while((fp, "%s %s %s %d",name_surname,pID,pDate,&pSalary)!=EOF){
        *head = addPersonToList(name_surname,pID,pDate,pSalary);
    }
}

person *addPersonToList(char name_surname[],char pId[], char pData[],int pSalary){
    int len = sizeof(name_surname)/sizeof(char);
    char pName[NAME_LENGTH];
    char pSurname[NAME_LENGTH];
    int count=0;
    int nameSurname = 2;
    for(int i=0; i<len; i++){
        if(name_surname[i] != '_' || count<=2){
            nameSurname=1;
        }
        if(name_surname[i] == '_'){
            count=0;
            nameSurname = 2;
        }
        switch (nameSurname){
            case 1: 
                pName[count] = name_surname[i];
                count++;
            case 2:
                pSurname[count] = name_surname[i];
                count++;
        }
        
    }
}

int main(int argc, char *argv[]){
    if(argc != 4){
        perror("\nArgument error.");
        exit(1);
    }
    const char *filename = argv[1];
    FILE *fp = fopen(filename,"r");
    person *head = NULL;
    head = storeList(fp,&head);

    return 0;
}