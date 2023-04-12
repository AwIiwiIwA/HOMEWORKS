#pragma once

#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack* createStack();
void push(Stack* s, int value);
int pop(Stack* s);
int isEmpty(Stack* s);
void deleteStack(Stack* s);

#endif