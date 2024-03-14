
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define days 7
int i;

typedef struct
{
    char *day;
    int date;
    char *activity;
} daytype;

void freecal(daytype *);
void readcal(daytype *);
void disp(daytype *);
daytype *create();

int main()
{

    daytype *mycal = create();
    readcal(mycal);
    disp(mycal);
    freecal(mycal);

    return 0;
}

daytype *create()
{
    daytype *cal = (daytype *)malloc(days * sizeof(daytype));
    for (i = 0; i < days; i++)
    {
        cal[i].day = NULL;
        cal[i].date = 0;
        cal[i].activity = NULL;
    }
    return cal;
}

void readcal(daytype *cal)
{
    char choice;
    for (i = 0; i < days; i++)
    {
        printf("do you want to enter data for the day %d  y/n \n", i + 1);
        scanf(" %c", &choice);
        getchar();
        if (choice == 'n')
            continue;
        ;
        printf("enter day name: ");
        char namebuf[50];
        scanf(" %s", namebuf);
        cal[i].day = strdup(namebuf);
        printf("enter date: ");
        scanf("%d", &cal[i].date);
        printf("enter activity: ");
        char actbuf[50];
        scanf("%s", actbuf);
        cal[i].activity = strdup(actbuf);
        printf("\n");
    }
}

void disp(daytype *cal)
{

    printf("calender data is\n ");
    for (i = 0; i < days; i++)
    {
        if (cal[i].date == 0)
        {
            printf("no data for the day\n");
        }
        printf(" day name: %s \n", cal[i].day);
        printf(" day date: %d \n", cal[i].date);
        printf(" day activity: %s \n", cal[i].activity);
    }
}

void freecal(daytype *cal)
{

    for (i = 0; i < days; i++)
    {

        free(cal[i].day);
        free(cal[i].activity);
    }
    free(cal);
}
