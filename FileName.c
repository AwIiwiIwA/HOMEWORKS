#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 10

void insertionSort(int* arr, int left, int right) 
{
    for (int i = left + 1; i <= right; i++) 
    {
        int j = i;
        int temp = arr[i];
        while (j > left && arr[j - 1] > temp) 
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

int partition(int* arr, int left, int right) 
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) 
    {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void quicksort(int* arr, int left, int right) 
{
    if (right - left + 1 <= MIN_SIZE) 
    {
        insertionSort(arr, left, right);
        return;
    }
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quicksort(arr, left, pivot_index - 1);
        quicksort(arr, pivot_index + 1, right);
    }
}

void qsortCustom(int* arr, int size)
{
    quicksort(arr, 0, size - 1);
}

int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf_s("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    qsortCustom(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
