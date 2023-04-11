#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int compare(const void* a, const void* b);
    int count = 0;
    int k,i;
    int n = MAX_SIZE;
    printf("Enter the size of array (max size 1000): ");
    scanf_s("%d", &n);

    printf("Enter the number of elements to search: ");
    scanf_s("%d", &k);

    int arr[MAX_SIZE];
    // Генерация массива из n случайных чисел
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    qsort(arr, n, sizeof(int), compare);

    printf("Generated array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Поиск k случайных чисел
    for (i = 0; i < k; i++) 
    {
        int x = rand() % 100;
        printf("Searching for %d in array...\n", x);
        if (binarySearch(arr, 0, n - 1, x) != -1)
        {
            printf("%d found in array\n", x);
            count++;
        }
        else
            printf("%d not found in array\n", x);
    }

    printf("Total %d elements found in array\n", count);

    return 0;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

