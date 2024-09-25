#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char producer[10];
    char product[10];
    struct Node *next;
    struct Node *nextList;
}Node;


Node *addList(Node **head,char productName[], char producerName[]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *temp = *head;
    Node *temp2 = NULL;
    while(temp != NULL){
        if(strcmp(temp->producer, producerName) ==0){
            temp2 = temp;
            while(temp2 != NULL){
                strcpy(newNode->product,productName);
                strcpy(newNode->producer,producerName);
                temp->nextList = newNode;
                newNode->next = NULL;
                newNode->nextList = NULL;   
                temp2->next = NULL;
            }
            
        }
    }
}

int main(){


    return 0;
}