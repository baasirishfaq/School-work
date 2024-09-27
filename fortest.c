#include <stdio.h>
 
int main()
{
    int traveledMiles, bonus;
    printf("Enter travelled miles: ");
    scanf("%d",  &traveledMiles);

    if(traveledMiles > 5000)
    {
        bonus = 100;
    }
    else if(traveledMiles > 3000)
    {
        bonus = 60;
    }
    else
    {
        bonus = 10;
    }

    printf("you get %d bonus miles", bonus);

    return 0;

};