#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
// This header file declares the structures and functions for a doubly linked list implementation.

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DList
{
    Node* head;
    Node* tail;
    int size;
} DList;

// Creates a new doubly linked list and returns a pointer to it.
DList* createDlist();

// Inserts a new node with the given data at the front (head) of the list.
void insertFront(DList* list, int data);

// Inserts a new node with the given data at the back (tail) of the list.
void insertBack(DList* list, int data);

// Deletes the node at the front (head) of the list.
void deleteFront(DList* list);

// Deletes the node at the back (tail) of the list.
void deleteBack(DList* list);

// Deletes all nodes in the list and frees the memory used by them.
void clearDlist(DList* list);
void printDlist(DList* list);

// Checks if the list is symmetric ( reads the same forwards and backwards) and returns 1 if it is, 0 otherwise.
int symmetric(DList* list);

#endif