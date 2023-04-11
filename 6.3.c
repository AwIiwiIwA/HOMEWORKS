#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 15

typedef struct Record
{
	char name[MAX_NAME_LEN];
	char phone[MAX_PHONE_LEN];
	struct Record* next;
} Record;

Record* merge(Record* list1, Record* list2, int by_name)
{
	Record* result = NULL;

	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	if ((by_name && strcmp(list1->name, list2->name) < 0) || (!by_name && strcmp(list1->phone, list2->phone) < 0))
	{
		result = list1;
		result->next = merge(list1->next, list2, by_name);
	}
	else
	{
		result = list2;
		result->next = merge(list1, list2->next, by_name);
	}

	return result;
}

void split(Record* source, Record** front, Record** back)
{
	Record* fast;
	Record* slow;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}

void mergeSort(Record** list, int by_name)
{
	Record* head = *list;
	Record* front;
	Record* back;

	if (head == NULL || head->next == NULL)
	{
		return;
	}

	split(head, &front, &back);

	mergeSort(&front, by_name);
	mergeSort(&back, by_name);

	*list = merge(front, back, by_name);
}

void printList(Record* list)
{
	while (list != NULL)
	{
		printf("%s - %s\n", list->name, list->phone);
		list = list->next;
	}
}

int main()
{
	int by_name;
	char name[MAX_NAME_LEN];
	char phone[MAX_PHONE_LEN];
	Record* head = NULL;
	Record* current = NULL;
	Record* prev = NULL;

	printf("Sort by name (1) or phone number (0)?\n");
	scanf_s("%d", &by_name, sizeof(by_name));
	scanf_s("%*c"); 

	FILE* fp;
	char filename[] = "name.txt";
	errno_t err = fopen_s(&fp, filename, "r");
	if (err != 0)
	{
		printf("Can't open file\n");
		return 1;
	}

	if (fp == NULL)
	{
		printf("Error: could not open file.\n");
		return 1;
	}

	while (fscanf_s(fp, "%s %s", name, MAX_NAME_LEN, phone, MAX_PHONE_LEN) == 2)
	{
		current = (Record*)malloc(sizeof(Record));
		strncpy_s(current->name, MAX_NAME_LEN, name, MAX_NAME_LEN);
		strncpy_s(current->phone, MAX_PHONE_LEN, phone, MAX_PHONE_LEN);
		current->next = NULL;

		if (prev == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}

		prev = current;
	}

	fclose(fp);

	mergeSort(&head, by_name);
	printf("\nSorted list:\n");
	printList(head);

	return 0;
}