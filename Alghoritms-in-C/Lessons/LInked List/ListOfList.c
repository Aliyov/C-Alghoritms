#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_CITY_LENGTH 50

// Define a single structure for Node
typedef struct Node {
    char city[MAX_CITY_LENGTH];
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    int age;
    struct Node *next;        // For cities
    struct Node *nextList;    // For people within the same city
} Node;

// Function prototypes
Node* add_city(Node *head, char *city_name);
void add_person(Node *city_node, char *name, char *surname, int age);
Node* find_city(Node *head, char *city_name);
void print_data(Node *head);
void free_memory(Node *head);

int main() {
    FILE *file = fopen("names.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int num_entries;
    fscanf(file, "%d", &num_entries);

    Node *head = NULL;
    
    for (int i = 0; i < num_entries; ++i) {
        char city_name[MAX_CITY_LENGTH], person_name[MAX_NAME_LENGTH], person_surname[MAX_NAME_LENGTH];
        int person_age;
        fscanf(file, "%s %s %s %d", city_name, person_name, person_surname, &person_age);

        Node *city_node = find_city(head, city_name);
        if (!city_node) {
            head = add_city(head, city_name);
            city_node = find_city(head, city_name);
        }
        add_person(city_node, person_name, person_surname, person_age);
    }

    fclose(file);

    print_data(head);

    free_memory(head);

    return 0;
}

// Add a new city node to the linked list
Node* add_city(Node *head, char *city_name) {
    Node *new_city = (Node *)malloc(sizeof(Node));
    strcpy(new_city->city, city_name);
    strcpy(new_city->name, "");
    strcpy(new_city->surname, "");
    new_city->age = 0;
    new_city->next = head;
    new_city->nextList = NULL;
    return new_city;
}

// Add a new person node to the city's list
void add_person(Node *city_node, char *name, char *surname, int age) {
    Node *new_person = (Node *)malloc(sizeof(Node));
    strcpy(new_person->city, city_node->city);
    strcpy(new_person->name, name);
    strcpy(new_person->surname, surname);
    new_person->age = age;
    new_person->next = NULL;
    new_person->nextList = city_node->nextList;
    city_node->nextList = new_person;
}

// Find a city node by name
Node* find_city(Node *head, char *city_name) {
    Node *current = head;
    while (current) {
        if (strcmp(current->city, city_name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Print all cities and their people
void print_data(Node *head) {
    Node *current_city = head;
    while (current_city) {
        printf("City: %s\n", current_city->city);
        Node *current_person = current_city->nextList;
        while (current_person) {
            printf("\t%s %s, Age: %d\n", current_person->name, current_person->surname, current_person->age);
            current_person = current_person->nextList;
        }
        current_city = current_city->next;
    }
}

// Free allocated memory
void free_memory(Node *head) {
    while (head) {
        Node *temp_city = head;
        head = head->next;

        Node *people_head = temp_city->nextList;
        while (people_head) {
            Node *temp_person = people_head;
            people_head = people_head->nextList;
            free(temp_person);
        }

        free(temp_city);
    }
}
