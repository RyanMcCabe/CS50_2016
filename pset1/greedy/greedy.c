#include <stdio.h>
#include "cs50.h"
#include "math.h"

int main(void)
{
    float money;  //money from user input
    int counter = 0;  //starting coin counter 
    int whole;  //whole number of money as opposed to decimal
    do
    {
        printf("Money:  ");
        money = GetFloat();
    }while (money < 0);
    
    whole = round(money * 100);  //converts decimals to just int values
    
        counter += whole / 25;
        whole = whole % 25;
    
    
        counter += whole / 10;
        whole = whole % 10;
    
        counter += whole / 5;
        whole = whole % 5;

        counter += whole / 1;
        whole = whole % 1;
        
    printf("%i\n", counter);
}