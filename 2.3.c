#include <stdio.h>

//Написать сортировки пузырьком и подсчётом.

int bubbleSort(int* num, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j])
			{
			int s = num[j - 1];
			num[j - 1] = num[j];
			num[j] = s;
			return 0;
			}
	
		}
	}

}
 

int main()
{
	int a[10];

	for (int i = 0; i < 10; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
	bubbleSort(a, 10);
	for (int i = 0; i < 10; i++)
	
		printf("%d ", a[i]);

	
	

	return 0;
}