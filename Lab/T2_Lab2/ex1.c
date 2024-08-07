#include <stdio.h>

int main()
{

    int size_arr1, size_arr2;

    printf("Enter Array Size 1: ");
    scanf("%d", &size_arr1);
    printf("Enter Array Size 2: ");
    scanf("%d", &size_arr2);

    if (size_arr1 != size_arr2)
    {
        printf("Invalid: Array sizes are not equal.\n");
        return 1;
    }

    int arr1[size_arr1], arr2[size_arr2];
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int sum[size], sub[size];

    printf("Enter Array1: ");
    for (int i = 0; i < size_arr1; i++)
    {
        
        scanf("%d", &arr1[i]);
    }

    printf("Enter Array2: ");
    for (int i = 0; i < size_arr2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < size; i++)
    {
        sum[i] = arr1[i] + arr2[i];
    }

    for (int i = 0; i < size; i++)
    {
        sub[i] = arr1[i] - arr2[i];
    }

    printf("===== Inputted Array =====\n");
    printf("First Array: ");
    for (int i = 0; i < size_arr1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\nSecond Array: ");
    for (int i = 0; i < size_arr2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("Additional Array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", sum[i]);
    }
    printf("\nSubtractional Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sub[i]);
    }
    printf("\n");

    return 0;
}
