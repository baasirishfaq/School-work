#include <stdio.h>

int main()
{
    char buffer[100]; // Create a buffer to hold the string
    int age = 25;
    sprintf(buffer, "I am %d years old", age); // Format and store the string

    printf("%s\n", buffer); // Now print the formatted string

    return 0;
}
