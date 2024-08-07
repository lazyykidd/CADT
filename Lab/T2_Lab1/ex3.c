#include <stdio.h>
int main()
{
    int arr[9] = {3, -3, 1, 5, 7, 0, 8, 9, 6};
    int input, check = 0;
    printf("Input number : ");
    scanf("%d", &input);
    for (int i = 0; i < 9; i++)
    {
        if (input == arr[i])
        {
            check = 1;
        }
    }
    if (check == 1) 
    {
        printf("The number %d exists in the array. \n", input);
    }
    else
    {
        printf("The number %d does not exists in the array. \n", input);
    }

    return 0;
}
