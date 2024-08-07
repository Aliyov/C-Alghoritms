#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *implementation(Node **head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("\nCan't allocate memory.\n");
        exit(1);
    }

    printf("Enter first element of linked list: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    *head = newNode; 
    return *head;
}


void printList(Node **head){
    Node *temp = *head;

    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
        if(temp != NULL){
            printf("->");
        }
    }
    printf("->NULL");
}

void addFront(Node **head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("\nCant allocate memory");
        exit(1);
    }
    printf("\nEnter value: ");
    scanf("%d",&newNode->data);

    newNode->next = *head;
    *head = newNode;
}

void addBack(Node **head){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("\nCant allocate memory");
        exit(1);
    }
    printf("\nEnter value: ");
    scanf("%d",&newNode->data);
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;

}

void addAnyPoint(Node **head){
    int position=0, counter=0;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("\nCant allocate mem.");
        exit(1);
    }
    Node *temp=*head;
    printf("\nWhich place you want to add:");
    scanf("%d",&position);
    printf("\nEnter value");
    scanf("%d",&newNode->data);

    while(counter<position-1 && temp != NULL){
        temp=temp->next;
        counter++;
    }
    if (temp == NULL) {
        printf("Position is out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}   

int findLenght(Node **head){
    Node *temp = *head;
    int counter =0;
    while(temp != NULL){
        counter++;
        temp = temp -> next;
    }
    return counter;
}

void reverserList(Node **head){
    Node *current=*head, *prev=NULL, *next=NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortTheList(Node **head){
    Node *current, *index;
    int temp;
    for(current = *head; current != NULL; current = current->next){
        for(index = current->next; index != NULL; index = index->next){
            if(current->data > index->data){
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

int main(){
    int pos=0, resume=1;
    Node *head;
    head = implementation(&head);
    while(resume){
        printf("\nWhere you want to add next element? (front(1) / back(2) /given point(3) : ");
        scanf("%d",&pos);
        if(pos ==1){
            addFront(&head);
        }else if(pos ==2){
            addBack(&head);
        }else if(pos == 3){
            addAnyPoint(&head);
        }
        printf("\nDo you want to continue: ");
        scanf("%d",&resume);
    printf("Printing the list: ");
    printList(&head);
    int len = findLenght(&head);
    printf("\nLenght is: %d",len);
    printf("\nReversed linked list is: ");
    reverseList(&head);
    sortTheList(&head);

    return 0;
    }
}

void deleteFirst(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(Node **head){
    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    }

    free(temp);
}

void findElement(Node **head, int key){
    Node *temp = *head;
    int flag=0;
    int counter=0;
    while(temp->next != NULL && flag){
        counter++;
        if(temp->data == key){
            printf("Key found: %d in %d position",key,counter);
            flag=1;
        }
        temp = temp->next;
    }
}
