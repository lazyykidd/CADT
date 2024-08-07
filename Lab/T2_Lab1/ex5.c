#include <stdio.h>
int main(void)
{
    float scores[7];
    for (int i = 0; i < 7; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf("%f", &scores[i]);
    }
    float min = scores[0], max = scores[0];

    // maximum
    for (int i = 0; i < 7; i++)
    {
        if (scores[i] < min)
        {
            min = scores[i];
        }

        if (scores[i] > max)
        {
            max = scores[i];
        }
    }

    printf("Minimum is %f.Maximum is %f", min, max);

    return 0;
}