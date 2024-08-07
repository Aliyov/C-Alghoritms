#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node *initialization(Node **head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("\n:::Cant allocate mem:::\n");
        exit(1);
    }

    printf("\nEnter first value of DLL: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    *head = newNode;
    return *head;
}

void addFront(Node **head){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("\n:::Cant allocate mem:::\n");
        exit(1);
    }

    printf("\nEnter value to add at the front of DLL: ");
    scanf("%d", &newNode->data);

    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}
void reverse(Node **head){
    Node *current = *head, *temp = NULL;
    while(current != NULL){
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;
       current = current->prev;
    } 
}
void addBack(Node **head){
    Node *temp;
    temp = *head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("\n:::Cant allocate mem:::\n");
        exit(1);
    }

    printf("\nEnter value to add at the front of DLL: ");
    scanf("%d", &newNode->data);
    
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next =NULL;
    newNode->prev = temp;
}

void mergeList(Node **head1,Node **head2){
    if (*head1 == NULL) return *head2;
    if (*head2 == NULL) return *head1;

    Node *head3 = NULL;
    Node *temp1 = *head1;
    Node *temp2 = *head2;

    if(temp1->data < temp2->data){
        head3 = temp1;
        temp1 = temp1->next;
    }else{
        head3 = temp2;
        temp2 = temp2->next;
    }

    Node *temp3 = head3;

    while(temp1 != NULL && !temp2 != NULL){
        if (temp1->data < temp2->data) {
            temp3->next = temp1;
            temp1->prev = temp3;
            temp3 = temp1;
            temp1 = temp1->next;
        } else {
            temp3->next = temp2;
            temp2->prev = temp3;
            temp3 = temp2;
            temp2 = temp2->next;
        }
    }

    if (temp1 != NULL) {
        temp3->next = temp1;
        temp1->prev = temp3;
    }
    if (temp2 != NULL) {
        temp3->next = temp2;
        temp2->prev = temp3;
    }

    return head3;
}



int main(){
    int choice = 0, resume=0;
    Node *head = (Node*)malloc(sizeof(Node));
    if(head == NULL){
        perror("\n:::Cant allocate mem:::\n");
        exit(1);
    }
    head = initialization(&head);
    while(resume){
        printf("\nDo you want to continue: ");
        scanf("%d",&resume);
        if(resume ==1){
            break;
        }
        printf("\nWhere to add: ");

    }
    
    return 0;
}