void addSchedule()
{
    system("cls"); // clear screen

    FILE *fb;
    fb = fopen("addSchedule.txt", "a"); // to open file addSchedule.txt
    if (fb == NULL)                     // check it found or not
    {
        printf("File does not exist");
        exit(8);
    }
    // input data on structure
    printf("1.Monday\n");
    printf("2.Tuesday\n");
    printf("3.Wednesday\n");
    printf("4.Thursday\n");
    printf("5.Friday\n");
    while (1)
    {
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
    printf("Subject:\n> ");
    scanf("%s", schedule.subject);
    printf("lecturer:\n> ");
    scanf("%s", schedule.lecturer);
    printf("Date (DD MM YYYY):\n> ");
    scanf("%d %d %d", &schedule.dat.date_DD, &schedule.dat.date_MM, &schedule.dat.date_YY);
    printf("Time (HH MM):\n> ");
    scanf("%d %d", &schedule.tim.time_HH, &schedule.tim.time_MM);
    printf("End\n> Added Successfully!!\n");

    // input data in file
    fprintf(fb, "%d %s %s %d %d %d %d %d\n",
            schedule.day, schedule.subject, schedule.lecturer,
            schedule.dat.date_DD, schedule.dat.date_MM, schedule.dat.date_YY,
            schedule.tim.time_HH, schedule.tim.time_MM);
    // close file for end
    fclose(fb);
}
//============================================  day on week    ===============================================================================================================
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
    default:
    }
}