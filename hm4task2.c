#include <stdio.h>
#include <stdlib.h>

void swap(int* firstElement, int* secondElement) //START CREATING QSORT
{
    int transitElement = *firstElement;
    *firstElement = *secondElement;
    *secondElement = transitElement;
}

int partition(int* array, int lowIndex, int highIndex)
{
    int pivot = array[lowIndex];
    int pivotIndex = lowIndex;

    int lastIndexOfPivot = 0;

    for (int i = lowIndex + 1; i <= highIndex; ++i)
    {
        if (array[i] < pivot)
        {
            swap(&array[i], &array[pivotIndex]);
            if (array[i] == pivot)
                lastIndexOfPivot = i;
            ++pivotIndex;
        }
    }

    if (array[pivotIndex] != pivot)
    {
        swap(&array[lastIndexOfPivot], &array[pivotIndex]);
    }

    return pivotIndex;
}

void insertSort(int* array, int lowIndex, int highIndex)
{
    int transitElement = 0;
    int shiftIndex = 0;
    for (int i = lowIndex + 1; i <= highIndex; ++i)
    {
        transitElement = array[i];
        shiftIndex = i - 1;
        while (shiftIndex >= 0 && transitElement < array[shiftIndex])
        {
            array[shiftIndex + 1] = array[shiftIndex];
            --shiftIndex;
        }
        array[shiftIndex + 1] = transitElement;
    }
}

void quickSort(int* array, int lowIndex, int highIndex)
{
    int pivotIndex = 0;
    if (lowIndex < highIndex)
    {
        if (highIndex - lowIndex >= 10)
        {
            pivotIndex = partition(array, lowIndex, highIndex);
            quickSort(array, lowIndex, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, highIndex);
        }
        else
        {
            insertSort(array, lowIndex, highIndex);
        }
    }
}
//END CREATING OF QSORT
int mostFrequent(int* array, int arrayLength)
{
    quickSort(array, 0, arrayLength - 1);
    int mostFrequentNumber = array[0];
    int counter = 1;
    int maxCounter = 1;
    for (int i = 0; i < arrayLength - 1; ++i)
    {
        if (array[i] == array[i + 1])
        {
            ++counter;
            if (counter > maxCounter)
            {
                mostFrequentNumber = array[i];
                maxCounter = counter;
            }
        }
        else
        {
            counter = 1;
        }
    }

    return mostFrequentNumber;
}

int main()
{
    FILE* f;
    if (fopen_s(&f, "D:/input.txt", "r") != 0)
    {
        printf("File not found!\n");
        return -1;
    }

    int sizeOfArray = 0;
    int tmp = 0;
    while (fscanf_s(f, "%d", &tmp) == 1)
    {
        ++sizeOfArray;
    }
    fseek(f, 0, SEEK_SET);

    if (sizeOfArray == 0)
    {
        printf("Incorrect data!\n");
        fclose(f);
        return 1;
    }
    int* array = calloc(sizeOfArray, sizeof(int));
    if (array == NULL)
    {
        printf("Memory error!");
        fclose(f);
        return 1;
    }

    printf("Your array: ");
    int scanResult = 0;
    for (int i = 0; i < sizeOfArray; ++i)
    {
        scanResult = fscanf_s(f, "%d", &array[i]);
        if (scanResult != 1)
        {
            printf("ERROR File should contain only numbers!\n");
            fclose(f);
            free(array);
            return -2;
        }
        printf("%d ", array[i]);
    }
    fclose(f);

    printf("\nThe most frequent number in the array is %d: ", mostFrequent(array, sizeOfArray));
    free(array);
    return 0;
}