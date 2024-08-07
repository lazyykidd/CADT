#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct time
{
    int time_HH;
    int time_MM;
};

typedef struct
{
    int day;
    struct time tim;
    char subject[50];
    char lecturer[50];
} Schedule;

Schedule schedule;

//============================================   addschedule    ===============================================================================================================
// Function to check if the given time is valid
int isValidTime(int hour, int minute)
{
    if (hour < 0 || hour > 23)
        return 0;
    if (minute < 0 || minute > 59)
        return 0;
    return 1;
}

void day_option(int day)
{
    switch (day)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;

    default:
        printf("event");
        break;
    }
}

void addSchedule()
{
    while (1)
    {
        system("cls"); // clear screen
        Schedule term;
        FILE *fb, *ft;
        fb = fopen("addSchedule.txt", "a+");
        // to open file addSchedule.txt
        if (fb == NULL) // check it found or not
        {
            printf("File does not exist");
            exit(8);
        }
        while (1)
        {
            printf("1.Monday\n");
            printf("2.Tuesday\n");
            printf("3.Wednesday\n");
            printf("4.Thursday\n");
            printf("5.Friday\n");
            printf("Enter the day of the week (1-5):\n> ");
            scanf("%d", &schedule.day);
            if (schedule.day >= 1 && schedule.day <= 5)
            {
                break;
            }
            else
            {
                printf("Invalid input! Please enter a number between 1 and 5.\n");
            }
        }
        // input
        fflush(stdin);
        printf("Subject:\n> ");
        scanf("%[^\n]s", &schedule.subject);
        fflush(stdin);
        printf("lecture:\n> ");
        scanf("%[^\n]s", &schedule.lecturer);
        fflush(stdin);
        while (1)
        {
            printf("Time (HH MM):\n> ");
            scanf("%d %d", &schedule.tim.time_HH, &schedule.tim.time_MM);
            if (isValidTime(schedule.tim.time_HH, schedule.tim.time_MM))
            {
                break;
            }
            else
            {
                printf("Invalid time! Please enter a valid time (HH MM).\n");
            }
        }

        int found = 0;
        while (fgets(term.subject, 100, fb) != NULL)
        {
            fgets(term.lecturer, 100, fb);
            fscanf(fb, "%d %d %d", &term.day, &term.tim.time_HH, &term.tim.time_MM);

            if ((term.day == schedule.day) && (term.tim.time_HH == schedule.tim.time_HH))
            {
                found = 1;
            }
        }

        if (found == 1)
        {
            printf("Schedule already added at this date!!\nPlease try again!!!\n");
        }
        else
        {
            printf("End\n> Added Successfully!!\n");
            // input data in file
            fputs(schedule.subject, fb);
            fputs("\n", fb);
            fputs(schedule.lecturer, fb);
            fputs("\n", fb);
            fprintf(fb, "%d %d %d", schedule.day, schedule.tim.time_HH, schedule.tim.time_MM);
        }
        // input in file
        fclose(fb);

        printf("\n\nPress 'a' to continue ......... \npress 'b' for exit\n/....>");
        int ch = getch();
        if (ch == 'a')
        {
            printf("\n");
        }
        else if (ch == 'b')
        {
            break;
        }
    }
}

