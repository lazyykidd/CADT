#include <stdio.h>

void addition(int *a, int b)
{
    *a = *a + b;
}

int main()
{
    int a = 9;
    int b = 2;

    int *p_a = NULL;

    // display a, b
    printf("Before swap: (a:%d, b:%d)\n", a, b);

    /* swap value of a and b */
    int temp = a;
    a = b;
    b = temp;

    /* display a, b */
    printf("After swap: (a:%d, b:%d)\n", a, b);

    /* pointer point to a */
    p_a = &a;

    // Correct pointer to integer assignment
    int *p_b = &b;

    /* display a, b */
    printf("Before sum: (a:%d, b:%d)\n", a, b);

    /* a equal to a + b */
    addition(p_a, b);

    /* display a, b */
    printf("After sum: (a:%d, b:%d)\n", a, b);

    return 0;
}
