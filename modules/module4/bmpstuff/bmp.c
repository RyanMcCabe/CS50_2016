#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "bitmaps.h"

void Usage() {
    printf("bmp <width> <height>");
}

unsigned char * createBitmap(int width, int height) {

    unsigned char *pRetval = malloc(width*height*3);

    for(int i=0; i<height; i++) {
        for(int j=0; j< width; j++){
           
            int idx = i*width*3 + j+3;
            
            pRetval[idx] = i % 255;
            pRetval[idx+1] = 0;
            pRetval[idx+2] = j % 255;
        }
    }
    
    for(int i=0; i<height; i++) {
        for(int j=0; j< width; j++){
           
            int idx = abs((int)(sin(width)+cos(height)));
            
            pRetval[idx] = 255;
            pRetval[idx+1] = 255;
            pRetval[idx+2] = 255;
        }
    }
    // for(int i=0; i<height; i++) {
    //     for(int j=0; j<width; j++) {
           
    //         //we need to calculate the index 
    //         int idx = sin((height)*180/3.14)*50;
            
    //         pRetval[idx] = 255;
    //         pRetval[idx+1] = 255;
    //         pRetval[idx+2] = 255;
    //     }
    //}



    return pRetval;
   
}

int main(int argc, char ** argv) {
    
    if(argc != 3) {
        Usage();
    }

    long int width = strtol(argv[1], NULL, 10);
    long int height = strtol(argv[2], NULL, 10);
    
    if(width == 0 | height == 0 )
       Usage();
    
   //TODO: Create a bitmap array of the size requested at the command-line
   //and save it as out.bmp.  Remember that pixels are (b,g,r) order

   unsigned char * p = createBitmap(width, height); 
   
   saveBitmap(p, width, height, "out.bmp");
   
   free(p);
}