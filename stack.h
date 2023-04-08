#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


typedef struct node 
{
    int data;
    struct node* next;
} Node;


typedef struct stack 
{
    Node* top;
} Stack;

void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int isEmpty(Stack* s);

#endif

