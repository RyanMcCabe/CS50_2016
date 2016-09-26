#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

void backward(char word[])
{
    int len = strlen(word);
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(word[i]);
    }
    putchar(' ');
}

int main(int argc, char* argv[])
{
    //read in arguments
    int numStrings = argc;
    for (int i = 0; i < numStrings; i++)
    {
        backward(argv[i]);
    }
    putchar('\n');
}