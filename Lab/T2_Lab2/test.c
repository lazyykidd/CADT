#include <stdio.h>

int main()
{
    int size;

    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    int arr1[size], arr2[size], sum[size], difference[size];

    printf("Enter elements for array 1:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements for array 2:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr2[i]);
    }

    // Element-wise addition
    for (int i = 0; i < size; i++)
    {
        sum[i] = arr1[i] + arr2[i];
    }

    // Element-wise subtraction
    for (int i = 0; i < size; i++)
    {
        difference[i] = arr1[i] - arr2[i];
    }

    printf("Original arrays:\n");
    printf("Array 1: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Sum of arrays:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sum[i]);
    }
    printf("\n");

    printf("Difference of arrays:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", difference[i]);
    }
    printf("\n");

    return 0;
}
