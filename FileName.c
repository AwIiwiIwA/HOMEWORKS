#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CHARS 256


char findMostFrequentChar(char* str, int len) 
{
    int i, j;
    int max_count = 0; 
    char most_frequent_char; 
    int count[MAX_CHARS] = { 0 }; 

    
    for (i = 0; i < len; i++) 
    {
        count[str[i]]++;
    }

    
    for (j = 0; j < MAX_CHARS; j++) 
    {
        if (count[j] > max_count) 
        {
            max_count = count[j];
            most_frequent_char = j;
        }
    }

    return most_frequent_char;
}

int main() 
{
    char str[] = "hello world"; 
    int len = strlen(str); 
    char most_frequent_char = findMostFrequentChar(str, len); 
    printf("The most frequent character in the string is '%c'\n", most_frequent_char);
    return 0;
}
