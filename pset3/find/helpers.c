/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n<=0)
    return false;
    else
    {
        int midpoint= n/2;
        int start = 0;
        int end = n-1;
        
        while (end >= start)
        {
            midpoint = (start+end)/2;
            
            if(values[midpoint] ==value)
                return true;
            
            if(values[midpoint] < value)
                start = midpoint +1;
                
            else
                end = midpoint - 1;
        }
        
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int small;  //variable to keep track of the smallest value in the array
    int index;  //index location of the smallest value in the array
    for (int i=0; i<n;i++)
    {
        index= i;
        small = values[i];
        for (int j=i+1; j<n;j++)
        {
            if(small>values[j])  //finds new smallest values in array
            {
                index = j;
                small= values[j];
            }
        }
        
        values[index]=values[i];  //swaps the smallest value with the lowest
        values[i]=small;          //unsorted value in the array
    
        
        
    }
    return;
}