#include <stdio.h>

int decimalToBinary(int x)
{
    int binary[32];
    int i = 0;

    while (x != 0)
    {
        binary[i] = x % 2;  
        x = x / 2;
        i++;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--)  
    {
        printf("%d", binary[j]);
    }

    return 0;
}

int main()
{
    int number;
    printf("Insert your number:\n");
    scanf("%d", &number);
    decimalToBinary(number);
    return 0;
}
