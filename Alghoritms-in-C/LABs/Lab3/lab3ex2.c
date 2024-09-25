#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 51
#define ID_LENGTH 17
#define DATE_LENGTH 11

typedef struct Employee {
    char name[MAX_NAME_LENGTH];
    char id[ID_LENGTH];
    char hire_date[DATE_LENGTH];
    int salary;
    struct Employee *next;
    struct Employee *prev;
} Employee;

void push(Employee **head, char *name, char *id, char *date, int salary) {
    Employee *new_node = (Employee *)malloc(sizeof(Employee));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    strncpy(new_node->id, id, ID_LENGTH);
    strncpy(new_node->hire_date, date, DATE_LENGTH);
    new_node->salary = salary;

    Employee *temp = *head;
    new_node->next = temp->next;
    new_node->prev = NULL;
    *head = new_node;
    
}

Employee* find_employee(Employee *head, char *name) {
    Employee *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_employee(Employee *emp) {
    if (emp) {
        printf("%s %s %s %d\n", emp->name, emp->id, emp->hire_date, emp->salary);
    }
}

void free_list(Employee *head) {
    Employee *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <name_surname> <directions>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *target_name = argv[2];
    const char *directions = argv[3];

    FILE *fpin = fopen(input_filename, "r");
    if (fpin == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    Employee *head = NULL;
    char name[MAX_NAME_LENGTH];
    char id[ID_LENGTH];
    char date[DATE_LENGTH];
    int salary;

    while (fscanf(fpin, "%50s %16s %10s %d", name, id, date, &salary) != EOF) {
        push(&head, name, id, date, salary);
    }

    fclose(fpin);

    Employee *current = find_employee(head, target_name);
    print_employee(current);

    for (int i = 0; directions[i] != '\0'; i++) {
        if (directions[i] == '+') {
            if (current->next != NULL) {
                current = current->next;
            }
        } else if (directions[i] == '-') {
            if (current->prev != NULL) {
                current = current->prev;
            }
        }
        print_employee(current);
    }
    free_list(head);

    return 0;
}
