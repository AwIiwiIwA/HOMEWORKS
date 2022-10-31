#include <stdio.h>
#include <math.h>

//Ðåàëèçîâàòü âîçâåäåíèå â ñòåïåíü — â ëîá (çà ëèíåéíîå âðåìÿ) è çà Î(log n).

int power()
{
	printf("Write a number");
	int x;
	scanf_s("%i", &x);

	printf("Write a power of number");
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