//============================================   deleteschedule    ===============================================================================================================
void deleteSchedule()
{
    while (1)
    {
        system("cls");
        FILE *fb, *ft;
        fb = fopen("addSchedule.txt", "r");
        if (fb == NULL)
        {
            printf("Error: File does not exist or cannot be opened.\n");
            exit(8);
        }
        ft = fopen("new.txt", "a");
        if (ft == NULL)
        {
            printf("Error: File does not exist or cannot be opened.\n");
            exit(8);
        }

        int day, time;
        char subject[50];
        printf("Enter Subject: ");
        fflush(stdin);
        scanf("%[^\n]s", &subject);
        fflush(stdin);
        printf("Enter time(HH): ");
        scanf("%d", &time);
        printf("Enter day: ");
        scanf("%d", &day);
        int found = 0;
        while (fgets(schedule.subject, 100, fb) != NULL)
        {
            fgets(schedule.lecturer, 100, fb);
            fscanf(fb, "%d %d %d", &schedule.day, &schedule.tim.time_HH, &schedule.tim.time_MM);
            if (schedule.day == day && schedule.tim.time_HH == time)
            {
                if (strstr(schedule.subject, subject) != NULL)
                {
                    day_option(schedule.day);
                    found = 1;
                    // Process and display the read schedule information
                    printf("\n________________________________________\nSubject: %s\n", schedule.subject);
                    printf("Lecturer: %s\n", schedule.lecturer);
                    printf("Time: %d:%02d\n________________________________________\n", schedule.tim.time_HH, schedule.tim.time_MM);
                }
                else
                {
                    fputs(schedule.subject, ft);
                    fputs(schedule.lecturer, ft);
                    fprintf(ft, "%d %d %d", schedule.day, schedule.tim.time_HH, schedule.tim.time_MM);
                }
            }
            else
            {
                fputs(schedule.subject, ft);
                fputs(schedule.lecturer, ft);
                fprintf(ft, "%d %d %d", schedule.day, schedule.tim.time_HH, schedule.tim.time_MM);
            }
        }
        fclose(fb);
        fclose(ft);

        if (found == 0)
        {
            printf("No schedule found for this time and day\n");
        }
        remove("addSchedule.txt");
        rename("new.txt", "addSchedule.txt");

        printf("\n\nPress 'a' to continue ......... \npress 'b' for exit\n/....>");
        int ch = getch();
        if (ch == 'a')
        {
            printf("\n");
        }
        else if (ch == 'b')
        {
            break;
        }
    }
}

//============================================   viewSchedules    ===============================================================================================================

void viewSchedules()
{
    system("cls");
    int day;
    FILE *fb;
    fb = fopen("addSchedule.txt", "r");
    if (fb == NULL)
    {
        printf("Error: File does not exist or cannot be opened.\n");
        exit(8);
    }

    while (fgets(schedule.subject, 100, fb) != NULL)
    {
        fgets(schedule.lecturer, 100, fb);
        fscanf(fb, "%d %d %d", &schedule.day, &schedule.tim.time_HH, &schedule.tim.time_MM);
        day_option(schedule.day);
        // // Process and display the read schedule information
        printf("\n________________________________________\nSubject:%s", schedule.subject);
        printf("Lecturer: %s", schedule.lecturer);
        printf("Time: %d:%d\n________________________________________\n", schedule.tim.time_HH, schedule.tim.time_MM);
    }

    fclose(fb);
}

//============================================   searchScheduleBySubject    ===============================================================================================================

void searchScheduleBySubject()
{
    system("cls");
    FILE *fb;
    fb = fopen("addSchedule.txt", "r");
    if (fb == NULL)
    {
        printf("Error: File does not exist or cannot be opened.\n");
        exit(8);
    }

    char subject[100];
    fflush(stdin);
    printf("Enter subject to search: ");
    scanf("%[^\n]s", subject);
    fflush(stdin);
    int found = 0;
    // search
    while (fgets(schedule.subject, 100, fb) != NULL)
    {
        fgets(schedule.lecturer, 100, fb);
        fscanf(fb, "%d %d %d", &schedule.day, &schedule.tim.time_HH, &schedule.tim.time_MM);
        if (strstr(schedule.subject, subject) != NULL)
        {
            day_option(schedule.day);
            found = 1;
            // // Process and display the read schedule information
            printf("\n________________________________________\nSubject:%s", schedule.subject);
            printf("Lecturer: %s", schedule.lecturer);
            printf("Time: %d:%02d\n________________________________________\n", schedule.tim.time_HH, schedule.tim.time_MM);
        }
    }

    fclose(fb);
    if (found == 0)
    {
        printf("No schedule found for subject: %s\n", subject);
    }
}
//============================================   searchScheduleByLecturer    ===============================================================================================================

