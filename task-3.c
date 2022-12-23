#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int check(const char* s)
{
    char symbol = toupper(s[0]);// Проверяем первый символ. 
    if ((!isdigit(symbol) || symbol == '0') && (symbol < 'A' || symbol > 'E'))
    {
        return 0;
    }

    const char* p = &s[1];  // указатель на второй символ
    int badch = 0, okAfterBadch = 0;  // был ли другой символ (.), был ли нужный символ после него
    while (*p) {
        symbol = toupper(*p++);  // очередной символ
        if (!isdigit(symbol) && (symbol < 'A' || symbol > 'E')) // другой символ
        {
            if (badch) { return 0; }
            badch = 1;
            okAfterBadch = 0;
        }
        else
        {
            okAfterBadch = 1;
        }
    }
    return okAfterBadch;
}

int main()
{
    setlocale(LC_ALL, "ru");
    printf("Эта программа реализует конечный автомат , задаваемый следующим регулярным выражением \n [1-9 A-E a-e][0-9 A-E a-e]*.[0-9 A-E a-e]+ \n");
    printf("Введите данные:");
    char s[256];
    gets_s(s, 256);  // ввод строки
    printf("1 - Все верно!\n");
    printf("0 - Не верно!\n\n");
    printf("Результат = %d", check(s));
}
