#include <stdio.h>

#define MAX_SIZE 100

int main() 
{
    int arr[MAX_SIZE];
    int n, i, minIndex, maxIndex;

    printf("Please enter the number of elements in the array (no more than %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    printf("Enter array elements:");
    for (i = 0; i < n; i++) 
    {
        scanf_s("%d", &arr[i]);
    }

    minIndex = 0;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] < arr[minIndex]) 
        {
            minIndex = i;
        }
    }

    maxIndex = 0;
    for (i = 1; i < n; i++) 
    {
        if (arr[i] > arr[maxIndex]) 
        {
            maxIndex = i;
        }
    }

    int sumIndex = minIndex + maxIndex;

    printf("Sum of indexes of minimum and maximum elements: %d\n", sumIndex);

    return 0;
}
