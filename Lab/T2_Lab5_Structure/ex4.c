#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DoB
{
    int day;
    int month;
    int year;
};

struct student
{
    struct DoB dob;
    char surname[50];
    char name[50];
} students[10];

int main()
{

    for (int i = 0; i < 10; i++)
    {
        printf("\nStudent number %d \n", i + 1);
        printf("Enter a student surname: ");
        scanf("%s", students[i].surname);

        printf("Enter a student name: ");
        scanf("%s", students[i].name);
        printf("Enter a student date of birth (day month year): ");
        scanf("%d %d %d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
    }

    int day = students[0].dob.day;
    int month = students[0].dob.month;
    int year = students[0].dob.year;

    printf("Show student that is the youngest: \n");
    for (int i = 0; i < 10; ++i)
    {
        if (students[i].dob.year > year)
        {
            year = students[i].dob.year;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        if (students[i].dob.year == year)
        {
            if (students[i].dob.month > month)
            {
                month = students[i].dob.month;
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {

        if (students[i].dob.month == month)
        {
            if (students[i].dob.day > day)
            {
                day = students[i].dob.day;
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        if ((students[i].dob.year == year) && (students[i].dob.month == month) && (students[i].dob.day == day))
        {
            printf("Show student that is the youngest: \n");
            printf("Student's number %d\n", i + 1);
            printf("Student: %s\n", students[i].surname);
            printf("Student's name: %s\n", students[i].name);
            printf("Student date of birth (day month year): %d %d %d\n", students[i].dob.day, students[i].dob.month, students[i].dob.year);
        }
    }

    return 0;
}
