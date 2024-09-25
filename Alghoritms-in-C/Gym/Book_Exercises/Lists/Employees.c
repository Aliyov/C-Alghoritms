/*
A file stores information regarding all emplyees of a large firm. For each employee the
file includes the following line:

lastName firstName id workingWeeks
week1 workingDays hoursDay1 hoursDay2 ...
week2 workingDays hoursDay1 hoursDay2 ...

All fields are strings of user selected lenghts or integer values.
The first line includes the generality of the emplyee, and the number of weeks he/she has worked.
All following lines report for each week the number of days, and for each day the number of hours
he/she has worked. Notice that week indicates the week within the year(an integer from 1 to 52).
workingDays the working days within that week(from 1 to 7). and hoursDay the hour worked within
that day(from 1 to 24).

The file order is unspecified.
Write a program able to:
-Recieve two files names on the command line.
-Read the first file, with the previous content, and store its content in a proper data structure.
-Store the entire data structure in an output file, where employees are ordered by ascending number
 of total working hours.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50+1

typedef struct employee_s {
    char *nc;        // Full name (first and last)
    char cf[17];     // Fiscal code (cf)
    int ns;          // Number of tasks (ns)
    int **mat;       // 2D array to store task numbers and days
    int to;          // Total amount of work done
    struct employee_s *next; // Pointer to the next employee in the list
} employee_t;

// Function to read employee data from the file
employee_t *employee_read(FILE *fin) {
    char n[MAX], c[MAX], cf[17];
    employee_t *e;
    int i, j, ns, num, day;

    if (fscanf(fin, "%s %s %s %d", c, n, cf, &ns) == EOF) {
        return NULL;
    }

    e = (employee_t *)malloc(sizeof(employee_t));
    if (!e) {
        perror("Error allocating memory for employee");
        exit(EXIT_FAILURE);
    }

    // Allocate enough space for concatenated name
    size_t name_length = strlen(c) + strlen(n) + 1; // +1 for the space
    char *tmp = (char *)malloc(name_length * sizeof(char)); // Dynamically allocate tmp
    if (!tmp) {
        perror("Error allocating memory for temporary name buffer");
        free(e);
        exit(EXIT_FAILURE);
    }

    snprintf(tmp, name_length, "%s %s", c, n);
    e->nc = strdup(tmp); // Combine first and last names
    strcpy(e->cf, cf);
    e->ns = ns;
    e->to = 0;

    // Allocate memory for the employee's tasks matrix
    e->mat = (int **)malloc(ns * sizeof(int *));
    if (!e->mat) {
        perror("Error allocating memory for task matrix");
        free(tmp);
        free(e);
        exit(EXIT_FAILURE);
    }

    // Read task data for each task
    for (i = 0; i < ns; i++) {
        fscanf(fin, "%d %d", &num, &day);
        e->mat[i] = (int *)malloc((day + 2) * sizeof(int)); // Extra 2 for task number and day count
        if (!e->mat[i]) {
            perror("Error allocating memory for task details");
            free(tmp);
            exit(EXIT_FAILURE);


        }
        e->mat[i][0] = num;  // Task number
        e->mat[i][1] = day;  // Number of days for this task
        for (j = 0; j < day; j++) {
            fscanf(fin, "%d", &e->mat[i][j + 2]); // Task details (work done)
            e->to += e->mat[i][j + 2]; // Add to total work done
        }
    }

    e->next = NULL; // Initialize next to NULL
    free(tmp); // Free temporary buffer after use
    return e;       // Return the newly created employee structure
}
// Function to insert an employee into a sorted linked list based on 'to'
employee_t *list_insert(employee_t *head, employee_t *e) {
    employee_t *p;

    // Insert at the head if the list is empty or the new employee has fewer total work
    if (head == NULL || e->to < head->to) {
        e->next = head;
        return e;
    }

    // Traverse the list to find the right position to insert
    p = head;
    while (p->next != NULL && p->next->to < e->to) {
        p = p->next;
    }

    e->next = p->next;
    p->next = e;

    return head;
}

// Function to write the employee data to a file
void file_write(FILE *fp, employee_t *head) {
    employee_t *e = head; 

    while (e != NULL) {
        fprintf(fp, "%s %s %d\n", e->nc, e->cf, e->ns);
        for (int i = 0; i < e->ns; i++) {
            for (int j = 0; j < e->mat[i][1] + 2; j++) {
                fprintf(fp, "%d ", e->mat[i][j]);
            }
            fprintf(fp, "\n");
        }
        e = e->next;
    }
}

// Function to free all allocated memory
void memory_free(employee_t *head) {
    employee_t *e;

    while (head != NULL) {
        for (int i = 0; i < head->ns; i++) {
            free(head->mat[i]); // Free individual task arrays
        }
        free(head->mat); // Free the matrix
        free(head->nc);  // Free the name
        e = head;
        head = head->next;
        free(e); // Free the employee structure
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    employee_t *e, *head = NULL;
    FILE *fin, *fout;

    // Open the input file
    if ((fin = fopen(argv[1], "r")) == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Read employees and insert them into the sorted list
    while ((e = employee_read(fin)) != NULL) {
        head = list_insert(head, e);
    }
    fclose(fin); // Close the input file

    // Open the output file
    if ((fout = fopen(argv[2], "w")) == NULL) {
        perror("Error opening output file");
        memory_free(head);
        return EXIT_FAILURE;
    }

    // Write the sorted list to the output file
    file_write(fout, head);
    fclose(fout); // Close the output file

    // Free all allocated memory
    memory_free(head);
    
    return EXIT_SUCCESS;
}
