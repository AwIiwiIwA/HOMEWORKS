#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// I am did't do maxsize , because my IDE cant scanf this.

int IncomingDataStatus(char symbol, char state) 
{
    switch (symbol)
    {
        case 1:
        {
            if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
            {
                state = 1;
            }
        }
        case 2:
        {
            if (symbol >= '0' && symbol <= '9')
            {
                state = 1;
            }
        }
        case 3:
        {
            if (symbol == "_")
            {
                state = 1;
            }

        }
        case 4:
        {
            if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z') || (symbol >= '0' && symbol <= '9') || (symbol == "_"))
            {
                state = 1;
            }
            else;
            {
                state = 2; // state can be 0,1. 2 is false.

            }
        }
     break;
    }
    return state;
}

bool isCorrectString(char *string)
{
    int state = 0;
    for (; *string != "/0"; string++)
    {
        state = IncomingDataStatus(*string, IncomingDataStatus);
        if (IncomingDataStatus == 2)
        {
            return false;
        }
    }
    return state == 1;
}

bool trueTests()
{
    char test1[] = "MyNameIs_Agent007";
    char test2[] = "F";
    

    return isCorrectString(test1) &&
        isCorrectString(test2);
}

bool falseTests()
{
    char test3[] = "_Rtfjkflf";
    char test4[] = "A_+m-9";

    return !isCorrectString(test3) &&
        !isCorrectString(test4);
       
}
 
int main()
{
    if (trueTests == (false))
    {
        printf("TRUE TEST FAILED , try again \n\n");
        return 0;
    }
    if (falseTests == (false))
    {
        printf("FALSE FAILED , try again \n\n");
        return 0;
    }
    char string[] = { 0 };
    printf("\nThis program can do the regular expression [A-Za-z] ([A-Za-z] | [0-9] | _ )*\n");
    printf("Enter the string to test perogram:");
    printf("(pls write only (decimal):\n");
    scanf("%s", string); //I cant check prog is working or not because %s crash scan

    if (isCorrectString(string))
    {
        printf("\"%s\"It's correct regular expression: \n", string);
    }
    else
    {
        printf("\"%s\" Ii's not regular expression: :(\n", string);
    }

    return 0;
}
