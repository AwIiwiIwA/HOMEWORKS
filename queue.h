#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int empty(Queue* queue);
void clearQueue(Queue* queue);
void deleteQueue(Queue* queue);

#endif
