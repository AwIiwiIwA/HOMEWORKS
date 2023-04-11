#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 256

typedef struct
{
	int data[MAX_LIST_SIZE];
	int length;
} List;

void initializeList(List* list)
{
	list->length = 0;
}

void printList(List list)
{
	printf("\nList: ");
	for (int i = 0; i < list.length; i++)
	{
		printf("%d ", list.data[i]);
	}
	printf("\n");
}

void insertIntoList(List* list, int value)
{
	int i = 0;
	while (i < list->length && list->data[i] < value)
	{
		i++;
	}
	for (int j = list->length; j > i; j--)
	{
		list->data[j] = list->data[j - 1];
	}
	list->data[i] = value;
	list->length++;
}

int removeFromList(List* list, int index)
{
	if (index >= list->length || index < 0)
	{
		printf("Invalid index.\n");
		return -1;
	}
	int value = list->data[index];
	memmove(&list->data[index], &list->data[index + 1], (list->length - index - 1) * sizeof(int));
	list->length--;
	return value;
}

void sumIntoList(List* list, int index1, int index2)
{
	if (index1 >= list->length || index2 >= list->length || index1 < 0 || index2 < 0) {
		printf("Invalid indices.\n");
		return;
	}
	int value1 = list->data[index1];
	int value2 = list->data[index2];
	int sum = value1 + value2;
	insertIntoList(list, sum);
}

int main()
{
	List list;
	initializeList(&list);
	char input[100];
	char* command, * valueOneStr, * valueTwoStr;
	int value1, value2;
	char *context;
	
	while (1)
	{
		printf("\n\n\n");
		printf("This program can do that!\n");
		printf("-----------------------------------------------\n");
		printf("EXIT\n");
		printf("ADD <value : int> \n");
		printf("REMOVE <index : int> \n");
		printf("SUM <index1 : int> <index2 : int> \n");
		printf("PRINT \n");
		printf("-----------------------------------------------\n\n");
		printf("Enter a command: ");

		fgets(input, sizeof(input), stdin);
		command = strtok_s(input, " \n",&context);
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else if (strcmp(command, "add") == 0)
		{
			valueOneStr = strtok_s(NULL, " \n",&context);
			if (valueOneStr == NULL) 
			{
				printf("Invalid arguments.\n");
				continue;
			}
			value1 = atoi(valueOneStr);
			insertIntoList(&list, value1);
		}
		else if (strcmp(command, "remove") == 0)
		{
			valueOneStr = strtok_s(NULL, " \n",&context);
			if (valueOneStr == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			value1 = atoi(valueOneStr);
			int removedValue = removeFromList(&list, value1);
			if (removedValue != -1)
			{
				printf("Removed value: %d\n", removedValue);
			}
		}
		else if (strcmp(command, "sum") == 0)
		{
			valueOneStr = strtok_s(NULL, " \n",&context);
			valueTwoStr = strtok_s(NULL, " \n",&context);
			if (valueOneStr == NULL || valueTwoStr == NULL)
			{
				printf("Invalid arguments.\n");
				continue;
			}
			value1 = atoi(valueOneStr);
			value2 = atoi(valueTwoStr);
			sumIntoList(&list, value1, value2);
		}
		else if (strcmp(command, "print") == 0)
		{
			printList(list);
		}
		else
		{
			printf("Invalid command.\n");
		}
	}
	return 0;
}