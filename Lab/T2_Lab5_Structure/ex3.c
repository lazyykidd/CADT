#include <stdio.h>

struct student
{
    char surname[10];
    char name[10];
    int age;
} student[10];

int main()
{

    for (int i = 0; i < 10; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("\nSurname: ");
        scanf("%s", &student[i].surname);
        printf("\nName: ");
        scanf("%s", &student[i].name);
        printf("\nAge: ");
        scanf("%d", &student[i].age);
    }

    int youngest = 0;
    for (int j = 0; j < 2; j++)
    {
        if (student[youngest].age > student[j].age)
        {
            youngest = j;
        }
    }

    for (int k = 1; k <= 1; k++)
    {
        printf("The youngest is: %s %s %d\n", student[youngest].name, student[youngest].surname, student[youngest].age);
    }
    return 0;
}