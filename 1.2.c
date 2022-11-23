#include <stdio.h>
#include <stdlib.h>


// Task: Реализовать гномью сортировку>

size_t n = 0;
long* arr = NULL;

void sortType()
{
	size_t i;
	printf("Array size: ");
	scanf_s("%u", &n);

	arr = (long*)calloc(n, sizeof(long));

	for (i = 0; i < n; i++) 
	{
		printf("Array[%d] =  ", i);

		scanf_s("%d", &(arr[i] ));
	}
}

void sort()
{
	
	size_t i = 1; 

	while (i < n) 
	{
		if (i == 0) 
		{
			i = 1;
		}

			if (arr[i - 1] <= arr[i]) 
			{
				++i; 
			}

		else 
		{		
			long tmp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = tmp;
			--i;
		}
	}
}

void sortResult()
{
	size_t i;

	printf("Result: ");

	for (i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	sortType();
	sort();
	sortResult();
}

