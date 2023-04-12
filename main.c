#include <stdio.h>
#include "stack.h"

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf_s("%d", &n);
    Stack* s = createStack();
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf_s("%d", &x);
        push(s, x);
    }
    printf("Reversed array:\n");
    while (!isEmpty(s))
    {
        printf("%d ", pop(s));
    }
    deleteStack(s);
    return 0;
}
