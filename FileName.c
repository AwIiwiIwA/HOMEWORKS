#include <stdio.h>
#include <stdbool.h>

bool prime(int num) 
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimes(int max_num)
{
    for (int i = 2; i <= max_num; i++) 
    {
        if (prime(i)) {
            printf("%d ", i);
        }
    }
}

int main() 
{
    int max_num;
    printf("Enter a number: ");
    scanf_s("%d", &max_num);
    printf("Prime numbers up to %d: ", max_num);
    printPrimes(max_num);
    printf("\n");
    return 0;
}