if (watts <= 60)
{
    life = life + 1000;
}
else if (watts <= 70)
{
    life = life + 1200;
}
else
{
    life = life - 750;
}

printf("Life = %d\nThis is the end of the program\n", life);
