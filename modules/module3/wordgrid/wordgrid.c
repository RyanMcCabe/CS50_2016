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
        for (int i = 1; i < 4; i++)
        {
        if (lenChecker(inputs[i])!=0)
            errorFlag = 2;
        }
    }    
    return errorFlag;
}

void gridPrinter(char** inputs)
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 1; k < 4; k++)
        {
            printf("%c", inputs[k][i]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    if (validation(argc, argv) != 0)
    {
        printf("Use ./wordgrid word word word\n");
        return 1;
    }
    
    gridPrinter(argv);
}
