#include <stdio.h>
#include <math.h>

//Реализовать возведение в степень — в лоб (за линейное время) и за О(log n).

int power()
{
	printf("Write a number");
	int x;
	scanf_s("%i", &x);

	printf("Write a number");
	int n;
	scanf_s("%i", &n);

	int y = 1;

	

	for (int i = 1; i <= n; i++)
	{
		y = y * x;
	}

	printf("%i",y);
	return y;
}

int main()
{
	
	power();

	return 0;
	
}