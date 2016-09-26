#include <stdio.h>
#include "cs50.h"

int main(void)
{
    int height;
    int hash = 2;  
    int space;
    
    do
    {
        printf("Please enter a non-negative integer no greater than 23.\n ");
        height = GetInt();
    }while(height >23 || height <0);
    
    space = height - 1;
    for (int i=0;i<height;i++)
    {
        for (int n = 0; n < space; n++)
        {
            printf(" ");
        }
        for (int n = 0; n<hash; n++)
        {
            printf("#");
        }
        
        printf("\n");
        hash++;
        space--;
    }
}