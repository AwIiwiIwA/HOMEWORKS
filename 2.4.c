#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ARRAY_SIZE 10

//task 2.4
//Написать программу, которая заполняет массив случайными значениями (с использованием функции rand из stdlib.h), 
//потом преобразует его без использования дополнительных массивов так, что в начале массива будут элементы, меньшие первого,
//а в конце — большие либо равные первому. Программа должна работать за линейное время.


void swap(int* firstElement, int* secondElement)
{
    int transitElement = *firstElement;
    *firstElement = *secondElement;
    *secondElement = transitElement;
}


void partition(int* array, int size)
{
    int pivot = array[0];
    int pivotIndex = 0;
    int separatingIndexOfPivot = 0;

    for (int i = 1; i < ARRAY_SIZE; ++i)
    {
        if (array[i] < pivot)
        {
            swap(&array[i], &array[pivotIndex]);
            if (array[i] == pivot) separatingIndexOfPivot = i;
            ++pivotIndex;
        }
    }
    if (array[pivotIndex] != pivot)
    {
        swap(&array[separatingIndexOfPivot], &array[pivotIndex]);
    }
}

void main()
{
    setlocale(LC_ALL, "ru");
    printf("\n     Эта программа которая заполняет массив случайными значениями,");
    printf("\n     потом преобразует его без использования дополнительных массивов так,");
    printf("\n     что в начале массива будут элементы, меньшие первого,");
    printf("\n     а в конце — большие либо равные первому\n\n");
    int array[ARRAY_SIZE] = { 0 };
    int size = 0;
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        array[i] = rand() % 32;
    }
    printf("\n   Массив до: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", array[i]);
    partition(array,size);
    printf("\n   Массив после: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) printf("%d ", array[i]);
    printf("\n\n\n");
}