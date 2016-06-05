//This is a template for programming in c
//template.c
//by: Daniel Shougam z5114053	
//date: whatever the date is

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "pixelColor.c"

#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0
#define SIZE 512
#define MIDDLE 256
#define BMP_FILE "mandel.bmp"

typedef unsigned char bits8;
typedef unsigned short bits16;
typedef unsigned int bits32;
typedef struct _complexNum complexNum;

struct _complexNum{
   double re;
   double im;
   double mod;
};

int manFormula(double re, double im);
int calculateMod(double re, double im);
void writeHeader (FILE *file);
void createBMP(FILE *file, float startX, float startY, double zoomNum);

int main(int argc, char* argv[]){

   FILE *outputFile;
   outputFile = fopen(BMP_FILE, "wb");
   assert ((outputFile!=NULL) && "Cannot open file");

   writeHeader(outputFile);
   createBMP(outputFile, -2, -2, 1);
   fclose(outputFile);

   return EXIT_SUCCESS;
}

void writeHeader (FILE *file){

   bits16 magicNumber = MAGIC_NUMBER;
   fwrite(&magicNumber, sizeof magicNumber, 1, file);

   bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite(&fileSize, sizeof fileSize, 1, file);

   bits32 reserved = 0;
   fwrite(&reserved, sizeof reserved, 1, file);

   bits32 offset = OFFSET;
   fwrite(&offset, sizeof offset, 1, file);

   bits32 dibHeaderSize = DIB_HEADER_SIZE;
   fwrite(&dibHeaderSize, sizeof dibHeaderSize, 1, file);

   bits32 width = SIZE;
   fwrite(&width, sizeof width, 1, file);

   bits32 height = SIZE;
   fwrite(&height, sizeof height, 1, file);

   bits16 planes = NUMBER_PLANES;
   fwrite(&planes, sizeof planes, 1, file);

   bits16 bitsPerPixel = BITS_PER_PIXEL;
   fwrite(&bitsPerPixel, sizeof bitsPerPixel, 1, file);

   bits32 compression = NO_COMPRESSION;
   fwrite(&compression, sizeof compression, 1, file);

   bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite(&imageSize, sizeof imageSize, 1, file);

   bits32 hResolution = PIX_PER_METRE;
   fwrite(&hResolution, sizeof hResolution, 1, file);

   bits32 vResolution = PIX_PER_METRE;
   fwrite(&vResolution, sizeof vResolution, 1, file);

   bits32 numColors = NUM_COLORS;
   fwrite(&numColors, sizeof numColors, 1, file);

   bits32 importantColors = NUM_COLORS;
   fwrite(&importantColors, sizeof importantColors, 1, file);
}

int manFormula(double re, double im){
   complexNum original;
   original.re = re;
   original.im = im;
   original.mod = calculateMod(original.re, original.im);
   complexNum old = original;
   complexNum new;
   new.re = 0;
   new.im = 0;
   new.mod = 0;
   int steps = 1;
      while (new.mod < 2){
         if (original.mod > 2){
            return steps;
//            printf("Steps: %d\n", steps);
         }
         new.re = (old.re*old.re) - (old.im*old.im) + original.re;
         new.im = (2*old.re*old.im) + original.im;
         new.mod = calculateMod(new.re, new.im);
         steps++;
//         printf("The Original one is: %lf %lfi\n", original.re, original.im);
//         printf("The Old one is: %lf %lfi\n", old.re, old.im);
//         printf("The new one is: %lf %lfi\n", new.re, new.im);
         if (steps == 256){
            return steps;
//            printf("Steps: %d\n", steps);
         }
         old = new;
   }
//   printf("Steps: %d\n", steps);
   return steps;
}

int calculateMod(double re, double im){
   double modulus = 0;
   modulus = sqrt((re * re) + (im * im));
   return modulus;
}

void createBMP(FILE *file, float startX, float startY, double zoomNum){
   int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);
   int pos = 0;
   int i = 0;
   int j = 0;
   float sizeFloat = SIZE;
   complexNum c;
   c.re = (startX * zoomNum);
   c.im = (startY * zoomNum);
   bits8 byte1;
   bits8 byte2;
   bits8 byte3;
   while (pos < numBytes){
      while (j < 1536){
         while (i < 1536){
            if (manFormula(c.re, c.im) == 256){
               byte1 = stepsToGreen(manFormula(c.re, c.im));
               byte2 = stepsToBlue(manFormula(c.re, c.im));
               byte3 = stepsToRed(manFormula(c.re, c.im));
            } else {
               byte1 = stepsToGreen(manFormula(c.re, c.im));
               byte2 = stepsToBlue(manFormula(c.re, c.im));
               byte3 = stepsToRed(manFormula(c.re, c.im));
            }
            fwrite(&byte1, sizeof byte1, 1, file);
            fwrite(&byte2, sizeof byte2, 1, file);
            fwrite(&byte3, sizeof byte3, 1, file);
            c.re += (1/(sizeFloat) * zoomNum) * 3;
            i+=3;
         }
         c.im += (((1/sizeFloat) * 4) * zoomNum);
         c.re = startX;
         j++;
         i = 0;
      }
      pos += 3;
   }
   printf("pos %d\n", pos);
   printf("j %d\n", j);
   printf("c %lf %lfi\n", c.re, c.im);
}
