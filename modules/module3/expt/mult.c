#include <stdio.h>
#include <stdlib.h>
int mult (int a,int b) 
{ 
    if (a < 0 && b < 0)
    {
        a=abs(a);
        b=abs(b);
    }
    
    else if (a > 0 && b < 0)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    if (b == 1)
    {
        return a;
    }
    else 
        return a + mult(a, b-1);
}
