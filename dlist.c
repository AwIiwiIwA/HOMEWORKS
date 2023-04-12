#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

Dlist* createDlist()
{
	Dlist* dlist = (Dlist*)malloc(sizeof(Dlist));
	if (dlist == NULL)
	{
		return NULL;
	}
	dlist->front = NULL;
	dlist->rear = NULL;
	dlist->size = 0;
	return dlist;
}

void deleteDlist(Dlist* dlist)
{
	Node* curr = dlist->front;
	while (curr != NULL) {
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
	free(dlist);
}

void insertFront(Dlist* dlist, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return newNode;
	}
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = dlist->front;
	if (dlist->front == NULL)
	{
		dlist->rear = newNode;
	}
	else
	{
		dlist->front->prev = newNode;
	}
	dlist->front = newNode;
	dlist->size++;
}

void insertRear(Dlist* dlist, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return newNode;
	}
	newNode->data = data;
	newNode->prev = dlist->rear;
	newNode->next = NULL;
	if (dlist->rear == NULL)
	{
		dlist->front = newNode;
	}
	else
	{
		dlist->rear->next = newNode;
	}
	dlist->rear = newNode;
	dlist->size++;
}

void deleteFront(Dlist* dlist)
{
	if (dlist->front == NULL)
	{
		return;
	}
	Node* frontNode = dlist->front;
	dlist->front = frontNode->next;
	if (dlist->front == NULL)
	{
		dlist->rear = NULL;
	}
	else
	{
		dlist->front->prev = NULL;
	}
	free(frontNode);
	dlist->size--;
}

void deleteRear(Dlist* dlist)
{
	if (dlist->rear == NULL)
	{
		return;
	}
	Node* rearNode = dlist->rear;
	dlist->rear = rearNode->prev;
	if (dlist->rear == NULL)
	{
		dlist->front = NULL;
	}
	else
	{
		dlist->rear->next = NULL;
	}
	free(rearNode);
	dlist->size--;
}

void deleteNode(Dlist* dlist, Node* node)
{
	if (node == NULL)
	{
		return;
	}
	if (node == dlist->front)
	{
		deleteFront(dlist);
		return;
	}
	if (node == dlist->rear)
	{
		deleteRear(dlist);
		return;
	}
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	dlist->size--;
}

void shiftRight(Dlist* dlist, int k)
{
	if (k == 0 || dlist->size <= 1)
	{
		return;
	}
	k = k % dlist->size;
	if (k == 0)
	{
		return;
	}
	Node* curr = dlist->rear;
	for (int i = 0; i < k; i++)
	{
		curr = curr->prev;
	}
	dlist->rear->next = dlist->front;
	dlist->front->prev = dlist->rear;
	dlist->front = curr->next;
	dlist->rear = curr;
	dlist->rear->next = NULL;
	dlist->front->prev = NULL;
}