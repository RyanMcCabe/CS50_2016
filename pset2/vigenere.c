#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int upper (char c, int k);
int lower (char c, int k);
char key_value (string key, int k);

int main(int argc, string argv[])
{
    
    bool check = true;      //creates a default assusming all ascii values in key are alpha
    if (argc <2)
    {
        printf("Need an arguement");
        return 1;
    }
    
    for (int n = 0, l = strlen(argv[1]); n < l; n++)
    {
        if (isalpha(argv[1][n]) == false)  
            check = false;
    }
    
    if (check == false)
    {    
        printf("please give a word");
        return 1;
    }
    else
    {               
        string key = argv[1];  //saves the cipher key to key
        string s = GetString();
        int k = strlen(key);     // position of the cipher key

        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (isalpha(s[i]) == false)
                printf("%c", s[i]);
            
            else if (isupper(s[i]))
            {                   
                upper(s[i], key_value(key,k));
                k = k + 1;
            }
            
            else
            {    
                lower(s[i], key_value(key,k));
                k = k + 1;
            }    
        }
        
        printf("\n");
    }   
}

int lower (char c, int k)
{
    if (c + k < 'z')
        printf("%c", c+k);
    
    else
        printf("%c", c+k - 26); //Rolls over the ascii table back to a
    
    return 0;       
}    

int upper (char c, int k)
{
    if (c + k < 'Z')
        printf("%c", c+k);
    
    else
        printf("%c", c+ k-26);  
    
    return 0;
}

char key_value(string key, int k)
{
    int key_info = key[(k % strlen(key))];
    if isupper(key_info)
        return (key_info - 'A');
    else
        return (key_info - 'a');
}