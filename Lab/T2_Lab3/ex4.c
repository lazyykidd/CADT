#include <stdio.h>
#include <string.h>
#include <conio.h>
void shift_left(char *str, int n);
int main()
{
    char str[100];
    int n;
    printf("Enter string : ");
    scanf("%[^\n]", str);
    printf("Enter n: ");
    scanf("%d", &n);
    shift_left(str, n);
    printf("%s", str);
    return 0;
}
void shift_left(char *str, int n)
{
    int len = strlen(str);
    if (n >= len)
    {
        *str = '\0';
    }

    for (int i = 0; i < n; i++)
    {
        // Shift remaining characters one position left
        for (int j = 0; j < len; j++)
        {
            str[j] = str[j + 1];
        }
        // Null-terminate the string after shifting
        str[len - i] = '\0';
    }
}
