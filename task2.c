#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ru");
    printf("Эта программа ищет Седловые точки матрицы.\n\n");
    FILE* f;
    if (fopen_s(&f, "matrix.txt", "r") != 0)// открываем файл для чтения
    {
        printf("Ошибка открытия файла!\n");
        return -1;
    }
    int rows, cols = 0;
    if (fscanf_s(f, "%d %d\n", &rows, &cols) < 2 || rows < 1 || cols < 1)  // читаем кол-во строк и столбцов
    {
        printf("Кол-во строк или столбцов не может быть меньше 1 (или их нет)!\n");
        return -1;
    }
    int* matrix = (int*)
        malloc(rows * cols * sizeof(int));  // Читаем данные из файла

    for (int j = 0; j < rows; ++j)
    {
        for (int i = 0; i < cols; ++i)
        {
            if (fscanf_s(f, "%d", &matrix[i + j * cols]) < 1)
            {
                printf("Ошибка чтения (мало данных?)!\n");
                return -1;
            }
        }
    }
    for (int j = 0; j < rows; ++j)
    {
        int min, max;  // мин\макс значения в строке
        min = matrix[j * cols];
        max = min;
        for (int i = 1; i < cols; ++i) // столбцы
        {
            if (matrix[i + j * cols] < min)// минимум в строке
            {
                min = matrix[i + j * cols];
            }
            if (matrix[i + j * cols] > max)// максимум в строке
            {
                max = matrix[i + j * cols];
            }
        }
        for (int i = 0; i < cols; ++i)
        {
            int saddlePoint = 0;  // седловая точка? (1/0)
            if (matrix[i + j * cols] == min)
            {
                saddlePoint = 1;
                for (int k = 0; k < rows; ++k)
                {
                    if (min < matrix[i + k * cols])
                    {
                        saddlePoint = 0;  // не максимальная в столбце
                        break;
                    }
                }
            }
            if (!saddlePoint && matrix[i + j * cols] == max)
            {
                saddlePoint = 1;
                for (int k = 0; k < rows; ++k)
                {
                    if (max > matrix[i + k * cols])
                    {
                        saddlePoint = 0;  // не минимальная в столбце
                        break;
                    }
                }
            }
            if (saddlePoint)
            {
                printf("Седловая точка в строке %d столбце %d = %d\n", j + 1, i + 1, matrix[i + j * cols]);
            }
        }
    }
}
