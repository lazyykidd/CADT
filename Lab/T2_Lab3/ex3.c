#include <stdio.h>
#include <string.h>
#include <conio.h>
void filter(char *str, char c);
int main()
{
    char str[100], c;
    printf("Enter string : ");
    scanf("%[^\n]", str);
    printf("Enter char : ");
    scanf(" %c", &c);
    filter(str, c);
    printf("%s", str);
    return 0;
}
void filter(char *str, char c)
{
    char *res = str;
    while (*str)
    {
        if (*str != c)
        {
            *res++ = *str;
        }
       str++;
    }
    *res = '\0';
}