#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("Give me a phrase:  ");
    string phrase = GetString();
    int times;
    do
    {
        printf("How many times should I say it (between 1 - 100)  ");
        times = GetInt();
    } while (times <= 0 || times >= 101);
    
    for (int i = 0; i < times; i++)
        printf("%s\n",phrase);
        
    return 0;
}