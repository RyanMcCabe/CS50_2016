#include <stdio.h>
#include <cs50.h>

int main()
{
    int ans = 5;
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
    int guess = 1;  //guess counter
    int user = 0;  //user guess
    
    while(ans!=user)
    {
        printf("Guess %d:  ", guess);
        user = GetInt();
        if (ans!=user)
            printf("Wrong!\n");
        else
            printf("Correct!\n");
        guess++;
    }
}