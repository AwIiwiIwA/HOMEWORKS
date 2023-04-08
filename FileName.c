#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define _CRT_SECURE_NO_WARNINGS

int checkBalance(char* str)
{
	int len = strlen(str);
	Stack s;
	s.top = NULL;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			push(&s, str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (isEmpty(&s))
			{
				return 0;
			}
			int c = pop(&s);
			if ((str[i] == ')' && c != '(') || (str[i] == ']' && c != '[') || (str[i] == '}' && c != '{'))
			{
				return 0;
			}
		}
	}
	return isEmpty(&s);
}

int main()
{
	char str[100];
	printf("Enter a string of brackets: ");
	scanf_s("%s", str);

	if (checkBalance(str))
	{
		printf("The brackets are balanced.\n");
	}
	else
	{
		printf("The brackets are not balanced.\n");
	}

	return 0;
}

