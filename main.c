#include <stdio.h>

void swap(int* x, int* y);
void segregateEvenOdd(int arr[], int size);

void segregateEvenOdd(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        while (arr[left] % 2 == 0 && left < right)
            left++;
        while (arr[right] % 2 == 1 && left < right)
            right--;
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int arr[100];
    int size, i;
    printf("Enter size of array: ");
    scanf_s("%d", &size);
    printf("Enter elements of array:\n");
    for (i = 0; i < size; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    segregateEvenOdd(arr, size);

    printf("The array after segregation is:  ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

    printf("Even numbers in the array: ");
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Odd numbers in the array: ");
    for (i = 0; i < size; i++) 
    {
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    }

    return 0;
}
