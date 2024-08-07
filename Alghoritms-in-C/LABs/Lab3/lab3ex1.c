#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct string {
    char *str;
    int frequency;
    struct string *next;
} Node;

void addWord(Node **head, char *word);
void writeToFile(Node *head, FILE *file);
void freeList(Node *head);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    FILE *fpin = fopen(input_filename, "r");
    FILE *fpout = fopen(output_filename, "w");

    if (fpin == NULL) {
        perror("Failed to open input file");
        exit(1);
    }
    if (fpout == NULL) {
        perror("Failed to open output file");
        fclose(fpin);
        exit(1);
    }

    char buffer[256];
    Node *head = NULL;

    while (fscanf(fpin, "%255s", buffer) != EOF) {
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        addWord(&head, buffer);
    }

    writeToFile(head, fpout);

    fclose(fpin);
    fclose(fpout);
    freeList(head);
    return 0;
}

void addWord(Node **head, char arr[]) {
    Node *temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->str, arr) == 0) {
            temp->frequency++;
            return;
        }
        temp = temp->next;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(1);
    }

    newNode->str = strdup(arr);
    if (newNode->str == NULL) {
        perror("Failed to allocate memory for string");
        free(newNode);
        exit(1);
    }

    newNode->frequency = 1;
    newNode->next = *head;
    *head = newNode;
}

void writeToFile(Node *head, FILE *file) {
    Node *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s %d\n", temp->str, temp->frequency);
        temp = temp->next;
    }
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }
}
