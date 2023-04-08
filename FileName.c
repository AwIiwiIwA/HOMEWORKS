#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = -1;

void push(char ch) {
    if (top == STACK_SIZE - 1) 
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop() 
{
    if (top == -1) 
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

bool matchingPair(char left, char right) 
{
    if (left == '(' && right == ')')
        return true;
    else if (left == '[' && right == ']')
        return true;
    else if (left == '{' && right == '}')
        return true;
    else
        return false;
}

bool isBalanced(char exp[]) 
{
    int i = 0;
    while (exp[i]) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') 
        {
            if (top == -1 || !matchingPair(pop(), exp[i]))
                return false;
        }
        i++;
    }
    return (top == -1);
}

int main() 
{
    char exp[STACK_SIZE];
    printf("Enter an expression: ");
    fgets(exp, STACK_SIZE, stdin);

    if (isBalanced(exp))
        printf("The expression is balanced\n");
    else
        printf("The expression is not balanced\n");

    return 0;
}
