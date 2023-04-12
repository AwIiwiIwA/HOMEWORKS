#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main()
{
    DList* list = createDlist();
    int n, data;
    printf("Enter the number of elements: ");
    scanf_s("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &data);
        insertBack(list, data);
    }
    if (symmetric(list)) 
    {
        printf("The list is symmetric.\n");
    }
    else 
    {
        printf("The list is not symmetric.\n");
    }
    clearDlist(list);
    free(list);
    return 0;
}