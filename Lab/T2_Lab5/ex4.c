#include <stdio.h>
#include <string.h>

int charExists(char str[], char ch)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char str[100];
    char ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (charExists(str, ch))
    {
        printf("The character '%c' exists in the string '%s'.\n", ch, str);
    }
    else
    {
        printf("The character '%c' does not exist in the string '%s'.\n", ch, str);
    }

    return 0;
}
