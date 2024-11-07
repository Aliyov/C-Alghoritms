#include <stdio.h>
#include <stdlib.h>

int binarySearchRecursive(int array[], int left, int right, int target){
    int middle;

    if(left > right){
        return -1;
    }

    middle = (left + right)/2;

    if(target < array[middle]){
        return binarySearchRecursive(array, left, middle - 1, target);
    }

    if(target > array[middle]){
        return binarySearchRecursive(array, middle + 1, right, target);
    }

    return middle;
}

int binarySearchIterative(int array[], int left, int right, int target) {
    int middle;

    while (left <= right) {
        middle = (left + right) / 2;

        if (target == array[middle]) {
            return middle; 
        }

        if (target < array[middle]) {
            right = middle - 1; 
        } else {
            left = middle + 1; 
        }
    }

    return -1; 
}

int main(){
    int target;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int arraySize = sizeof(array) / sizeof(array[0]);

    int posRecursive, posIterative;

    printf("\nEnter a target value to search: ");
    scanf("%d", &target);

    posRecursive = binarySearchRecursive(array, 0, arraySize - 1, target);
    posIterative = binarySearchIterative(array, 0, arraySize - 1, target);

    if(posRecursive != -1){
        printf("Recursive search: Target %d found at index %d\n", target, posRecursive);
    }else{
        printf("Recursive search: Target %d not found\n", target);
    }


    if (posIterative != -1) {
        printf("Iterative search: Target %d found at index %d\n", target, posIterative);
    } else {
        printf("Iterative search: Target %d not found\n", target);
    }


    return 0;
}