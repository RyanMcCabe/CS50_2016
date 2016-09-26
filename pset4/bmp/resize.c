/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy manification infile outfile\n");
        return 1;
    }
    int mag= atoi(argv[1]);
    if(mag < 1 ||mag > 100)
    {
        printf("magification between 1 and 100 inclusive");
        return 5;
    }
    
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // storage of variable from orginal bmp for fseek function later
    int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    LONG oldWidth = bi.biWidth; 
    DWORD oldSizeImg = bi.biSizeImage;
    LONG oldHeight = bi.biHeight;    
    DWORD oldSize = bf.bfSize;
    
    // new size of of image for header info.
    bi.biHeight *= mag;
    bi.biWidth *= mag;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;    
    
    // use new information to determine headerinfo
    bi.biSizeImage = ((abs(bi.biWidth) * sizeof(RGBTRIPLE) + padding) * abs(bi.biHeight));
    bf.bfSize = oldSize - oldSizeImg + bi.biSizeImage;
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldHeight); i < biHeight; i++)
    {
        // iterate each line mag times
        for (int h=0; h < mag; h++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < oldWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile mag times
                for (int k=0; k<mag; k++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);   //add padding after scanline
            }
            fseek(inptr, sizeof(RGBTRIPLE)*-oldWidth, SEEK_CUR);
        }
        
        
        // skip over padding, if any
        fseek(inptr, oldPadding + sizeof(RGBTRIPLE)*oldWidth, SEEK_CUR);


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
