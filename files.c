#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_SIZE 256

void merge(int arr1[], int size1, int arr2[], int size2, int res[], int* size_res)
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] == arr2[j])
        {
            res[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else {
            j++;
        }
    }
    *size_res = k;
}

void writeToFile(int arr[], int size, FILE* file)
{
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }
}

int main()
{
    FILE* file1;
    errno_t err = fopen_s(&file1, "file1.txt", "r");
    if (err != 0)
    {
        printf("Error opening file1.txt\n");
        return 1;
    }
    FILE* file2;
    err = fopen_s(&file2, "file2.txt", "r");
    if (err != 0)
    {
        printf("Error opening file2.txt\n");
        return 1;
    }
    FILE* file_res;
    err = fopen_s(&file_res, "result.txt", "w");
    if (err != 0)
    {
        printf("Error opening result.txt\n");
        return 1;
    }

    int F1[MAX_SIZE];
    int F2[MAX_SIZE];
    int res[MAX_SIZE];
    int size1 = 0, size2 = 0, size_res = 0;

    // Read file1
    while (fscanf_s(file1, "%d", &F1[size1]) == 1 && size1 < MAX_SIZE)
    {
        size1++;
    }

    // Read file2
    while (fscanf_s(file2, "%d", &F2[size2]) == 1 && size2 < MAX_SIZE)
    {
        size2++;
    }
    fclose(file1);
    fclose(file2);

    merge(F1, size1, F2, size2, res, &size_res);

    // Write common elements to result file
    writeToFile(res, size_res, file_res);

    int unique1[MAX_SIZE];
    int size_unique1 = 0;
    for (int i = 0; i < size1; i++)
    {
        int j = 0;
        while (j < size_res && res[j] != F1[i])
        {
            j++;
        }
        if (j == size_res)
        {
            unique1[size_unique1++] = F1[i];
        }
    }

    // Write elements only in file1 to result file
    writeToFile(unique1, size_unique1, file_res);

    int unique2[MAX_SIZE];
    int size_unique2 = 0;
    for (int i = 0; i < size2; i++)
    {
        int j = 0;
        while (j < size_res && res[j] != F2[i])
        {
            j++;
        }
        if (j == size_res)
        {
            unique2[size_unique2++] = F2[i];
        }
    }

    writeToFile(unique2, size_unique2, file_res);

    fclose(file_res);

    printf("Program executed successfully.\n");

    return 0;
}