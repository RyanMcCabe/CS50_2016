#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lenChecker(char* input)
{
    if (strlen(input) == 3)
        return 0;
    else
        return 1;
}

int validation(int numInputs, char** inputs)
{
    int errorFlag = 0;
    
    if (numInputs != 4)
        errorFlag = 1;
    
    else
    {
        int len[4];
        for (int i = 1; i < 4; i++)
        {
            len[i] = strlen(inputs[i]);
        }
        if (len[1] != len[2] || len[2] != len[3])
            errorFlag = 2;
    }    
    return errorFlag;
}

void letterPrinter(char input, int stretch) {
    for (int i = 0; i < stretch; i++) {
        
    }
}

void gridPrinter(char* input, int stretch)
{
    for (int i = 0; i < stretch; i++) {
        letterprinter(input[i], stretch);
    }
}

int main(int argc, char* argv[])
{
    if (validation(argc, argv) != 0)
    {
        printf("Use ./wordgrid word word word\n");
        return 1;
    }
    
    printf("How much do you want to stretch it?  ");
    int stretch = GetInt();
    for (int i = 0; i < stretch; i++){
        gridprinter(argv[i], stretch);  
    }
    
}
