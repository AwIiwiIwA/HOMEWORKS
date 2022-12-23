#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

#define SIZE 32

void decimalToBinary(unsigned char *binaryNumber, int number)
{
    int bit = 1;
    for (int i = SIZE - 1; i >= 0; --i)
    {
        binaryNumber[i] = number & bit ? 1 : 0;
        bit <<= 1;
    }
}

int binaryToDecimal(unsigned char *binaryNumber)
{
    int decimalNumbers = 0;
    int power = 1;
    for (int i = SIZE - 1; i >= 0; --i)
    {
        decimalNumbers += binaryNumber[i] * power;
        power *= 2;
    }
    return decimalNumbers;
}

void array(unsigned char* array, int arrayLength)
{
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

void sumOfBinary(unsigned char *sumResult, unsigned char *firstBinNum, unsigned char *secondBinNum)
{
    int bit = 0;
    int extraSum = 0;
    for (int i = SIZE - 1; i >= 0; --i)
    {
        extraSum = firstBinNum[i] + secondBinNum[i] + bit;
        sumResult[i] = extraSum & 1;
        bit = extraSum >> 1;
    }
}

bool test()
{
    int firstNumbers[3] = {1, 10, 77};
    int secondNumbers[3] = {-1, 90, -76};
    int firstNumber = 0;
    int secondNumber = 0;
    unsigned char firstBinNum[SIZE] = {0};
    unsigned char secondBinNum[SIZE] = {0};
    unsigned char binarySumResult[SIZE] = {0};
    for (int i = 0; i < 3; ++i)
    {
        decimalToBinary(firstBinNum, firstNumbers[i]);
        decimalToBinary(secondBinNum, secondNumbers[i]);
        sumOfBinary(binarySumResult, firstBinNum, secondBinNum);
        if (binaryToDecimal(binarySumResult) != firstNumbers[i] + secondNumbers[i])
        {
            return false;
        }
    }
    return true;
}

void main()
{
    setlocale(LC_ALL, "");
    if (!test())
    {
        printf("Тест провален!\n");
        return;
    }

    int firstNumber = 0;
    int secondNumber = 0;
    unsigned char firstBinNum[SIZE] = {0};
    unsigned char secondBinNum[SIZE] = {0};
    unsigned char binarySumResult[SIZE] = { 0 };
    int scanResult = 0;
    while (scanResult < 2)
    {
        printf("Введите два числа:");
        scanResult = scanf_s("%d%d", &firstNumber, &secondNumber);
        if (scanResult < 2)
        {
            printf("Не правильный ввод, повторите попытку!\n");
            scanf_s("%*[^\n]");
        }
    }

    decimalToBinary(firstBinNum, firstNumber);
    printf("Перевод первого числа из десятичного в бинарные: ");
    array(firstBinNum, SIZE);

    decimalToBinary(secondBinNum, secondNumber);
    printf("\nПеревод первого числа из десятичного в бинарные: ");
    array(secondBinNum, SIZE);

    sumOfBinary(binarySumResult, firstBinNum, secondBinNum);
    printf("\n \nДвоичная сумма ваших чисел:");
    array(binarySumResult, SIZE);

    printf("Десятичная сумма ваших чисел: %d", binaryToDecimal(binarySumResult));
}