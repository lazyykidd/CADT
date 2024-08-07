#include <stdio.h>

void power(float *x, const int n)
{
    float result = 1.0;
    for (int i = 0; i < n; ++i)
    {
        result *= *x; // or result = result * *x;
    }
    *x = result;
}

int main()
{
    float x;
    int n;
    int *p_x = '\0';

    printf("Enter a number and its power: ");
    if (scanf("%f, %d", &x, &n) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    power(&x, n);
    printf("Result = %.2f\n", x);

    return 0;
}
