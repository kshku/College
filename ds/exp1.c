#include <stdio.h>
#include <stdlib.h>

typedef struct Day {
    char *day_name;
    int date;
    char *description;
} Day;

Day *createDay() {
    Day *day = (Day *)malloc(sizeof(Day));

    day->day_name = (char *)malloc(10 * sizeof(char));
    day->description = (char *)malloc(100 * sizeof(char));

    printf("Enter the day name: ");
    scanf("%s", day->day_name);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    printf("Enter the description: ");
    scanf(" %[^\n]", day->description);

    return day;
}

void read(Day **days, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Enter the details for day %d:\n", i + 1);
        days[i] = createDay();
    }
}

void display(Day **days, int n) {
    for (int i = 0; i < n; ++i)
        printf("Day %d\nDay name: %s\nDate: %d\nDescription: %s\n", i + 1,
               days[i]->day_name, days[i]->date, days[i]->description);
}

void destroyDay(Day *day) {
    free(day->day_name);
    free(day->description);
    free(day);
}

int main() {
    Day **week = (Day **)malloc(7 * sizeof(Day *));
    read(week, 7);
    display(week, 7);
    for (int i = 0; i < 7; ++i) destroyDay(week[i]);
}
