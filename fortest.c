#include <stdio.h>

int main()
{
    int aNumber;

    printf("Enter a number: ");
    scanf("%d", &aNumber);

    // Using the remainder of aNumber divided by 2 as the switch expression
    switch (aNumber % 2)
    {
    case 0:
        printf("%d is even\n", aNumber);
        break;

    case 1:
        printf("%d is odd\n", aNumber);
        break;
    }

    return 0;
}
