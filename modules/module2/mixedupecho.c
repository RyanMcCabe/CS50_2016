#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int maxLetterCount(int numStrings, char* strings)
{
    int max = 0;
    for (int i = 0; i < numStrings; i++)
    {
        int tempCount = strlen(&strings[i]);
        if (tempCount > max )
            max = tempCount;
    }
    return max;
}

void letterPuller (int num, char* word)
{
    putchar(word[num]);
}

void letterPullerCaller (int letterCount, char* word)
{
    //uses mod to allow word to wrap and cycle through again if not 
    //the longest word
    letterCount = letterCount % strlen(word);
    letterPuller(letterCount, word);
}

int main(int argc, char* argv[])
{

    int letterCount = 0;
    int maxLetter = maxLetterCount(argc, *argv);
    for (int i = 0; i < maxLetter; i++)
    {
        for(int j = 0; j < argc; j++)
        {
            letterPullerCaller(letterCount, argv[j]);
        }
        letterCount++;
    }
    putchar('\n');
}

