#include <stdio.h>

int main()
{
    int format, enteredHour, enteredMinute, originalHour, hotelChoice, days = 0, rideChoice = 0, dob, subtotal, sum, flag1 = 0, flag2 = 0;
    float rideCost = 0, beforetax = 0, discount1, discount2, hotelCost = 0, flightCost = 0; // Variable to store the cost of the closest flight

    // Time selection
    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &format);
    printf("\n");

    // Time Input and Conversion
    if (format == 1)
    {
        // 12-hour format input
        printf("Enter time in 12-hour format.\n");
        printf("\n");
        printf("Enter a value between 0 and 12 for hour: ");
        scanf("%d", &enteredHour);

        if (enteredHour < 1 || enteredHour > 12)
        {
            printf("Invalid hour entered.\n");
            return 1;
        }

        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &enteredMinute);

        if (enteredMinute < 0 || enteredMinute > 59)
        {
            printf("Invalid minute entered.\n");
            return 1;
        }

        char ampm;
        printf("Enter a for am or p for pm: ");
        scanf(" %c", &ampm);

        originalHour = enteredHour; // to store the original hour in 12-hour format
        char ampmOutput;

        // 'a' or 'p' for AM or PM input
        if (ampm == 'p' || ampm == 'P')
        {
            ampmOutput = 'p';
        }
        else if (ampm == 'a' || ampm == 'A')
        {
            ampmOutput = 'a';
        }
        else
        {
            printf("Invalid AM/PM entered.\n");
            return 1;
        }

        // convert to 24-hour format
        if (ampm == 'p' || ampm == 'P')
        {
            if (enteredHour != 12)
                enteredHour += 12;
        }
        else if (ampm == 'a' || ampm == 'A')
        {
            if (enteredHour == 12)
                enteredHour = 0; // 12 AM is 0
        }

        printf("__________________________\n");
        printf("You entered: %02d:%02d %cm\n", originalHour, enteredMinute, ampmOutput);    // 12-hour format
        printf("In 24 hour format - you entered %02d:%02d\n", enteredHour, enteredMinute); // 24-hour format
        printf("__________________________\n");
    }
    else if (format == 2)
    {
        // 24-hour format input
        printf("Enter time in 24-hour format.\n");
        printf("\n");
        printf("Enter a value between 0 and 24 for hour: ");
        scanf("%d", &enteredHour);

        if (enteredHour < 0 || enteredHour > 23)
        {
            printf("Invalid hour entered.\n");
            return 1;
        }

        printf("Enter a value between 0 and 60 for minutes: ");
        scanf("%d", &enteredMinute);

        if (enteredMinute < 0 || enteredMinute > 59)
        {
            printf("Invalid minute entered.\n");
            return 1;
        }

        originalHour = enteredHour; // Store the original 24-hour hour
        char ampmOutput;
        int displayHour = enteredHour;

        // Convert to 12-hour format
        if (enteredHour == 0)
        {
            displayHour = 12; // Midnight (12 AM)
            ampmOutput = 'a';
        }
        else if (enteredHour == 12)
        {
            displayHour = 12; // Noon (12 PM)
            ampmOutput = 'p';
        }
        else if (enteredHour > 12)
        {
            displayHour = enteredHour - 12; // Convert to PM format
            ampmOutput = 'p';
        }
        else
        {
            ampmOutput = 'a'; // Morning (AM)
        }

        printf("---------------------------\n");
        printf("In 24 hour format - you entered %02d:%02d\n", originalHour, enteredMinute);
        printf("In 12 hour format - you entered %02d:%02d %cm\n", displayHour, enteredMinute, ampmOutput);
        printf("---------------------------\n");
    }
    else
    {
        printf("Invalid format choice.\n");
        return 1;
    }

    // Determine closest flight time and cost
    if ((originalHour < 7) || (originalHour == 7 && enteredMinute <= 15))
    {
        printf("Closest departure times is 7:15 a.m., arriving at 8:25 a.m.\n");
        flightCost = 231.00;
    }
    else if ((originalHour < 8) || (originalHour == 8 && enteredMinute <= 15))
    {
        printf("Closest departure times is 8:15 a.m., arriving at 9:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 9) || (originalHour == 9 && enteredMinute <= 15))
    {
        printf("Closest departure times is 9:15 a.m., arriving at 10:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 10) || (originalHour == 10 && enteredMinute <= 15))
    {
        printf("Closest departure times is 10:15 a.m., arriving at 11:25 a.m.\n");
        flightCost = 283.00;
    }
    else if ((originalHour < 11) || (originalHour == 11 && enteredMinute <= 15))
    {
        printf("Closest departure times is 11:15 a.m., arriving at 12:25 p.m.\n");
        flightCost = 283.00;
    }
    else if ((originalHour < 15) || (originalHour == 15 && enteredMinute <= 15))
    {
        printf("Closest departure times is 3:15 p.m., arriving at 4:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 16) || (originalHour == 16 && enteredMinute <= 15))
    {
        printf("Closest departure times is 4:15 p.m., arriving at 5:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 17) || (originalHour == 17 && enteredMinute <= 15))
    {
        printf("Closest departure times is 5:15 p.m., arriving at 6:25 p.m.\n");
        flightCost = 401.00;
    }
    else
    {
        printf("No more departure times available for today.\n");
        return 1;
    }

    printf("\nWould you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &hotelChoice);

    if (hotelChoice == 1)
    {
        printf("\nThere are 3 hotels:\n");
        printf("1. Marriott: $248 per night\n");
        printf("2. Sheraton: $90 per night\n");
        printf("3. Double Tree: $128 per night\n");

        printf("\nYour choice?:");
        scanf("%d", &hotelChoice);

        // Set hotel cost based on selection
        if (hotelChoice == 1)
        {
            hotelCost = 248.0;
        }
        else if (hotelChoice == 2)
        {
            hotelCost = 90.0;
        }
        else if (hotelChoice == 3)
        {
            hotelCost = 128.0;
        }
        else if (hotelChoice == 0)
        {
            hotelCost = 0;
        }

        // Ask for number of days staying at hotel
        printf("How many days in Montreal?");
        scanf("%d", &days);

        // Ask if the user needs a ride to the hotel
        printf("\nWould you like a ride from airport to hotel? - enter 0 for no; 1 for yes ");
        scanf("%d", &rideChoice);

        if (rideChoice == 1)
        {
            if (hotelChoice == 1)
                rideCost = 0;
            else if (hotelChoice == 2)
                rideCost = 25;
            else if (hotelChoice == 3)
                rideCost = 20;
        }
    }

    printf("\nNow enter your day of birth to qualify for discount2: ");
    scanf("%d", &dob);
    if (dob >= 10)
    {
        int firstDigit = dob / 10;
        int secondDigit = dob % 10;
        sum = firstDigit + secondDigit;
    }
    else
    {
        sum = dob;
    }

    hotelCost = (hotelCost * days);
    subtotal = hotelCost + rideCost + flightCost;

    printf("\n");
    printf("Your total cost comes to:\n");
    printf("\n");
    printf("Cost of closest departure flight: $ %.2f\n", flightCost);
    printf("Cost of Hotel for %d days: $ %.2f\n", days, hotelCost);
    printf("Cost of Ride: $ %.2f\n", rideCost);
    printf("\n");
    printf("Total cost before tax: $ %d.00\n", subtotal);
    printf("\n");
    
    if (subtotal % 11 == 0)
    {
        flag1 = 1;
        discount1 = (subtotal * 0.05);
        printf("You get a 5%% discount because the total cost was a multiple of 11 :)\n");
        
    }
    // else
    // {
    //     printf("Sorry - you missed out on the 5%% discount because the total cost was not a multiple of 11\n");
    // }

    // DISCOUNT 2 cal

    if (subtotal % sum == 0)
    {
        flag2 = 1;
        discount2 = (subtotal * 0.05);
        printf("You get an additional 5%% discount because the total cost after discount1 was a multiple of the sum of digits in your day of birth :)\n");
    }

    if(flag1 == 0  && flag2 == 0)
    {
        float finalTotal = subtotal;
        beforetax = finalTotal;
        printf("Sorry - you missed out on the 5%% discount because the total cost was not a multiple of 11\n");
        printf("Sorry - you missed out on the additional 5%% discount because the total cost after discount1 was not a multiple of the sum of digts in your day of birth\n");
    }

    if (flag1 == 1 && flag2 == 1)
    {
        float finalTotal = subtotal - discount1 - discount2;
        beforetax = finalTotal;
        printf("\nTotal cost after discount 1 and 2:  $ %.2f\n", finalTotal);
    }
    else if (flag1 == 0 && flag2 == 1)
    {
        float finalTotal = subtotal - discount2;
        beforetax = finalTotal;
        printf("\nTotal cost after discount 1 and 2:  $ %.2f\n", finalTotal);
    }
    else if (flag1 == 1 && flag2 == 0)
    {
        float finalTotal = subtotal - discount1;
        beforetax = finalTotal;
        printf("\nTotal cost after discounts 1 and 2: $ %.2f\n", finalTotal);
    }
    else
    {
        printf("\nTotal cost after discounts 1 and 2: $ %d.00\n", subtotal);
    }

    float bill =  (0.13 *  beforetax) +  beforetax;


    printf("\nFinally, your total cost after taxes: $ %.2f\n", bill);


    return 0;

};