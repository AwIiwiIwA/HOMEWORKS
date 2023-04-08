#include <stdio.h>
#include <stdbool.h>

bool check_balance(char str[]) 
{
    int count_parentheses = 0;
    int count_brackets = 0;
    int count_braces = 0;
    for(int i = 0; str[i] != '\0'; i++)
{
        if(str[i] == '(') 
{

            count_parentheses++;
        }
        else if(str[i] == ')') 
{
            count_parentheses--;
        }
        else if(str[i] == '[') 
{
            count_brackets++;
        }
        else if(str[i] == ']')
{
            count_brackets--;
        }
        else if(str[i] == '{') 
{
            count_braces++;
        }
        else if(str[i] == '}') 
{
            count_braces--;
        }
        if(count_parentheses < 0 || count_brackets < 0 || count_braces < 0) 
{
            return false;
        }
    }
    return (count_parentheses == 0 && count_brackets == 0 && count_braces == 0);
}

int main() 
{
    char str[100];
    printf("Enter a string with parentheses, brackets, and braces: ");
    fgets(str, sizeof(str), stdin);
    if(check_balance(str)) {
        printf("The parentheses, brackets, and braces are balanced.\n");
    }
    else 
{
        printf("The parentheses, brackets, and braces are not balanced.\n");
    }
    return 0;
}
