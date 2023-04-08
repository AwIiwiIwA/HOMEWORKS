#include <stdio.h>

void reverse(int x[], int start, int end) 
{
    for(int i = start; i <= (start + end) / 2; i++)
    {
        int tmp = x[i];
        x[i] = x[end - i + start];
        x[end - i + start] = tmp;
    }
}

int main()
 {
    int m, n;
    printf("Enter the lengths of the two segments (m and n): ");
    scanf("%d %d", &m, &n);
    int x[m + n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < m + n; i++)
 {
        scanf("%d", &x[i]);
    }
    reverse(x, 0, m - 1); 
    reverse(x, m, m + n - 1); 
    reverse(x, 0, m + n - 1); 
    printf("The reversed array is: ");
    for(int i = 0; i < m + n; i++) 
{
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}
