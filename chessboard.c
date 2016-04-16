/*
 *  chessboard.c
 *  create a 512x512 BMP of a chessboard, with user specified size (in pixels)
 *  of the black and white squares on the board.  bottom right square must be white.
 *
 *  Created by Richard Buckland on 14/04/11, edited 5/4/14
 *  Licensed under Creative Commons BY 3.0.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
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
#define BMP_FILE "chess.bmp"
 
typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;
 
void writeHeader (FILE *file);
 
int main (int argc, char *argv[]) {
 
   // check that the types have the size i'm relying on here
   assert (sizeof(bits8)  == 1);
   assert (sizeof(bits16) == 2);
   assert (sizeof(bits32) == 4);
 
   FILE *outputFile;
   int squareSize;
 
   outputFile = fopen(BMP_FILE, "wb");
   assert ((outputFile!=NULL) && "Cannot open file");
 
   writeHeader(outputFile);
 
   printf ("Enter square size (must be a factor of %d): \n", SIZE);
   scanf ("%d", &squareSize);
   assert (SIZE % squareSize == 0); // Makes sure it is a multiple of 512
 
   int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);
   int pos = 0;
   bits8 byte;

   // Brian's code

   int row = 0;
   int column = 1;

   while (pos < numBytes) {
      // Colour in black
      while (pos < (squareSize*3) && row == 0) {
         byte = 0;
         fwrite (&byte, sizeof byte, 1, outputFile);
         pos++;
      }
      // Colour in whites
      while (pos < (squareSize*3) && column == 1) {
         byte = 255;
         fwrite (&byte, sizeof byte, 1, outputFile);
         pos++;
      }

      // byte = 0;
      // byte = 255;

      fwrite (&byte, sizeof byte, 1, outputFile);
      pos++;
   }
 
   // End of Brian's code


   fclose(outputFile);
 
   return EXIT_SUCCESS;
}
 
void writeHeader (FILE *file) {
   assert(sizeof (bits8) == 1);
   assert(sizeof (bits16) == 2);
   assert(sizeof (bits32) == 4);
 
   bits16 magicNumber = MAGIC_NUMBER;
   fwrite (&magicNumber, sizeof magicNumber, 1, file);
 
   bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&fileSize, sizeof fileSize, 1, file);
 
   bits32 reserved = 0;
   fwrite (&reserved, sizeof reserved, 1, file);
 
   bits32 offset = OFFSET;
   fwrite (&offset, sizeof offset, 1, file);
 
   bits32 dibHeaderSize = DIB_HEADER_SIZE;
   fwrite (&dibHeaderSize, sizeof dibHeaderSize, 1, file);
 
   bits32 width = SIZE;
   fwrite (&width, sizeof width, 1, file);
 
   bits32 height = SIZE;
   fwrite (&height, sizeof height, 1, file);
 
   bits16 planes = NUMBER_PLANES;
   fwrite (&planes, sizeof planes, 1, file);
 
   bits16 bitsPerPixel = BITS_PER_PIXEL;
   fwrite (&bitsPerPixel, sizeof bitsPerPixel, 1, file);
 
   bits32 compression = NO_COMPRESSION;
   fwrite (&compression, sizeof compression, 1, file);
 
   bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&imageSize, sizeof imageSize, 1, file);
 
   bits32 hResolution = PIX_PER_METRE;
   fwrite (&hResolution, sizeof hResolution, 1, file);
 
   bits32 vResolution = PIX_PER_METRE;
   fwrite (&vResolution, sizeof vResolution, 1, file);
 
   bits32 numColors = NUM_COLORS;
   fwrite (&numColors, sizeof numColors, 1, file);
 
   bits32 importantColors = NUM_COLORS;
   fwrite (&importantColors, sizeof importantColors, 1, file);
 
}