#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void buildPrefixTable(const char* str, int* table) {
    int len = strlen(str);
    table[0] = 0;
    for (int i = 1, j = 0; i < len; i++) {
        while (j > 0 && str[i] != str[j]) {
            j = table[j - 1];
        }
        if (str[i] == str[j]) {
            j++;
        }
        table[i] = j;
    }
}

int countSubstring(const char* s, const char* s1) {
    int s_len = strlen(s);
    int s1_len = strlen(s1);
    int table[MAX_LEN];
    buildPrefixTable(s1, table);

    int i = 0, j = 0, count = 0;
    while (i < s_len) {
        if (s[i] == s1[j]) {
            i++;
            j++;
        }
        if (j == s1_len) {
            count++;
            j = table[j - 1];
        }
        else if (i < s_len && s[i] != s1[j]) {
            if (j != 0) {
                j = table[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    char s[100], s1[100];
    printf("Enter the main string: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter the substring: ");
    fgets(s1, sizeof(s1), stdin);
    s[strcspn(s, "\n")] = 0;
    s1[strcspn(s1, "\n")] = 0;
    int count = countSubstring(s, s1);
    printf("The substring \"%s\" occurs %d times in the string \"%s\".\n", s1, count, s);
    return 0;
}
