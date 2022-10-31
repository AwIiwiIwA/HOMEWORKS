#include <stdio.h>

//Написать программу, считающую количество нулевых элементов в массиве.

int nullCounter(int *arr, int len)
{
	int counter = 0;
	for (int i = 0; i < len; i++) 
	{
		if (arr[i] == 0)
			counter++;
	}

	return counter;
}

int main()
{
	const int A[] = {1,2,0,4,5,6,7,8,0};

	printf("Nulls %i", nullCounter(&A,9));

	return 0;
}