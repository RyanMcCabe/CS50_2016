#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int upper (char c, int k);
int lower (char c, int k);

int main(int argc, string argv[])
{
    
    if (argc <2)
    {
        printf("Need another argument");
        return 1;
    }
    
    else
    {        
        int k = atoi(argv[1]);
        k = k % 26;
        
       
        string s = GetString();
        
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (ispunct(s[i]) || isspace(s[i]))
                printf("%c", s[i]);
            
            else if (isupper(s[i]))
                upper(s[i], k);
                
            else
                lower(s[i],k);
            
        }
        
        printf("\n");
    }   
}

int lower (char c, int k)
{
    if (c + k < 'z')
        printf("%c", c+k);
    
    else
        printf("%c", c+k-'z'+'a'-1); //Rolls over the ascii table back to a
    
    return 0;       
}    

int upper (char c, int k)
{
    if (c + k < 'Z')
        printf("%c", c+k);
    
    else
        printf("%c", c+k-'Z'+'A'-1);  
    
    return 0;
}
