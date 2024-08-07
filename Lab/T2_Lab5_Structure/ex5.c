#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
struct Student
{
    int id;
    char surname[50];
    char name[50];
    int age;
    char sex;
} s[100];

void studentInfo(int *n);
void studentAdd(int *n);
void studentDel(int *n);
void studentDisplay(int n);

int main()
{
    int option, n;
    do
    {
        printf("===========>> Student <<===========\n");
        printf("\t1. Input Student\n");
        printf("\t2. Add Student\n");
        printf("\t3. Delete Student\n");
        printf("\t4. Display Student\n");
        printf("\t5. Exit\n");
        printf("===================================\n");
        do
        {
            printf("Enter your option: ");
            scanf("%d", &option);
            if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
            {
                printf("Error! Invalid option, Choose again.\n");
            }
        } while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5);

        switch (option)
        {
        case 1:
            printf("Enter the number of student: ");
            scanf("%d", &n);
            studentInfo(&n);
            break;

        case 2:
            studentAdd(&n);
            break;

        case 3:
            studentDel(&n);
            break;

        case 4:
            studentDisplay(n);
            break;

        case 5:
            exit(8);
            break;
        }

        printf("Please, press \"Enter\" to continue.....\n\n");
    } while (getch() == 13);
    return 0;
}

void studentInfo(int *n)
{
    int i;
    for (i = 0; i < *n; i++)
    {
        printf("======== Student %d ========\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter Surname: ");
        scanf("%s", s[i].surname);
        printf("Enter name: ");
        scanf("%s", &s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter sex (M/F): ");
        scanf(" %c", &s[i].sex);
        printf("=============================\n\n");
    }
}
void studentAdd(int *n)
{
    int i, add;
    printf("Enter the number of student to add: ");
    scanf("%d", &add);
    for (i = *n; i < *n + add; i++)
    {
        printf("======== Student %d ========\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter Surname: ");
        scanf("%s", s[i].surname);
        printf("Enter name: ");
        scanf("%s", &s[i].name);
        printf("Enter age: ");
        scanf("%d", &s[i].age);
        printf("Enter sex (M/F): ");
        scanf(" %c", &s[i].sex);
        printf("=============================\n\n");
    }
    *n += add;
    printf("Add new student successful...!\n\n");
}
void studentDel(int *n)
{
    int check = 0;
    int i, j, delete;
    printf("Enter ID's student to delete: ");
    scanf("%d", &delete);

    for (i = 0; i < *n; i++)
    {
        if (delete == s[i].id)
        {
            for (j = i; j < *n; j++)
            {
                s[j] = s[j + 1];
            }
            *n--;
            check = 1;
            printf("Delete ID's student %d successful...!\n\n", delete);
            break;
        }
    }
    if (check == 0)
        printf("Delete ID's student %d not successful...!\n\n", delete);
}
void studentDisplay(int n)
{
    int check = 0;
    int i, display;
    printf("Enter ID's student to display: ");
    scanf("%d", &display);
    for (i = 0; i < n; i++)
    {
        if (display == s[i].id)
        {
            printf("=======>> Student %d <<=======\n", i + 1);
            printf("ID: %d\n", s[i].id);
            printf("Surname: %s\n", s[i].surname);
            printf("Name: %s\n", s[i].name);
            printf("Age: %d\n", s[i].age);
            printf("Sex: %c\n", s[i].sex);
            printf("=============================\n\n");
            check = 1;
        }
    }
    if (check == 0)
        printf("ID's student %d not found...!\n\n", display);
}