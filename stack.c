#include <stdlib.h>
#include "stack.h"

#define ERROR_EMPTY_STACK -1
#define ERROR_ALLOCATING_MEMORY 1

struct node
{
    int value;
    struct node* next;
};

struct stack
{
    struct node* head;
};

Stack* createStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) 
    {
        return ERROR_ALLOCATING_MEMORY; 
    }
    s->head = NULL;
    return s;
}

void push(Stack* s, int value)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) 
    {
        return ERROR_ALLOCATING_MEMORY; 
    }
    newNode->value = value;
    newNode->next = s->head;
    s->head = newNode;
}

int pop(Stack* s)
{
    if (s->head == NULL)
    {
        return ERROR_EMPTY_STACK; // stack is empty
    }
    int value = s->head->value;
    struct node* temp = s->head;
    s->head = s->head->next;
    free(temp);
    return value;
}

int isEmpty(Stack* s)
{
    return s->head == NULL;
}

void deleteStack(Stack* s)
{
    while (s->head != NULL)
    {
        pop(s);
    }
    free(s);
}
