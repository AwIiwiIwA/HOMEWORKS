#include <stdio.h>
#define maxAvailableNumber 100000

int main() 
{
    int numbers[maxAvailableNumber] = { 0 };
    int maxNumber = 0;

    printf("This program writes simple numbers ");

    scanf_s("%d", &maxNumber);

    if (maxNumber <= 1)
    {
        printf("There are not simple number\a ", maxNumber);

        return 0;
    }
    for (int i = 2; i <= maxNumber; i++)    
    {
        numbers[i - 2] = i;
    }
    int divider = 0;

    for (int p = 0; p <= maxNumber; p++)
    {
        if (numbers[p] != 0) 
        {
            divider = numbers[p];

            for (int k = p + 1; k <= maxNumber; k++) 
            {
                if (numbers[k] % divider == 0) 
                {
                    numbers[k] = 0;
                }
            }
        }
    }
    printf("Simple numbers:\n");

    for (int i = 0; i <= maxNumber; i++) 
    {
        if (numbers[i] != 0) printf("%d ", numbers[i]);
    }
    return 0;
}