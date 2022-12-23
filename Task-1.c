#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ru");// просто установка ру 
    const char* rome[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    const int arab[13] = { 1000, 900, 500, 400,  100, 90,   50,  40,   10,  9,    5,    4,   1 };
    printf("Эта программа переводит Римские цифры в Арабаские.\n");
    printf("Введите Римские числа такие как  M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I \n");
    char size[256];
    gets_s(size, 256);
    int indexResult = 0, i = 0;  // результат и индекс римского числа
    char* positionOfLine = size;  // указатель на текущую позицию строки
    while (*positionOfLine && i < 13)
    {
        while (1) //1 это true
        {
            int remainedLenght = strlen(positionOfLine);  // длина остатка строки
            int romeLength = strlen(rome[i]);  // длина римского числа
            if (remainedLenght < romeLength || _strnicmp(positionOfLine, rome[i], romeLength) != 0) { break; }  // если остаток строки короче или её часть не равна римской цифре, прерываем цикл while
            indexResult += arab[i];
            positionOfLine += romeLength;
        }
        ++i;  // к следующему римскому числу!
    }
    if (*positionOfLine != '\0')
    {
        printf("Неверный ввод!\n");
    }
    else
    {
        printf("Результат = %d\n", indexResult);
    }
}

