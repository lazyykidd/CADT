#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int id;
    char surname[10];
    char name[10];
    int age;
    char sex;
}s[100];

int total_students;
int student_count = 0;

void studentInfo()
{

    printf("How many students info you want to input?\n");
    scanf("%d", &total_students);
    for (int i = 0; i < total_students; i++)
    {
        printf("\nStudent %d", i + 1);
        printf("\nID: ");
        scanf("%d", &s[i].id);
        printf("\nSurname: ");
        scanf("%s", s[i].surname);
        printf("\nName: ");
        scanf("%s", s[i].name);
        printf("\nAge: ");
        scanf("%d", &s[i].age);
        printf("\nSex: ");
        scanf("%c", &s[i].sex);
        while ((getchar()) != '\n');
    }
}

void studentArray(struct student new_student)
{
    if (student_count < 100)
    {
        s[student_count] = new_student;
        student_count++;
    }
    else
    {
        printf("Array is full, cannot add more students.\n");
    }
}

void studentDel(int id)
{
    int found = 0;
    for (int i = 0; i < student_count; i++)
    {
        if (s[i].id == id)
        {
            found = 1;
            for (int j = i; j < student_count - 1; j++)
            {
                s[j] = s[j + 1];
            }
            student_count--;
            printf("Student with ID %d deleted.\n", id);
            break;
        }
    }
    if (!found)
    {
        printf("Student with ID %d not found.\n", id);
    }
}

void studentDisp(int id)
{
    for (int i = 0; i < student_count; i++)
    {
        if (s[i].id == id)
        {
            printf("Student ID: %d\n", s[i].id);
            printf("Surname: %s\n", s[i].surname);
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n", s[i].age);
            printf("Sex: %c\n", s[i].sex);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void option()
{
    struct student new_student;
    int id;
    int choice;
    while (1)
    {
        printf("1. Enter Student's information");
        printf("\n2. Add Student to arrays");
        printf("\n3. Delete Student");
        printf("\n4. Display Student information");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            studentInfo();
            break;
        case 2:
            studentArray(new_student);
            break;
        case 3:
            printf("Enter the student ID to delete: ");
            scanf("%d", &id);
            studentDel(id);
            break;
        case 4:
            printf("Enter the student ID to display: ");
            scanf("%d", &id);
            studentDisp(id);
            break;
        default:
            break;
        }
    }
}

int main()
{

    option();
    return 0;
}