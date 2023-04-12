#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QueueIsEmpty 1
#define MemoryAllocationFailed 1


typedef struct node
{
    int data;
    struct node* next;
} Node;

struct queue 
{
    Node* front;
    Node* rear;
    int size;
};

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return MemoryAllocationFailed;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue()
{
    Queue* newQueue = (Queue*)
        malloc(sizeof(Queue));
    if (!newQueue) 
    {
        printf("Error: Memory allocation failed\n");
        return MemoryAllocationFailed;
    }
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}


void enqueue(Queue* queue, int data)
{
    Node* newNode = createNode(data);
    if (empty(queue))
    {
        queue->front = newNode;
    }
    else 
    {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

int dequeue(Queue* queue) 
{
    if (empty(queue))
    {
        printf("Error: Queue is empty\n");
        return QueueIsEmpty;
    }
    Node* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;
    queue->size--;
    free(frontNode);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return data;
}

int empty(Queue* queue)
{
    return queue->size == 0;
}

void clearQueue(Queue* queue)
{
    while (!empty(queue)) 
    {
        dequeue(queue);
    }
}

void deleteQueue(Queue* queue)
{
    clearQueue(queue);
    free(queue);
}
