#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Gimme a dollar amount: ");
    float money = GetFloat();
    money *= 100;
    money = round(money);
    money /= 100;
    printf("I think you mean %f \n", money);
    return 0;
}