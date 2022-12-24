#include <stdio.h>
#include <stdlib.h>


float expLinear(float number, int power) 
{
    if (power == 0) 
        return 1;
    float result = 1;
    int pow = abs(power);
    for (int i = 1; i <= pow; i++)
    {
        result *= number;
    }
    if (power < 0) return (1 / result);
    return result;
}

float expLogN(float number, int power)
{
    if (power == 0) 
        return 1;
    int pow = abs(power);
    float result = 1;
    while (pow != 0) 
    {
        if (pow & 1)
        {
            result *= number;
            pow--;
        }
        number *= number;
        pow = (int)pow / 2;
    }
    if (power < 0) 
        return (1 / result);
    return result;
}


int main() 
{
    printf("This program calculates entered number to the of entered power(if it is integer)\nEnter number: ");
    int power = 0;
    float number = 0;
    scanf_s("%f", &number);
    printf("Enter power: ");
    scanf_s("%d", &power);
    printf("The result Log(n) %f\n", expLogN(number, power));
    printf("The result Linear %f\n", expLinear(number, power));
    
    return 0;
}
