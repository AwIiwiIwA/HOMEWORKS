#pragma once

#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

//this function creates a new stack and returns a pointer to it
Stack* createStack();

//function adds a new element to the top of the stack
void push(Stack* s, int value);

//function removes the top element from the stack and returns its value
int pop(Stack* s);

//function checks if the stack is empty
int isEmpty(Stack* s);

//function deletes the stack and frees up the memory allocated to it
void deleteStack(Stack* s);

#endif