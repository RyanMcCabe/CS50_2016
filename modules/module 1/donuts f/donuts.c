#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("Welcome to the Loop Hole! \nToday's Manager's Special is:  \nA vanilla longjohn\n");
    printf("How many would you like?  ");
    
    int donuts = GetInt();
    
    printf("How much would you like to pay per donut (suggested price is $4.35 each?  ");
    
    float price = GetFloat();
    
    printf("Ok, let me prepare that for you....");
    
    float total = price * donuts * 1.05;
    
    printf("After tax, your total is: $%f\n", total);
    printf("Thank you for snacking! Loop back around here soon!\n");
}