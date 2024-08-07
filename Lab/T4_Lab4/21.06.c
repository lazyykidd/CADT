#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_LECTURERS 10
#define MAX_SCHEDULES 10

struct date {
    int date_DD;
    int date_MM;
    int date_YY;
};

struct time {
    int time_HH;
    int time_MM;
};

typedef struct {
    char subject[50];
    char lecturer[50];
    struct date dat;
    struct time tim;
} Schedule;

void viewSchedules() {
    FILE *fb;
    fb = fopen("addSchedule.txt", "r");
    if (fb == NULL) {
        printf("Error: File does not exist or cannot be opened.\n");
        return;
    }

    Schedule schedule;
    int result = fscanf(fb, "%49s %49s %d %d %d %d %d",
                        schedule.subject, schedule.lecturer,
                        &schedule.dat.date_DD, &schedule.dat.date_MM,
                        &schedule.dat.date_YY, &schedule.tim.time_HH,
                        &schedule.tim.time_MM);

    if (result != 7) {
        printf("Error reading data from file.\n");
    } else {
        // Add code to validate date and time (optional)

        // Process and display the read schedule information
        printf("Subject: %s\n", schedule.subject);
        printf("Lecturer: %s\n", schedule.lecturer);
        printf("Date: %d/%d/%d\n", schedule.dat.date_DD, schedule.dat.date_MM, schedule.dat.date_YY);
        printf("Time: %d:%02d\n", schedule.tim.time_HH, schedule.tim.time_MM);
    }

    fclose(fb);
}

int main() {
    viewSchedules();
    return 0;
}
