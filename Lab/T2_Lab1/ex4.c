#include <stdio.h>
int main(void)
{
    float scores[10], average = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf("%f", &scores[i]);
        average += scores[i];
    }
    printf("Average is %f.", average / 10);

    for (int i = 0; i < 10; i++)
    {
        if (scores[i] > (average / 10))
        {
            printf("\nScore %f is above average.", scores[i]);
        }
    }

    return 0;
}