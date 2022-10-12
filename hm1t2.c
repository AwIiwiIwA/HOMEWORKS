#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf ("Input a: ");
	int a;
	scanf ("%d", &a);

	printf ("Input b: ");
	int b;
	scanf ("%d", &b);

	int result = 0;
	int moduleOfa = abs(a);
	int moduleOfb = abs(b);

	if (b == 0)
	{
		printf ("There are no solutions with the number 0");
	}
	else
	{
		while ((moduleOfa - result * moduleOfb >= moduleOfb) || (a < 0 && moduleOfa > result * moduleOfb))
		{
			result++;
		}
		if ((a > 0) ^ (b > 0))
		{
			result = -result;
		}

		printf("result: %d", result);
	}
	return 0;
}