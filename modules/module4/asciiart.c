#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    csvLine lineData;
    char line [1000];
    //Prompt the user for an input file
    printf("What file do you want to open?  \n");
    char* read = GetString();
    //Prompt the user for an output file
    printf("Where do you want to output to?  \n");
    char* write = GetString();
    //Open the file to read from
    FILE* fInput = fopen(read, "r");
    //Open the file you're writing to
    FILE* fOutput = fopen(write, "w");
    if (fOutput == NULL || fInput == NULL) {
        printf("files were not open successfully \n ");
        return 1;
    }
    //For each line being read in from the input file:
    while (fgets(line, 1000, fInput) != NULL) {
        //Pass the line into the given extractNumbers function
        lineData = extractNumbers(line);
        //For each value in the int array returned by extractNumbers:
        int filePosition = 0;
        
        for (int hashPosition = 0; hashPosition < lineData.length; hashPosition++) {
            while (lineData.hashLocations[hashPosition] != filePosition) {
                fputc(' ', fOutput);
                filePosition++;
            }
            //put a hash in the file
            fputc('#', fOutput);
            filePosition++;
        }
        filePosition = 0;
        fputc('\n', fOutput);
    }
    //Close both files
    fclose(fInput);
    fclose(fOutput);
    //Insert the name of the output file in the print statement below
    printf("Done! If you open up <output file name> you should now see a cool image!\n");
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count + 1;
    return result;
}