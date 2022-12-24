#include <stdio.h>
#include <stdbool.h>

#define SIZE 47

int recursivelyFibonacci(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return recursivelyFibonacci(num - 2) + recursivelyFibonacci(num - 1);
}

int iteractiveFibonacci(int num)
{
    int currentNum = 1;
    int previousNum = 1;
    for (int i = 2; i <= num; i++)
    {
        int temp = currentNum;
        currentNum = previousNum + currentNum;
        previousNum = temp;
    }
    return currentNum;
}

int main()
{
    int number = 0;
    int scan_res = 0;
    bool isIncorrectInput = true;

    do
    {
        isIncorrectInput = true;

        printf("Enter which Fibonacci number you want to output: ");
        scan_res = scanf_s("%d", &number);

        if (!scan_res || !isIncorrectInput || number < 0 || number >= SIZE)
        {
            printf("Incorrect input (the number must be (>= 0) %d). Try again!\n", SIZE);
            scanf_s("%*[^\n]");

            isIncorrectInput = false;
        }
    } while (!scan_res || !isIncorrectInput);

    printf("The Fibonacci number of %d is %d\n", number, iteractiveFibonacci(number));
    printf("And also the %d Fibonacci number is %d\n", number + 1, recursivelyFibonacci(number + 1));
}