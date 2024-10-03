#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numInput, i;
    double Rtotal = 0.0, resistance;

    do
    {
        printf("Enter the number of resistors (must be greater than 0): ");
        scanf("%d", &numInput);

        if (numInput <= 0)
        {
            printf("Number of resistors must be greater than 0. Please try again.\n");
        }

    } while (numInput <= 0);

    for (i = 0; i < numInput; i++)
    {
        printf("Enter value for R%d (in Ohms): ", i + 1);
        scanf("%lf", &resistance);
        Rtotal += 1.0 / resistance;
    }

    Rtotal = 1.0 / Rtotal;

    printf("Total Resistance = %.1lf Ohms \n", Rtotal);

    return 0;
}
