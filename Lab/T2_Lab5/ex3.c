#include <stdio.h>
#include <stdlib.h>
// Write a function that can calculate the summation from 1 to n positive number where n is passed as parameter.
int sum(int n)
{
    int result;
    if (n < 0)
    {
        printf("Error!");
        exit(8);
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}

int main()
{
    int n;
    printf("Enter: ");
    scanf("%d", &n);
    printf("Sum: %d", sum(n));
    return 0;
}
