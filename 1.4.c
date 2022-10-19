#include <stdio.h>
#define sumAmount 

int main()
{
    int sums[sumAmount] = {0};

    for (int firstNumb = 0; firstNumb <= 9; firstNumb++) 
    {
        for (int sndNumb = 0; sndNumb <= 9; sndNumb++) 
        {
            for (int thirdNumb = 0; thirdNumb <= 9; thirdNumb++) 
            {
                sums[firstNumb + sndNumb + thirdNumb]++;
            }
        }
    }
    int happyTickets = 0;

    for (int i = 0; i < sumAmount; i++) 
    {
        happyTickets += sums[i] * sums[i];
    }

    printf("Amount of happy tickets: %d", happyTickets);
    return 0;
}