void searchScheduleByLecturer()
{
    system("cls");
    FILE *fb;
    fb = fopen("addSchedule.txt", "r");
    if (fb == NULL)
    {
        printf("Error: File does not exist or cannot be opened.\n");
        exit(8);
    }

    char lecturer[100];
    fflush(stdin);
    printf("Enter subject to lecturer: ");
    scanf("%[^\n]s", lecturer);
    fflush(stdin);
    int found = 0;
    // search
    while (fgets(schedule.subject, 100, fb) != NULL)
    {
        fgets(schedule.lecturer, 100, fb);
        fscanf(fb, "%d %d %d", &schedule.day, &schedule.tim.time_HH, &schedule.tim.time_MM);
        if (strstr(schedule.lecturer, lecturer) != NULL)
        {
            day_option(schedule.day);
            found = 1;
            // // Process and display the read schedule information
            printf("\n________________________________________\nSubject:%s", schedule.subject);
            printf("Lecturer: %s", schedule.lecturer);
            printf("Time: %d:%02d\n________________________________________\n", schedule.tim.time_HH, schedule.tim.time_MM);
        }
    }

    fclose(fb);
    if (found == 0)
    {
        printf("No schedule found for subject: %s\n", lecturer);
    }
}

//============================================   searchSchedulebyday    ===============================================================================================================

void searchScheduleByDay()
{
    system("cls");
    FILE *fb;
    fb = fopen("addSchedule.txt", "r");
    if (fb == NULL)
    {
        printf("Error: File does not exist or cannot be opened.\n");
        exit(8);
    }

    int day;
    while (1)
    {
        printf("1.Monday\n");
        printf("2.Tuesday\n");
        printf("3.Wednesday\n");
        printf("4.Thursday\n");
        printf("5.Friday\n");
        printf("Enter the day of the week (1-5):\n> ");
        fflush(stdin);
        scanf("%d", &day);
        if (day >= 1 && day <= 5)
        {
            break;
        }
        else
        {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
        }
    }
    int found = 0;
    while (fgets(schedule.subject, 100, fb) != NULL)
    {
        fgets(schedule.lecturer, 100, fb);
        fscanf(fb, "%d %d %d", &schedule.day, &schedule.tim.time_HH, &schedule.tim.time_MM);

        if (schedule.day == day)
        {

            day_option(schedule.day);
            found = 1;
            // Process and display the read schedule information
            printf("\n________________________________________\nSubject: %s\n", schedule.subject);
            printf("Lecturer: %s\n", schedule.lecturer);
            // printf("Date: %d/%d/%d\n", schedule.dat.date_DD, schedule.dat.date_MM, schedule.dat.date_YY);
            printf("Time: %d:%d\n________________________________________\n", schedule.tim.time_HH, schedule.tim.time_MM);
        }
    }

    fclose(fb);
    if (found == 0)
    {
        printf("No schedule found for subject: %s\n", day);
    }
}

// !!!!!!                         interface for select function                             !!!!!!
//============================================   searchSchedule    ===============================================================================================================

