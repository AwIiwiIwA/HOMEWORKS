#ifndef DLIST_H
#define DLIST_H

typedef struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

typedef struct Dlist
{
	Node* front;
	Node* rear;
	int size;
} Dlist;

// creates a new empty doubly linked list and returns a pointer to it
Dlist* createDlist();

// frees the memory used by the doubly linked list and its nodes
void deleteDlist(Dlist* dlist);

// inserts a new node with the given data at the front of the doubly linked list
void insertFront(Dlist* dlist, int data);

// inserts a new node with the given data at the rear of the doubly linked list
void insertRear(Dlist* dlist, int data);

// removes the node at the front of the doubly linked list
void deleteFront(Dlist* dlist);

// removes the node at the rear of the doubly linked list
void deleteRear(Dlist* dlist);

// removes the given node from the doubly linked list
void deleteNode(Dlist* dlist, Node* node);

// shifts all the nodes in the doubly linked list k positions to the right
void shiftRight(Dlist* dlist, int k);


#endif
