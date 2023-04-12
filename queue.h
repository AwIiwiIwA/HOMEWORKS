#ifndef QUEUE_H
#define QUEUE_H
// Header file for a Queue data structure

typedef struct queue Queue;
// Create a new Queue and return a pointer to it
Queue* createQueue();

// Add an item to the back of the Queue
void enqueue(Queue* queue, int data);

// Remove and return the front item from the Queue
int dequeue(Queue* queue);

// Return 1 if the Queue is empty, 0 otherwise
int empty(Queue* queue);

// Remove all items from the Queue
void clearQueue(Queue* queue);

// Free all memory associated with the Queue
void deleteQueue(Queue* queue);
#endif