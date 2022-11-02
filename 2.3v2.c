#include <stdio.h>


//Написать сортировки пузырьком и подсчётом.


#define range 2001

int sortOfNumbers() {
    int num[range] = { 0 }, element = 0, numAmount = 0, enteredNumsAmount = 0;

    printf("This program sorts numbers (from -1000 to 1000)." "\nEnter the number of amount: ");

    scanf_s("%d", &numAmount);

   

    while (enteredNumsAmount != numAmount)
    {
        printf("Element: ");

        scanf_s("%d", &element);

        if (element < -1000 || element > 1000)
        {
            printf("Look at the first line \n",
                numAmount - enteredNumsAmount);
        }
        else {
            num[element + 1000]++;
            enteredNumsAmount++;
        }
    }

   for (int i = 0; i < range; i++) 
   {
        for (int j = 0; j < num[i]; j++)
        {

            printf("%d ", i - 1000);
        }
    }
   
}

int main()
{
    sortOfNumbers();
    printf("\n");

    return 0;

}