#include <stdio.h>

int countOfZeros(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == 0) 
        {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = { 0, 5, 0, 3, 0, 7, 0, 0 };
    int n = sizeof(arr);
        sizeof(arr[0]);
    int zeroCount = countOfZeros(arr, n);
    printf("The array contains %d zero(s).\n", zeroCount);
    return 0;
}