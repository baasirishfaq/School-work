#include <stdio.h>
 
int main()
{
    if(watts <= 60)
    {
        life = life + 1000;
    }
    else if (watts <= 70)
    {
         life = life + 1200;
    }
    else
    life = life - 750;
};
