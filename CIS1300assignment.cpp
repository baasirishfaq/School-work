#include <stdio.h>

int main()
{
    int format, enteredHour, enteredMinute, hotelChoice, days, rideChoice = 0, rideCost = 0, birthDay, sumDigits = 0;
    char ampm;
    float flightCost = 0; // Variable to store the cost of the closest flight

    // Time selection
    printf("Would you like to enter the time in 12-hour format (enter 1) or 24-hour format (enter 2)? ");
    scanf("%d", &format);

    // Time Input and Conversion Logic
    if (format == 1)
    { // 12-hour format input
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

        printf("Time in 24-hour format: %02d:%02d\n", enteredHour, enteredMinute);
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

        // Convert to 12-hour format and show
        if (enteredHour >= 12)
        {
            if (enteredHour > 12)
                enteredHour -= 12;
            ampm = 'P';
        }
        else
        {
            if (enteredHour == 0)
                enteredHour = 12;
            ampm = 'A';
        }

        printf("Time in 12-hour format: %d:%02d %cM\n", enteredHour, enteredMinute, ampm);
    }
    else
    {
        printf("Invalid format choice.\n");
        return 1;
    }

    // Determine closest flight time and cost
    if ((enteredHour < 7) || (enteredHour == 7 && enteredMinute <= 15))
    {
        printf("Closest departure time is 7:15 a.m., arriving at 8:25 a.m.\n");
        flightCost = 231.00;
    }
    else if ((enteredHour < 8) || (enteredHour == 8 && enteredMinute <= 15))
    {
        printf("Closest departure time is 8:15 a.m., arriving at 9:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((enteredHour < 9) || (enteredHour == 9 && enteredMinute <= 15))
    {
        printf("Closest departure time is 9:15 a.m., arriving at 10:25 a.m.\n");
        flightCost = 226.00;
    }
    else if ((enteredHour < 10) || (enteredHour == 10 && enteredMinute <= 15))
    {
        printf("Closest departure time is 10:15 a.m., arriving at 11:25 a.m.\n");
        flightCost = 283.00;
    }
    else if ((enteredHour < 11) || (enteredHour == 11 && enteredMinute <= 15))
    {
        printf("Closest departure time is 11:15 a.m., arriving at 12:25 p.m.\n");
        flightCost = 283.00;
    }
    else if ((enteredHour < 15) || (enteredHour == 15 && enteredMinute <= 15))
    {
        printf("Closest departure time is 3:15 p.m., arriving at 4:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((enteredHour < 16) || (enteredHour == 16 && enteredMinute <= 15))
    {
        printf("Closest departure time is 4:15 p.m., arriving at 5:25 p.m.\n");
        flightCost = 226.00;
    }
    else if ((enteredHour < 17) || (enteredHour == 17 && enteredMinute <= 15))
    {
        printf("Closest departure time is 5:15 p.m., arriving at 6:25 p.m.\n");
        flightCost = 401.00;
    }
    else
    {
        printf("No more departure times available for today.\n");
        return 1;
    }

    // hotel in Montreal
    printf("Would you like a hotel in Montreal - enter 0 for no; 1 for yes? ");
    scanf("%d", &hotelChoice);

    if (hotelChoice == 1)
    {
        printf("There are 3 hotels:\n");
        printf("1. Marriott: $248.00 per night\n");
        printf("2. Sheraton: $90.00 per night\n");
        printf("3. DoubleTree: $128.00 per night\n");

        printf("Your choice?: ");
        scanf("%d", &hotelChoice);

        // Ask for the number of days
        printf("How many days in Montreal? ");
        scanf("%d", &days);

        // Ask if they need a ride from the airport to the hotel
        printf("Do you need a ride from airport to hotel? enter 0 for no; 1 for yes: ");
        scanf("%d", &rideChoice);

        // Ask for the customer's day of birth
        printf("Now enter you date of birth to qualify for discount2: ");

        scanf("%d", &birthDay);

        // Determine hotel cost
        float hotelCost;
        switch (hotelChoice)
        {
        case 1:
            hotelCost = 248.00;
            break;
        case 2:
            hotelCost = 90.00;
            rideCost = 25; // Cost for Sheraton
            break;
        case 3:
            hotelCost = 128.00;
            rideCost = 20; // Cost for DoubleTree
            break;
        default:
            printf("Invalid hotel choice.\n");
            return 1;
        }

        // Calculate total cost
        float subtotal = (days * hotelCost) + (rideChoice * rideCost) + flightCost;
        float totalCost = subtotal;

        // Displaying costs
        printf("Your total cost comes to:\n");
        printf("Cost of closest departure flight: $%.2f\n", flightCost);
        printf("Cost of Hotel for %d days: $%.2f\n", days, (days * hotelCost));
        printf("Cost of Ride: $%.2f\n", (rideChoice == 1 ? rideCost : 0.00));
        printf("Total cost before tax: $  $%.2f\n", totalCost);

        // Discount 1: Check if total cost is a multiple of 11
        if ((int)subtotal % 11 == 0)
        {
            float discount1 = subtotal * 0.05;
            totalCost -= discount1;
            printf("5%% discount applied: -$%.2f\n", discount1);
        }

        // Calculate the sum of digits of the day of birth
        int temp = birthDay;
        while (temp > 0)
        {
            sumDigits += temp % 10;
            temp /= 10;
        }

        // Discount 2: Check if subtotal after discount1 is a multiple of the sum of digits of the day of birth
        if ((int)subtotal % sumDigits == 0)
        {
            float discount2 = totalCost * 0.05;
            totalCost -= discount2;
            printf("Additional 5%% discount applied: -$%.2f\n", discount2);
        }

        // Apply tax
        float tax = totalCost * 0.13; // 13% tax
        totalCost += tax;

        //  final bill
        printf("Total cost after discounts: $%.2f\n", totalCost);
        printf("Tax (13%%): $%.2f\n", tax);
        printf("Final total cost: $%.2f\n", totalCost);
    }
    else
    {
        printf("Finally, your total cost after taxes: $%.2f\n", flightCost);
    }

    return 0;
}
