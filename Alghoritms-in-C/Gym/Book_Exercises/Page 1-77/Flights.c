#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 20
#define FLIGHT_CODE 5
#define STRUCT_SIZE 100

struct Flight {
    char flightCode[FLIGHT_CODE];
    char origin[NAME_SIZE];
    char destination[NAME_SIZE];
    float departure_time;
    float arrival_time;
};

int createFlights(struct Flight allFlights[], int num);
void printData(struct Flight allFlights[], int size);

void processData(struct Flight allFlights[], int size, char origin_addr[], char dest_addr[], float time) {
    int i, j, count = 0, indirect_count = 0;
    struct Flight directFlights[STRUCT_SIZE];
    struct Flight indirectFlights[STRUCT_SIZE];

    // Direct flights
    for (i = 0; i < size; i++) {
        if (strcmp(origin_addr, allFlights[i].origin) == 0 &&
            strcmp(dest_addr, allFlights[i].destination) == 0 &&
            allFlights[i].departure_time >= time) {
            directFlights[count] = allFlights[i];
            count++;
        }
    }

    // Print Direct Flights
    if (count > 0) {
        printf("\n\t%d Direct Flight(s) Found\t\n", count);
        for (i = 0; i < count; i++) {
            printf("%s\t%s\t%s\t%.2f\t%.2f\n", directFlights[i].flightCode, directFlights[i].origin, directFlights[i].destination,
                   directFlights[i].departure_time, directFlights[i].arrival_time);
        }
    } else {
        printf("No direct flights found.\n");
    }

    // Indirect flights (one stop)
    for (i = 0; i < size; i++) {
        // First leg: origin -> stopover
        if (strcmp(origin_addr, allFlights[i].origin) == 0 && allFlights[i].departure_time >= time) {
            for (j = 0; j < size; j++) {
                // Second leg: stopover -> destination
                if (strcmp(allFlights[i].destination, allFlights[j].origin) == 0 &&
                    strcmp(allFlights[j].destination, dest_addr) == 0 &&
                    allFlights[i].arrival_time < allFlights[j].departure_time) {
                    indirectFlights[indirect_count] = allFlights[i]; // First leg
                    indirectFlights[indirect_count + 1] = allFlights[j]; // Second leg
                    indirect_count += 2;
                }
            }
        }
    }

    // Print Indirect Flights (with one stop)
    if (indirect_count > 0) {
        printf("\n\t%d Indirect Flight(s) with One Stop Found\t\n", indirect_count / 2);
        for (i = 0; i < indirect_count; i += 2) {
            printf("%s\t%s\t%s\t%.2f\t%.2f\n", indirectFlights[i].flightCode, indirectFlights[i].origin, indirectFlights[i].destination,
                   indirectFlights[i].departure_time, indirectFlights[i].arrival_time);
            printf("%s\t%s\t%s\t%.2f\t%.2f\n", indirectFlights[i + 1].flightCode, indirectFlights[i + 1].origin, indirectFlights[i + 1].destination,
                   indirectFlights[i + 1].departure_time, indirectFlights[i + 1].arrival_time);
            printf("\n");
        }
    } else {
        printf("No indirect flights (with one stop) found.\n");
    }
}

int main() {
    char dest_addr[STRUCT_SIZE];
    char origin_addr[STRUCT_SIZE];
    float dept_time;
    struct Flight allFlights[STRUCT_SIZE];

    int size = createFlights(allFlights, STRUCT_SIZE);

    printf("\nEnter departure address: ");
    scanf("%s", origin_addr);
    printf("\nEnter arrival address: ");
    scanf("%s", dest_addr);
    printf("\nEnter departure time: ");
    scanf("%f", &dept_time);

    processData(allFlights, size, origin_addr, dest_addr, dept_time);

    return 0;
}

int createFlights(struct Flight allFlights[], int num) {
    FILE *fpin = fopen("flights.txt", "r");
    if (fpin == NULL) {
        perror("\nCould not open the flight.txt file\n");
        return EXIT_FAILURE;
    }
    int count = 0;
    while (fscanf(fpin, "%s %s %s %f %f", allFlights[count].flightCode, allFlights[count].origin,
                  allFlights[count].destination, &allFlights[count].departure_time,
                  &allFlights[count].arrival_time) == 5) {
        count++;
    }

    fclose(fpin);
    return count;
}

void printData(struct Flight allFlights[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %s %s %.2f %.2f\n", allFlights[i].flightCode, allFlights[i].origin,
               allFlights[i].destination, allFlights[i].departure_time, allFlights[i].arrival_time);
    }
}
