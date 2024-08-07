#include <stdio.h>
int main()
{
    FILE *f;
    char filename[50];
    printf("Input a file: ");
    scanf("%s", &filename);
    f = fopen(filename, "r");
    char string[100];
    if (f != NULL)
    {
        while (fgets(string, 100, f) != NULL)
        {
            printf("%s", string);
        }
    }
    else
    {
        printf("Error");
    }
    fclose(f);
    return 0;
}
