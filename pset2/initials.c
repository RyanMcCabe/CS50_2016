#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string str = GetString();
    
    int length = strlen(str);
    char Initial = toupper(str[0]);
    printf("%c", Initial);
    for(int i = 0; i<length;i++)
    { 
        if(isspace(str[i]))
        {
            Initial = toupper(str[i + 1]);
            printf("%c", Initial);
        }

    }
    printf("\n");
}