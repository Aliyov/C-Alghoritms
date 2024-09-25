#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 30

struct Cyclist {
    char name[NAME_SIZE];
    int id;
    int laps;
    float *lap_times;
    float avg;
};

struct Cyclist *readFile(char filename[], int *numberOfCyclists) {
    int val, c_id, c_laps;
    char c_name[NAME_SIZE];
    float time;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("\nCan't read the file.\n");
        exit(1);
    }

    fscanf(fp, "%d", &val);
    *numberOfCyclists = val;

    struct Cyclist *cyclists;
    cyclists = (struct Cyclist *)malloc(val * sizeof(struct Cyclist));

    int cnt = 0;
    float sum = 0;
    while (fscanf(fp, "%s%d%d", c_name, &c_id, &c_laps) == 3) {
        sum = 0;
        cyclists[cnt].lap_times = (float *)malloc(c_laps * sizeof(float));

        for (int i = 0; i < c_laps; i++) {
            fscanf(fp, "%f", &time);
            cyclists[cnt].lap_times[i] = time;
            sum += cyclists[cnt].lap_times[i];
        }

        strcpy(cyclists[cnt].name, c_name);
        cyclists[cnt].id = c_id;
        cyclists[cnt].laps = c_laps;
        cyclists[cnt].avg = sum / cyclists[cnt].laps;
        cnt++;
    }
    fclose(fp);
    return cyclists;
}

void printData(struct Cyclist *cyclists, int numberOfCyclists) {
    for (int i = 0; i < numberOfCyclists; i++) {
        printf("Name: %s -- ID: %d -- Laps: %d\n", cyclists[i].name, cyclists[i].id, cyclists[i].laps);
    }
}

void findAthlete(struct Cyclist *cyclists, char name[], int numberOfCyclists) {
    for (int i = 0; i < numberOfCyclists; i++) {
        if (strcmp(cyclists[i].name, name) == 0) {
            printf("Name: %s\t#ID_NUMBER: %d #Laps: %d Times: ", cyclists[i].name, cyclists[i].id, cyclists[i].laps);
            for (int j = 0; j < cyclists[i].laps; j++) {
                printf("%.2f ", cyclists[i].lap_times[j]);
            }
            printf(" Average: %.2f\n", cyclists[i].avg);
            return; // Exit after finding the athlete
        }
    }
    printf("Athlete not found.\n");
}

void findBest(struct Cyclist *cyclists, int numberOfCyclists) {
    int best_index = 0;
    for (int i = 1; i < numberOfCyclists; i++) {
        if (cyclists[i].avg < cyclists[best_index].avg) {
            best_index = i;
        }
    }

    printf("Best Athlete:\nName: %s -- ID: %d -- Avg Time: %.2f\n",
           cyclists[best_index].name, cyclists[best_index].id, cyclists[best_index].avg);
}

int main(int argc, char *argv[]) {
    char filename[20];
    char name[NAME_SIZE];
    int option;
    int numberOfCyclists = 0;
    struct Cyclist *cyclists;

    printf("Enter cyclist filename: ");
    scanf("%s", filename);
    cyclists = readFile(filename, &numberOfCyclists);

    printf("\n...Reading is successful...\n");

    while (1) {
        printf("Select an option:\n  1.List\n  2.Detail\n  3.Best\n  4.Stop\nChoice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n\t...Listing...\n");
                printData(cyclists, numberOfCyclists);
            case 2:
                printf("Enter athlete name: ");
                scanf("%s", name);
                findAthlete(cyclists, name, numberOfCyclists);
            case 3:
                printf("\nBest athlete: ");
                findBest(cyclists, numberOfCyclists);
            case 4:
                printf("\nExiting...\n");
                // Free memory before exiting
                for (int i = 0; i < numberOfCyclists; i++) {
                    free(cyclists[i].lap_times);
                }
                free(cyclists);
                return 0; // Exit the program
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
