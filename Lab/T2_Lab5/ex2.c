#include <stdio.h>
// Write a function that can calculate the summation of 3 integers.

int sum(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

int main(){
    int num1, num2, num3;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter third number:");
    scanf("%d", &num3);
    printf("Sum of the numbers is %d", sum(num1, num2, num3));
    return 0;
}