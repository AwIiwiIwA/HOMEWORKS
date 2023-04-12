#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* mergeQueues(Queue* one, Queue* two) 
{
    Queue* mergeQueues = createQueue();
    while (!empty(one) && !empty(two)) 
    {
        enqueue(mergeQueues, dequeue(one));
        enqueue(mergeQueues, dequeue(two));
    }
    clearQueue(one);
    clearQueue(two);
    return mergeQueues;
}

int main() 
{
    Queue* one = createQueue();
    Queue* two = createQueue();
    int n;
    printf("Enter the number of elements in each queue: ");
    scanf_s("%d", &n);
    printf("Enter the elements of queue 1:\n");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf_s("%d", &element);
        enqueue(one, element);
    }
    printf("Enter the elements of queue 2:\n");
    for (int i = 0; i < n; i++) 
    {
        int element;
        scanf_s("%d", &element);
        enqueue(two, element);
    }
    Queue* mergedQueue = mergeQueues(one, two);
    printf("Merged queue: ");
    while (!empty(mergedQueue)) 
    {
        printf("%d ", dequeue(mergedQueue));
    }
    printf("\n");
    clearQueue(mergedQueue);
    free(mergedQueue);
    return 0;
}
