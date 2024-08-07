#include <stdio.h>

// Define the schedule structure
struct Schedule {
    int day;
};

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
        printf("Invalid date!!!!!");
        break;
    }
}

int main() {
    struct Schedule schedule;

    // Prompt the user to enter a day and store it in schedule.day
    printf("Enter a day (1-5): ");
    scanf("%d", &schedule.day);

    // Call day_option with the value from schedule.day
    day_option(schedule.day);

    return 0;
}
