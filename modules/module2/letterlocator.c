#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int posAns(char letter);

int main ()
{
    bool letterFlag=true;
    char letter;
    do 
    {
        printf("Give me a letter:  ");
        letter = GetChar();
        if(isalpha(letter))
            letterFlag=false;
    }while(letterFlag);
    
    posAns(letter);
    return 0;
}

int posAns(char letter)
{
    char letterDown = tolower(letter);
    int locator = letterDown - 'a' + 1;
    printf("%c is at position %d\n", letter, locator);
    return 0;
}