#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack 
{
    int top;
    int items[MAX_SIZE];
};

void initializeStack(struct Stack* stack)
{
    stack->top = -1;
}

int isStackEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return 1;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(struct Stack* stack) 
{
    if (isStackEmpty(stack))
    {
        printf("Stack Underflow\n");
        return 1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

void reverseArray(int arr[], int size)
{
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < size; i++)
    {
        push(&stack, arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = pop(&stack);
    }
}

int main()
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter size of array: ");
    scanf_s("%d", &size);

    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf_s("%d", &arr[i]);
    }

    reverseArray(arr, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
