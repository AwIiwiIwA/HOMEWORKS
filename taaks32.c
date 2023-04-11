#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue
{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void enqueue(Queue* q, int value)
{
    if (q->rear == MAX_QUEUE_SIZE - 1) 
    {
        printf("Queue is full\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue* q)
{
    if (q->front > q->rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return  q->data[q->front++];
}

int main()
{
    int n;
    printf("Enter the number of elements in the queues: ");
    scanf_s("%d", &n);

    Queue one, two, three;
    one.front = two.front = three.front = 0;
    one.rear = two.rear = three.rear = -1;

    printf("Enter %d elements for queue 1: ", n);
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf_s("%d", &val);
        enqueue(&one, val);
    }

    printf("Enter %d elements for queue 2: ", n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf_s("%d", &val);
        enqueue(&two, val);
    }

    for (int i = 0; i < n; i++) 
    {
        enqueue(&three, dequeue(&one));
        enqueue(&three, dequeue(&two));
    }

    printf("Merged queue: ");
    for (int i = 0; i < 2 * n; i++) 
    {
        printf("%d ", dequeue(&three));
    }
    printf("\n");

    return 0;
}
