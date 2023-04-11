#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1000

int main()
{
    FILE* inFile, * outFile;
    char line[MAX_LINE_LENGTH];
    int maxLength = 0, lineLength;

    errno_t err = fopen_s(&inFile, "input.txt", "r");
    if (err != 0) 
    {
        printf("Ошибка открытия файла: %d", err);
        return 1;
    }
    while (fgets(line, MAX_LINE_LENGTH, inFile)) 
    {
        lineLength = strlen(line);
        if (lineLength > maxLength)
        {
            maxLength = lineLength;
        }
    }

    fclose(inFile);

    err = fopen_s(&outFile,"output.txt", "w");
    if (outFile == NULL) 
    {
        printf("Ошибка при открытии выходного файла");
        return 1;
    }

    err = fopen_s(&inFile,"input.txt", "r");
    while (fgets(line, MAX_LINE_LENGTH, inFile))
    {
        lineLength = strlen(line);
        int num_spaces = maxLength - lineLength;
        for (int i = 0; i < num_spaces; i++) 
        {
            fputc(' ', outFile);
        }
        fputs(line, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    return 0;
}
