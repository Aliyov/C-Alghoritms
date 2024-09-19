#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 50

int searchSubStr(char str1[], char str2[], int from) {
    int i, j, flag;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    i = from;
    while (i <= len1 - len2) {
        flag = j = 0;
        while (j < len2 && flag == 0) {
            if (str1[i + j] != str2[j]) {
                flag = 1;
            }
            j++;
        }
        if (flag == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    char str1[DIM + 1];
    char str2[DIM + 1];
    char str3[DIM + 1];
    char strOut[DIM * DIM + 1];
    int i, idx, from, to, endflag;

    if (argc != 4) {
        printf("\nWrong number of arguments");
        return 1;
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);
    strcpy(str3, argv[3]);

    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len1 = strlen(str1);

    endflag = from = idx = 0;

    do {
        to = searchSubStr(str1, str2, from);
        if (to < 0) {
            to = len1;
            endflag = 1;
        }
        for (i = from; i < to; i++) {
            strOut[idx++] = str1[i];
        }
        if (endflag == 0) {
            for (i = 0; i < len3; i++) {
                strOut[idx++] = str3[i];
            }
        }
        from = to + len2;
    } while (endflag != 1);

    strOut[idx] = '\0';  // Null-terminate the output string
    printf("%s\n", strOut);  // Print the resulting string

    return 0;
}
