#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000 // Size of hash table

int findMostFrequent(int arr[], int n)
{
    int i, max_count = 0, max_num = 0;
    int* hash_table = (int*)calloc(SIZE, sizeof(int)); // Initialize the hash table with zeros

    for (i = 0; i < n; i++) 
    {
        int num = arr[i];
        hash_table[num]++;
        if (hash_table[num] > max_count)
        {
            max_count = hash_table[num];
            max_num = num;
        }
    }

    free(hash_table);
    return max_num;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 1, 2, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int most_frequent = findMostFrequent(arr, n);
    printf("Most frequent element: %d\n", most_frequent);
    return 0;
}