char take_password(char pass[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch(); // take the password without returning it on the screen
        if (ch == 13)
        {
            pass[i] = '\0'; // Null terminates the password string at the current index i
            break;          // like if there are no password then break
        }
        else if (ch == 8)
        {
            if (i > 0) // Checks if there's at least one character entered
            {
                i--;             //  i to move back to the previous character position.
                printf("\b \b"); // Prints two backspaces and a space to visually erase
            }
        }
        else if (ch == 9 || ch == 32) // checking for Tab or Space
        {
            continue; // then if found skip
        }
        else
        {
            pass[i++] = ch; // then the last one its will place a star for the user to view
            printf("*");
        }
    }
    return pass[20];
}
//============================================   searchSchedule    ===============================================================================================================
void searchSchedule()
{
    while (1)
    {
        system("cls");
        int choice;
        printf("\nSearch Schedule by:\n");
        printf("1. Subject\n");
        printf("2. Lecturer\n");
        printf("3. Date\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            searchScheduleBySubject();
            break;
        case 2:
            searchScheduleByLecturer();
            break;
        case 3:
            searchScheduleByDay();
            break;
        }

        printf("\n\nPress 'a' to continue ......... \npress 'b' for exit\n/....>");
        int ch = getch();
        if (ch == 'a')
        {
            printf("\n");
        }
        else if (ch == 'b')
        {
            break;
        }
    }
}
//============================================   setting for student    ===============================================================================================================
void student_login_success()
{
    system("cls");
    int choice;
    while (1)
    {
        system("cls");
        printf("\nSchedule Management System\n");
        printf("1. View Schedules\n");
        printf("2. Search Schedule\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            viewSchedules();
            break;
        case 2:
            searchSchedule();
            break;
        case 3:
            exit(8);
            printf("Exiting now..............\n");
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
//============================================   setting for admin   ===============================================================================================================
void admin_login_success(char name[20])
{
    system("cls");
    int choice;
    while (1)
    {
        system("cls");
        printf("\nSchedule Management System\n");
        printf("Welcome back, %s!!\n\n", name);
        printf("1. Add Schedule\n");
        printf("2. delete Schedule\n");
        printf("3. View Schedules\n");
        printf("4. Search Schedule\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addSchedule();
            break;
        case 2:
            deleteSchedule();
            break;
        case 3:
            viewSchedules();
            break;
        case 4:
            searchSchedule();
            break;
        case 5:
            exit(8);
            printf("Exiting now..............\n");
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

//============================================    check_account_for_user   ===============================================================================================================
struct Account
{
    char name[20];
    char password[20];
} account;

void check_account_user(int check)
{
    while (1) // while true
    {
        FILE *fb;

        if (check == 1)
        {
            fb = fopen("Admin.txt", "r"); // if enter 1 admin file is open and if ther are no file return null
            if (fb == NULL)
            {
                printf("Error: File does not exist or cannot be opened.\n");
                exit(8);
            }
        }

        else if (check == 2) // if enter 2 student file is open and if ther are no file return null
        {

            fb = fopen("Student.txt", "r");
            if (fb == NULL)
            {
                printf("Error: File does not exist or cannot be opened.\n");
                exit(8);
            }
        }

        char username[20];
        char password[20];
        printf("> USERNAME /> ");
        scanf("%s", &username);
        printf("> PASSWORD /> ");
        take_password(password); // password function call for encrypt

        int u_i = 0, p_i = 0;
        while (fscanf(fb, "%s %s", &account.name, &account.password) != EOF) // while there are data in  file
        {
            if (strcmp(account.name, username) == 0) // for user name comparision
            {
                u_i = 1; // if true u_i equal to 1
            }
            if (strcmp(account.password, password) == 0) // for pw comparision
            {
                p_i = 1; // if true u_i equal to 1
            }
        }

        if (u_i == 1 && p_i == 1) // if name and password are true then can go to the account option
        {
            printf("Login successful.\n");
            if (check == 1)
            {
                admin_login_success(username);
            }
            else if (check == 2)
            {
                student_login_success(username);
            }
            break;
        }
        else
        {
            // both are incorrect return else
            printf("Login fail!!!");
            if (u_i == 1)
            {
                printf("\nPassword is incorrect.\n");
            }
            else if (p_i == 1)
            {
                printf("\nName is incorrect.\n");
            }
            else
            {
                printf("\nError!! Both are incorrect.\n");
            }
        }

        fclose(fb);
    }
}
//============================================   Login    ===============================================================================================================
void login()
{
    int login;

    printf("\n\n \t\t\t\t\t\t  > Enter your choice: ");
    scanf("%d", &login);
    if (login == 1)
    {
        system("cls");
        admin_account();       // for gui function
        check_account_user(1); // enter 1 for admin account call the function
    }
    else if (login == 2)
    {
        system("cls");
        student_login();
        check_account_user(2); // enter 2 for student account call the function
    }
    else
    {
        system("cls");
        printf("Exiting now..............\n");
        exit(8);
    }
}
//============================================   main    ===============================================================================================================
int main()
{
    front();
    login();
    return 0;
}