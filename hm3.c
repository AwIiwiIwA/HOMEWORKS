#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_SIZE 1000000

int main() {
    int* arr = (int*)
        malloc(MAX_SIZE * sizeof(int));
    int n = 0, i = 0;
    FILE* fp;

    if (fopen_s(&fp, "input.txt", "r") != 0) 
    {
        printf("Error opening file\n");
        exit(1);
    }
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fscanf_s(fp, "%d", &arr[n]) == 1) {
        n++;
        if (n == MAX_SIZE) {
            printf("Array is too big\n");
            exit(1);
        }
    }

    fclose(fp);

    sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}