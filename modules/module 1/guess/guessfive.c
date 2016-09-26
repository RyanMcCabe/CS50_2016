#include <stdio.h>
#include <cs50.h>

int main()
{
    int ans = 5;
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
    int user = 0;  //user guess
    bool correct = false;
    for(int i=0; i < 5; i++)
    {
        printf("Guess %d:  ", i+1);
        user = GetInt();
        if (ans!=user)
            printf("Wrong!\n");
        else
        {
            printf("Correct!\n");
            correct = true;
            break;
        }
    }
    if(correct == false)
        printf("Sorry, you ran out of guesses.\n");
    return 0;
}