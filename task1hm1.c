#include <stdio.h>

//Написать программу, считающую значение формулы x4 + x3 + x2 + x + 1 за два умножения.

float f(float x)
{
	float y = x * x;
	return y * (y + x) + y + x + 1;
}

int main()
{

	printf("Do u want an answer to this exaple?  x^4 + x^3 + x^2 + x + 1\n");

	float x = 0;

	printf("Pls write x = ");
	scanf_s("%f", &x);
	printf("x^4 + x^3 + x^2 + x = %f \n", f(x));

	return 0;
}