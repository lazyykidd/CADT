#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fac(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fac(n - 1);
    }
}
int seila(int n)
{
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
        return n + seila(n - 1);
    }
}

double square(double Z)
{
    double square = sqrt(Z);
    return sqrt(Z);
}
int prime(int k)
{
    int i;
    for (i = 2; i < k; i++)
    {
        if (k % i == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    printf("Choose an operation: ");
    int choice;
    printf("\n1. Factorial\n2. Sum of numbers\n3.Square root of number\n4.Prime number\n5.Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        int n;
        printf("Enter n: ");
        scanf("%d", &n);
        printf("Factorial of %d is %d", n, fac(n));
        break;
    case 2:
        int x;
        printf("Enter n: ");
        scanf("%d", &x);
        int result = seila(x);
        printf("Summation from 1 to %d is %d", x, result);
        break;
    case 3:
        double Z, square;
        printf("Enter n: ");
        scanf("%lf", &Z);
        square = sqrt(Z);
        printf("sqrt of %.2f is %.2f", Z, square);
        break;
    case 4:
        int k, prime1;
        printf("Enter n: ");
        scanf("%d", &k);
        prime1 = prime(k);
        if (prime1 == 0)
        {
            printf("%d is a prime number", k);
        }
        else
        {
            printf("%d is not a prime number", k);
        }
        break;
    case 5:
        return 1;
        break;
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}
