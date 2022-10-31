	
#include <stdio.h>		

//Реализовать вычисление чисел Фибоначчи рекурсивно(и убедиться, что при n ~37 уже заметно медленно), реализовать итеративно, почувствовать разницу.


int fibonacci(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int antiFibonacci(int n)
{
	int a = 0, b = 1, c;

	while (n != 0)
	{
		c = a + b;
		printf("%i\n", c );
		a = b;
		b = c;
		n--;
	}

}

int main()
{
	antiFibonacci(37);

	return 0;
}
