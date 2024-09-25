#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CYCLIST 100
#define MAX_NAME_LENGTH 30

typedef struct{
    char name[MAX_NAME_LENGTH + 1];
    int identifier;
    int num_laps;
    float *lap_times;
}Cyclist;

typedef struct{
    int num_cyclists;
    Cyclist cyclists[MAX_CYCLIST];
}CyclistGroup;

void listCyclists(CyclistGroup *group) {
    printf("Number of athletes : %d\n", group->num_cyclists);
    for (int i = 0; i < group->num_cyclists; i++) {
        Cyclist *cyclist = &group->cyclists[i];
        printf("Name: %s #Id:%d #Laps:%d\n", cyclist->name, cyclist->identifier, cyclist->num_laps);
    }
}

void detailsCyclist(CyclistGroup *group, const char *name) {
    for (int i = 0; i < group->num_cyclists; i++) {
        Cyclist *cyclist = &group->cyclists[i];
        if (strcmp(cyclist->name, name) == 0) {
            printf("#Id:%d #Laps:%d Times: ", cyclist->identifier, cyclist->num_laps);
            for (int j = 0; j < cyclist->num_laps; j++) {
                printf("%.2f ", cyclist->lap_times[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Cyclist not found.\n");
}

float computeAverageTime(Cyclist *cyclist) {
    float sum = 0;
    for (int i = 0; i < cyclist->num_laps; i++) {
        sum += cyclist->lap_times[i];
    }
    return sum / cyclist->num_laps;
}

void bestCyclist(CyclistGroup *group) {
    if (group->num_cyclists == 0) {
        printf("No cyclists in the group.\n");
        return;
    }

    Cyclist *best = &group->cyclists[0];
    float best_avg = computeAverageTime(best);

    for (int i = 1; i < group->num_cyclists; i++) {
        Cyclist *cyclist = &group->cyclists[i];
        float avg = computeAverageTime(cyclist);
        if (avg < best_avg) {
            best = cyclist;
            best_avg = avg;
        }
    }

    printf("Name:%s #Id number:%d Laps:%d Times: ", best->name, best->identifier, best->num_laps);
    for (int j = 0; j < best->num_laps; j++) {
        printf("%.2f ", best->lap_times[j]);
    }
    printf("(Average:%.2f)\n", best_avg);
}

void freeCyclistGroup(CyclistGroup *group) {
    for (int i = 0; i < group->num_cyclists; i++) {
        free(group->cyclists[i].lap_times);
    }
}


int main(){
    char filename[100];
    printf("Input file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Can't open input file");
        return 1;
    }

    CyclistGroup group;
    fscanf(file, "%d", &group.num_cyclists);
    for (int i = 0; i < group.num_cyclists; i++) {
        Cyclist *cyclist = &group.cyclists[i];

        fscanf(file, "%s %d %d", cyclist->name, &cyclist->identifier, &cyclist->num_laps);
        cyclist->lap_times = (float *)malloc(cyclist->num_laps * sizeof(float));

        for (int j = 0; j < cyclist->num_laps; j++) {
            fscanf(file, "%f", &cyclist->lap_times[j]);
        }
    }

    fclose(file);

    char command[50];
    while (1) {
        printf("Command? ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            listCyclists(&group);
        } else if (strcmp(command, "details") == 0) {
            char name[MAX_NAME_LENGTH + 1];
            scanf("%s", name);
            detailsCyclist(&group, name);
        } else if (strcmp(command, "best") == 0) {
            bestCyclist(&group);
        } else if (strcmp(command, "stop") == 0) {
            printf("Program ended.\n");
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    freeCyclistGroup(&group);
    return 0;
}