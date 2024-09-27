#include <stdio.h>

int main()
{
    int enteredHour, enteredMinute;
    char ampm;

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

    if ((enteredHour < 7) || (enteredHour == 7 && enteredMinute <= 15))
    {
        printf("Your closest flight is 7:15 and arrival time is 8:25 AM\n");
    }
    else if ((enteredHour < 8) || (enteredHour == 8 && enteredMinute <= 15))
    {
        printf("Your closest flight is 8:15 and arrival time is 9:25 AM\n");
    }
    else if ((enteredHour < 9) || (enteredHour == 9 && enteredMinute <= 15))
    {
        printf("Your closest flight is 9:15 and arrival time is 10:25 AM\n");
    }
    else if ((enteredHour < 10) || (enteredHour == 10 && enteredMinute <= 15))
    {
        printf("Your closest flight is 10:15 and arrival time is 11:25 AM\n");
    }
    else if ((enteredHour < 11) || (enteredHour == 11 && enteredMinute <= 15))
    {
        printf("Your closest flight is 11:15 and arrival time is 12:25 PM\n");
    }
    else if ((enteredHour < 15) || (enteredHour == 15 && enteredMinute <= 15))
    {
        printf("Your closest flight is 3:15 and arrival time is 4:25 PM\n");
    }
    else if ((enteredHour < 16) || (enteredHour == 16 && enteredMinute <= 15))
    {
        printf("Your closest flight is 4:15 and arrival time is 5:25 PM\n");
    }
    else if ((enteredHour < 17) || (enteredHour == 17 && enteredMinute <= 15))
    {
        printf("Your closest flight is 5:15 and arrival time is 6:25 PM\n");
    }
    else
    {
        printf("No more flights available for today.\n");
    }

    return 0;
}
