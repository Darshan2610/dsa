    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define days 7

    typedef struct
    {

        char *day;
        int date;
        char *activity;

    } daytype;

    daytype *create();
    void read(daytype* );
    void display(daytype*);
    void freecal(daytype *);

    int main()
    {
        daytype *weekcal = create();
        read(weekcal);
        display(weekcal);
        freecal(weekcal);

        return 0;
    }

    daytype *create(){
        daytype *calender = (daytype*)malloc(days * sizeof(daytype));
        for (int i = 0; i < days;i++){
            calender[i].day = NULL;
            calender[i].date = 0;
            calender[i].activity = NULL;
        }
        return calender;
    }

    void read(daytype *calender){
        for (int i = 0; i < days; i++) {
            printf("do you want to enter deatils for day %d (Y/N): ", i+1);
            char ch;
            scanf(" %c", &ch);
            getchar();
            if((ch=='n')||(ch=='N'))
                continue;
            ;

            printf("enter day name : ");
            char daybuf[20];
            scanf(" %s", daybuf);
            calender[i].day=strdup(daybuf);
            printf("enter date : ");
            scanf("%d", &calender[i].date);
            printf("enter activity: ");
            char actbuf[50];
            scanf("%s", actbuf);
            calender[i].activity = strdup(actbuf);
            printf("\n");
            }
    }
    void display(daytype *calender){
        printf("week details\n");

        for (int i = 0; i < days; i++){
            
            if(calender[i].date==0){
                printf("no activity for the %dth day\n", i+1);
                continue;
            }
            printf("day %d\n", i + 1);
            printf("day name : %s\n", calender[i].day);
            printf("day date : %d\n", calender[i].date);
            printf("day activity : %s \n", calender[i].activity);
            
        }
    }

    void freecal(daytype *calender){
        for (int i = 0; i< days;i++){
            free(calender[i].day);
            free(calender[i].activity);

        }
        free(calender);
    }