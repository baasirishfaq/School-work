#include <stdio.h>
 
int main()
{
    int myvar = 2500;

    if(myvar < 3000)
    {
        myvar =500;
    }

    if(myvar > 400)
    {
        myvar = 300;
    }

    printf("%d", myvar);
};