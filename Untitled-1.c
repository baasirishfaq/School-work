#include <stdio.h>

int main()
{
    int format, tempsubTotal, enteredHour, enteredMinute, originalHour, hotelChoice, days = 0, rideChoice = 0, rideCost = 0, dob, subtotal, sum, discount2, discount1, flag1 = 0, flag2 = 0;
    float hotelCost = 0, flightCost = 0; // Variable to store the cost of the closest flight

    // Time selection
    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &format);

    // Time Input and Conversion Logic
    if (format == 1)
    {
        // 12-hour format input
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

        char ampm;
        printf("Enter 'a' for AM or 'p' for PM: ");
        scanf(" %c", &ampm);

        originalHour = enteredHour; // Store the original hour in 12-hour format
        char ampmOutput;

        // Assign 'a' or 'p' based on AM or PM input
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

        // Convert to 24-hour format
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
        // Adding a leading zero for single-digit hours and printing 'am' or 'pm'
        printf("You entered: %02d:%02d %cm\n", originalHour, enteredMinute, ampmOutput);    // 12-hour format
        printf("In 24-hour format - you entered: %02d:%02d\n", enteredHour, enteredMinute); // 24-hour format
        printf("__________________________\n");
    }
    else if (format == 2)
    {
        // 24-hour format input
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

        printf("__________________________\n");
        printf("In 24-hour format - you entered: %02d:%02d\n", originalHour, enteredMinute);
        printf("In 12-hour format - you entered: %02d:%02d %cm\n", displayHour, enteredMinute, ampmOutput);
        printf("__________________________\n");
    }
    else
    {
        printf("Invalid format choice.\n");
        return 1;
    }

    // Determine closest flight time and cost
    if ((originalHour < 7) || (originalHour == 7 && enteredMinute <= 15))
    {
        printf("Closest departure time is 7:15 a.m., arriving at 8:25 a.m.\n");
        flightCost = 231.00;
    }
    else if ((originalHour < 8) || (originalHour == 8 && enteredMinute <= 15))
    {
        printf("Closest departure time is 8:15 a.m., arriving at 9:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 9) || (originalHour == 9 && enteredMinute <= 15))
    {
        printf("Closest departure time is 9:15 a.m., arriving at 10:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 10) || (originalHour == 10 && enteredMinute <= 15))
    {
        printf("Closest departure time is 10:15 a.m., arriving at 11:25 a.m.\n");
        flightCost = 283.00;
    }
    else if ((originalHour < 11) || (originalHour == 11 && enteredMinute <= 15))
    {
        printf("Closest departure time is 11:15 a.m., arriving at 12:25 p.m.\n");
        flightCost = 283.00;
    }
    else if ((originalHour < 15) || (originalHour == 15 && enteredMinute <= 15))
    {
        printf("Closest departure time is 3:15 p.m., arriving at 4:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 16) || (originalHour == 16 && enteredMinute <= 15))
    {
        printf("Closest departure time is 4:15 p.m., arriving at 5:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((originalHour < 17) || (originalHour == 17 && enteredMinute <= 15))
    {
        printf("Closest departure time is 5:15 p.m., arriving at 6:25 p.m.\n");
        flightCost = 401.00;
    }
    else
    {
        printf("No more departure times available for today.\n");
        return 1;
    }

    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &hotelChoice);

    if (hotelChoice == 1)
    {
        printf("Here are 3 hotels:\n");
        printf("1) Marriott: $248 per night\n");
        printf("2) Sheraton: $90 per night\n");
        printf("3) DoubleTree: $128 per night\n");

        printf("Please choose a hotel (1, 2, or 3): ");
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
        printf("How many days will you stay at the hotel? ");
        scanf("%d", &days);

        // Ask if the user needs a ride to the hotel
        printf("Do you need a ride to the hotel (1 for yes, 0 for no)? ");
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

    hotelCost = (hotelCost * days);
    subtotal = hotelCost + rideCost + flightCost;

    printf("Now enter your day of birth to qualify for discount2: ");
    scanf("%d", &dob);
    if (dob > 10)
    {
        int firstDigit = dob / 10;
        int secondDigit = dob % 10;
        sum = firstDigit + secondDigit;
        if (sum >= 10)
        {
            flag1 = 1; // Check if the sum is greater than or equal to 10
        }
        if (flag1 == 1)
        {
            discount1 = 15; // If true, discount1 is 15
        }
        else
        {
            discount1 = 0; // Else discount1 is 0
        }
    }
    else
    {
        discount1 = 0; // Else discount1 is 0
    }

    // Calculating discount2
    if (days > 3)
    {
        flag2 = 1; // Check if the days are greater than 3
        discount2 = 10; // If true, discount2 is 10
    }
    else
    {
        discount2 = 0; // Else discount2 is 0
    }

    // Print subtotal, discounts, and total cost
    printf("__________________________\n");
    printf("Subtotal: $%.2f\n", subtotal);
    printf("Discount1 (day of birth): %d%%\n", discount1);
    printf("Discount2 (days staying): %d%%\n", discount2);
    printf("__________________________\n");

    // Apply discounts to subtotal
    subtotal -= subtotal * discount1 / 100;
    subtotal -= subtotal * discount2 / 100;

    printf("Total cost after discounts: $%.2f\n", subtotal);
    printf("__________________________\n");

    return 0;
}
