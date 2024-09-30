#include <stdio.h>

int main()
{
    int format, enteredHour, enteredMinute;
    char ampm;

    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &format);

    if (format == 1)
    {
        printf("Enter time in 12-hour format.\n");
        printf("Enter a value between 1 and 12 for hour: ");
        scanf("%d", &enteredHour);

        if (enteredHour < 1 || enteredHour > 12)
        {
            printf("Invalid hour entered.\n");
            return 1;
        }

        printf("Enter a value between 0 and 59 for minutes: ");
        scanf("%d", &enteredMinute);

        if (enteredMinute < 0 || enteredMinute > 59)
        {
            printf("Invalid minute entered.\n");
            return 1;
        }

        printf("Enter 'a' for AM or 'p' for PM: ");
        scanf(" %c", &ampm);

        if (ampm == 'p' || ampm == 'P')
        {
            if (enteredHour != 12)
                enteredHour += 12;
        }
        else if (ampm == 'a' || ampm == 'A')
        {
            if (enteredHour == 12)
                enteredHour = 0;
        }
        else
        {
            printf("Invalid AM/PM entered.\n");
            return 1;
        }
    }
    else if (format == 2)
    {
        printf("Enter time in 24-hour format.\n");
        printf("Enter a value between 0 and 23 for hour: ");
        scanf("%d", &enteredHour);

        if (enteredHour < 0 || enteredHour > 23)
        {
            printf("Invalid hour entered.\n");
            return 1;
        }

        printf("Enter a value between 0 and 59 for minutes: ");
        scanf("%d", &enteredMinute);

        if (enteredMinute < 0 || enteredMinute > 59)
        {
            printf("Invalid minute entered.\n");
            return 1;
        }
    }
    else
    {
        printf("Invalid format choice.\n");
        return 1;
    }

    if ((enteredHour < 7) || (enteredHour == 7 && enteredMinute <= 15))
    {
        printf("Closest departure time is 7:15 a.m., arriving at 8:25 a.m.\n");
    }
    else if ((enteredHour < 8) || (enteredHour == 8 && enteredMinute <= 15))
    {
        printf("Closest departure time is 8:15 a.m., arriving at 9:25 a.m.\n");
    }
    else if ((enteredHour < 9) || (enteredHour == 9 && enteredMinute <= 15))
    {
        printf("Closest departure time is 9:15 a.m., arriving at 10:25 a.m.\n");
    }
    else if ((enteredHour < 10) || (enteredHour == 10 && enteredMinute <= 15))
    {
        printf("Closest departure time is 10:15 a.m., arriving at 11:25 a.m.\n");
    }
    else if ((enteredHour < 11) || (enteredHour == 11 && enteredMinute <= 15))
    {
        printf("Closest departure time is 11:15 a.m., arriving at 12:25 p.m.\n");
    }
    else if ((enteredHour < 15) || (enteredHour == 15 && enteredMinute <= 15))
    {
        printf("Closest departure time is 3:15 p.m., arriving at 4:25 p.m.\n");
    }
    else if ((enteredHour < 16) || (enteredHour == 16 && enteredMinute <= 15))
    {
        printf("Closest departure time is 4:15 p.m., arriving at 5:25 p.m.\n");
    }
    else if ((enteredHour < 17) || (enteredHour == 17 && enteredMinute <= 15))
    {
        printf("Closest departure time is 5:15 p.m., arriving at 6:25 p.m.\n");
    }
    else
    {
        printf("No more departure times available for today.\n");
    }

    return 0;
}
