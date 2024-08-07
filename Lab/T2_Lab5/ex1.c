#include <stdio.h>

double max(float a, float b)
{
    double greatest;

    if (a > b)
    {
        greatest = a;
    }
    else
    {
        greatest = b;
    }

    return greatest;
}

int main()
{
    float a, b, greatest;

    printf("Enter First number: ");
    scanf("%f", &a);

    printf("Enter Second number: ");
    scanf("%f", &b);

    greatest = max(a, b);

    printf("Greatest number: %.2f\n", greatest);
    return 0;
}
