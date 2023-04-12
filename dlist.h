#ifndef DLIST_H
#define DLIST_H

typedef struct Node Node;
typedef struct Dlist Dlist;

Dlist* createDlist();
void deleteDlist(Dlist* dlist);
void insertFront(Dlist* dlist, int data);
void insertRear(Dlist* dlist, int data);
void deleteFront(Dlist* dlist);
void deleteRear(Dlist* dlist);
void deleteNode(Dlist* dlist, Node* node);
void printDlist(Dlist* dlist);
void reversePrintDlist(Dlist* dlist);
void rotateRight(Dlist* dlist, int k);

#endif
