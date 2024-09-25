#include <stdio.h>

int main()
{
    int grade, lastDigit;
    printf("Enter a numeric grade in %%: ");
    scanf("%d", &grade);
    if (grade >= 90 && grade <= 100)
    {
        printf("Letter grade = A");
    }
    else if (grade >= 80 && grade <= 89)
    {
        printf("Letter grade = B");
    }
    else if (grade >= 70 && grade <= 79)
    {
        printf("Letter grade = C");
    }
    else if (grade >= 60 && grade <= 69)
    {
        printf("Letter grade = D");
    }
    else if (grade >= 0 && grade <= 59)
    {
        printf("Letter grade = F");
    }
    else
    {
        printf("Error: Grade must be between 0 and 100.");
    }
    lastDigit =  grade % 10;
    if(grade < 100 && lastDigit >= 0  && lastDigit <= 2)
    {
        printf("-");
    }
    if(lastDigit >= 7  && lastDigit <= 9)
    {
        printf("+");
    }


}