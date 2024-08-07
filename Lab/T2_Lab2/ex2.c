#include <stdio.h>

int main()
{
    int row_1, col_1, row_2, col_2, i, n, row, col;
    do
    {
        printf("Input Row and Column for Array 1 : ");
        scanf("%d %d", &row_1, &col_1);
        printf("Input Row and Column for Array 2 : ");
        scanf("%d %d", &row_2, &col_2);
        if ((row_1 != row_2) || (col_1 != col_2))
        {
            printf("Both array must have the same size!! \n");
        }
        else if (row_1 == 0 || row_2 == 0 || col_1 == 0 || col_2 == 0)
        {
            printf("Array with 0 demisenal is not Exit \n");
        }
        else
        {
            printf("\n");
        }
    } while ((row_1 != row_2) || (col_1 != col_2) || row_1 == 0 || row_2 == 0 || col_1 == 0 || col_2 == 0);
    row = row_1;
    col = col_1;

    int array1[row_1][col_1], array2[row_2][col_2], sum[row][col], sub[row][col];
    printf("Input value for array1 \n");
    for (i = 0; i < row_1; i++)
    {
        for (n = 0; n < col_1; n++)
        {
            printf("Elements [%d][%d] : ", i, n);
            scanf("%d", &array1[i][n]);
        }
    }
    printf("Input value for array2 \n");
    for (i = 0; i < row_2; i++)
    {
        for (n = 0; n < col_2; n++)
        {
            printf("Elements [%d][%d] : ", i, n);
            scanf("%d", &array2[i][n]);
        }
    }
    for (i = 0; i < row_2; i++)
    {
        for (n = 0; n < col_2; n++)
        {
            sum[i][n] = array1[i][n] + array2[i][n];
            sub[i][n] = array1[i][n] - array2[i][n];
        }
    }
    printf("Result of sum : ");
    for (i = 0; i < row_2; i++)
    {
        for (n = 0; n < col_2; n++)
        {
            printf("%d ", sum[i][n]);
        }
    }
    printf("\n");
    printf("Result of sub : ");
    for (i = 0; i < row_2; i++)
    {
        for (n = 0; n < col_2; n++)
        {
            printf("%d ", sub[i][n]);
        }
    }
    return 0;
}