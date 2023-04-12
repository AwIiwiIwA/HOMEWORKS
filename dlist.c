#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

DList* createDlist() 
{
    DList* newList = (DList*)malloc(sizeof(DList));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

void insertFront(DList* list, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL) 
    {
        list->head->prev = newNode;
    }
    else 
    {
        list->tail = newNode;
    }
    list->head = newNode;
    list->size++;
}

void insertBack(DList* list, int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;
    if (list->tail != NULL)
    {
        list->tail->next = newNode;
    }
    else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->size++;
}

void deleteFront(DList* list)
{
    if (list->head != NULL)
    {
        Node* temp = list->head;
        list->head = list->head->next;
        if (list->head != NULL)
        {
            list->head->prev = NULL;
        }
        else 
        {
            list->tail = NULL;
        }
        free(temp);
        list->size--;
    }
}

void deleteBack(DList* list)
{
    if (list->tail != NULL)
    {
        Node* temp = list->tail;
        list->tail = list->tail->prev;
        if (list->tail != NULL) 
        {
            list->tail->next = NULL;
        }
        else {
            list->head = NULL;
        }
        free(temp);
        list->size--;
    }
}

void clearDlist(DList* list)
{
    Node* current = list->head;
    Node* temp;
    while (current != NULL) 
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int symmetric(DList* list)
{
    Node* front = list->head;
    Node* back = list->tail;
    while (front != back && front->prev != back) 
    {
        if (front->data != back->data) 
        {
            return 0;
        }
        front = front->next;
        back = back->prev;
    }
    return 1;
}
