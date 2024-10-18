#include <stdio.h>

int main()
{
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    int radius = 0;
    char x;

    if (choice == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("Enter radius: ");
            scanf("%d", &radius);
            printf("The area of the circle is: %.2f\n", 3.14 * radius * radius);
            printf("The circumference of the circle is: %.2f\n", 2 * 3.14 * radius);
        }
    }
    else if (choice == 2)
    {
        while (1)
        {
            printf("Enter radius: ");
            scanf("%d", &radius);
            if (radius == -1)
            {
                break;
            }
            printf("The area of the circle is: %.2f\n", 3.14 * radius * radius);
            printf("The circumference of the circle is: %.2f\n", 2 * 3.14 * radius);
        }
    }
    else if (choice == 3)
    {
        do
        {
            printf("Enter radius: ");
            scanf("%d", &radius);
            printf("The area of the circle is: %.2f\n", 3.14 * radius * radius);
            printf("The circumference of the circle is: %.2f\n", 2 * 3.14 * radius);
            printf("Do you want to continue? ");
            scanf(" %c", &x);
        } while (x == 'y');
    }

    return 0;
}
