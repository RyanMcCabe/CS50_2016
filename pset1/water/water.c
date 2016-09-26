#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int minutes;
    
    do
    {
        printf("minutes:  ");
        minutes = GetInt();
        printf("\n");
    }while (minutes < 0);
    
    int bottles = 12 * minutes;
    
    printf("bottles:  %i\n", bottles);
}