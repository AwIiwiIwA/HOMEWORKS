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
    printf("How you want to calculate it?\nIf by quick algorithm (log(n)) enter'1', if by simple algorithm '2': \n");
    int choice = 0;
    scanf_s("%d", &choice);
    while (!(choice == 1 || choice == 2)) 
    {
        printf("You can enter only '1' or '2'. Try again\nHow you want to calculate it? If by quick algorithm"
            " enter '1', if by simple algorithm '2': ");
        scanf_s("%d", &choice);
    }
    if (choice == 1)
    {
        printf("The result is %f\n", expLogN(number, power));
    }
    else 
    {
        printf("The result is %f\n", expLinear(number, power));
    }
    return 0;
}