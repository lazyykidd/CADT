#include <stdio.h>

int main()
{
    int n = 0;
    do
    {
        printf("How many names: ");
        scanf("%d", &n);
    } while (n <= 0);

    char names[n][100];
    for (int i = 0; i < n; i++)
    {
        printf("Names %d: ", i + 1);
        scanf("%s", names[i]);
    }
    if (n == 1)
    {
        printf("This name is: %s\n", names[0]);
    }
    else
    {
        printf("Those %d names are: ", n);
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                printf("and %s", names[j]);
            }
            else
            {
                printf("%s, ", names[j]);
            }
        }
    }
    return 0;
}