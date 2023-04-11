#include <stdio.h>
#include <errno.h>

int calculateTotalCost()
{
    FILE* file;
    char currentCharacter = 0;
    int totalSum = 0;
    int amountOfGoods = 0;
    int price = 0;
    int scanRes = 0;
    errno_t err = fopen_s(&file, "order.txt", "r");
    if (err != 0 || file == NULL)
    {
        printf("Can't open file!\n");
        return 1;
    }

    while (!feof(file))
    {

        while (currentCharacter != '\t' && !feof(file))
        {
            currentCharacter = fgetc(file);
            if (currentCharacter == '\n')
            {
                printf("Incorrect file structure.\n");
                fclose(file);
                return 0;
            }
        }

        if (feof(file))
        {
            break;
        }

        scanRes = fscanf_s(file, "%d", &amountOfGoods);
        if (scanRes == 0 || amountOfGoods <= 0)
        {
            printf("Incorrect file structure.\n");
            fclose(file);
            return 0;
        }

        scanRes = fscanf_s(file, "%d", &price);
        if (scanRes == 0 || price <= 0)
        {
            printf("Incorrect file structure.\n");
            fclose(file);
            return 0;
        }
        if ((currentCharacter = fgetc(file)) != '\n' && currentCharacter != EOF)
        {
            printf("Incorrect file structure.\n");
            fclose(file);
            return 0;
        }

        totalSum += amountOfGoods * price;

        if (totalSum <= 0)
        {
            printf("Incorrect file structure.\n");
        }
    }

    if (totalSum > 0)
    {
        printf("Total order value: %d\n", totalSum);
    }

    fclose(file);
    return 0;
}

int main()
{
    calculateTotalCost();
    return 0;
}