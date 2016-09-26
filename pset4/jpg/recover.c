/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//define BYTE type
typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    //open file and standard error checking
    FILE* inptr = fopen("card.raw","r");
    if (inptr==NULL)
    {
        return 1;
    }
    int counter =0;  //counter for jpg file titles
    char* title = malloc(sizeof(char)*7);  //place to create the titles for jpg
    
    //storage for 512 byte increments of the file
    BYTE* buffer = malloc(512);
    if (buffer==NULL)
    {
        return 2;
    }    
    
    FILE* outptr;
    bool open=false;  //variable to check if a file has been opened
    bool first=true;  //variable to see if this is the first file
    while(true)
    {
        //reads into buffer from card file and checks to make sure a full block was read.
        if((fread(buffer, sizeof(BYTE), 512, inptr)<512))
            break;
        
        else
        {    
            //checks to see if the first 4 bytes match a jpg
            if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]==0xe0 || buffer[3]==0xe1))
            {
                if(!first)
                    fclose(outptr);
            
                //creates new file and opens it for writing
                sprintf(title, "%0*d.jpg", 3,counter);
                outptr=fopen(title, "a");
                open=true;
                counter++;
                first=false;
            }
            fwrite(buffer, sizeof(BYTE),512, outptr);
        }    
    }
    fclose(inptr);
 
    free(title);
    free(buffer);
    return 0;
}
