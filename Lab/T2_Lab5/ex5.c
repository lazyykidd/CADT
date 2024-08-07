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

int sum(int n)
{
    if (n < 0)
    {
        printf("Error! \n");
        return -1; 
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

double square(double Z)
{
    return sqrt(Z);
}

int prime(int k)
{
    if (k <= 1)
        return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            return 1; // Not a prime number
        }
    }
    return 0; // Is a prime number
}

int main()
{
    while (1) //Infinite Looping to make user keep inputting until they select option 5 to exit this loop 
    {
        printf("Choose an operation: ");
        int choice;
        printf("\n1. Factorial\n2. Sum of numbers\n3. Square root of number\n4. Prime number\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter n: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, fac(n));
            break;
        }
        case 2:
        {
            int x;
            printf("Enter n: ");
            scanf("%d", &x);
            int result = sum(x);
            if (result != -1) //check if result is valid
            {
                printf("Summation from 1 to %d is %d\n", x, result);
            }
            break;
        }
        case 3:
        {
            double Z;
            printf("Enter n: ");
            scanf("%lf", &Z);
            printf("sqrt of %.2f is %.2f\n", Z, square(Z));
            break;
        }
        case 4:
        {
            int k;
            printf("Enter n: ");
            scanf("%d", &k);
            if (prime(k) == 0)
            {
                printf("%d is a prime number\n", k);
            }
            else
            {
                printf("%d is not a prime number\n", k);
            }
            break;
        }
        case 5:
            printf("Program Exited.!\n");
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
