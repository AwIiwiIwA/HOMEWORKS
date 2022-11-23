#include<stdio.h>
#include <conio.h>

#define N 10

void test()
{
    int numbers[N];
    int i, j;

    for (i = 0; i < N; i++)
    {
        printf("numbers[%d] = ", i);
        scanf_s("%d", &numbers[i]);
    }


    for (i = 0; i < N; i++)
    {
        for (j = i; j < N - 1; j++)
        {
            if (numbers[i] == numbers[j + 1])
            {
                printf("Dublicate num %d \n", numbers[i]);
            }
        }
    }

}
int main()
{
    test();
    return 0;
}
