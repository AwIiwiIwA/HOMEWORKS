#include <stdio.h>
#include "dlist.h"

int main()
{
	// Print Errors
	Dlist* dlist = createDlist();
	if (dlist == NULL)
	{
		printf("Failed to create dlist.\n");
		return 1;
	}

	insertFront(dlist, 5);
	insertRear(dlist, 10);

	if (dlist->size != 2)
	{
		printf("Size of dlist should be 2.\n");
		return 1;
	}

	deleteNode(dlist, dlist->front);
	deleteNode(dlist, dlist->front);

	if (dlist->size != 0)
	{
		printf("Size of dlist should be 0.\n");
		return 1;
	}
	shiftRight(dlist, 5);

	int n, x;
	printf("Enter number of elements: ");
	scanf_s("%d", &n);

	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		insertRear(dlist, x);
	}

	printf("Doubly linked list: ");
	Node* curr = dlist->front;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
	shiftRight(dlist, 2);
	printf("List after shifting right by 2: ");
	curr = dlist->front;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
	deleteNode(dlist, dlist->front->next);
	printf("List after deleting the second element: ");
	curr = dlist->front;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
	deleteDlist(dlist);
	return 0;
}

