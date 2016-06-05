#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "extract.h"

typedef struct _stringCoords {

   char x[sizeof (double)];
   char y[sizeof (double)];
   int counter;

} stringCoords; 

static char *getcoord(char *message, char character);

int main (int argc, char *argv[]) {
    
    char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp";
 
    triordinate dat = extract (message);
 
    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
 
    assert (dat.x == 3.14);
    assert (dat.y == -0.141);
    assert (dat.z == 5);

    return EXIT_SUCCESS;
}

triordinate extract (char *message){
   triordinate data;

   char * x = getcoord(message, 'x');
   char * y = getcoord(message, 'y');
   char * z = getcoord(message, 'z');

   data.x = myAtoD(x);
   data.y = myAtoD(y);
   data.z = myAtoL(z);

   return data;
}
static char *getcoord(char *message, char character){
   int i = 0;
   int j = 0; 
   static char x[sizeof (double)];
   while (message[i] != character){
      i++;
   }
   i++;
   while (message[i] != '_'){
      x[j] = message[i];
      i++;
      j++;
   }
   return x;
}
double myAtoD (char *message){
   double AtoD = 0;
   int i = 0;
   int power = 0;
   while (i < strlen(message)){
      if (message[i] == '1'){
         AtoD += 1 * pow(10, strlen(message)  - i);
      } else if (message[i] == '2'){
         AtoD += 2 *  pow(10, strlen(message) - i);
      } else if (message[i] == '3'){
         AtoD += 3 * pow(10, strlen(message) - i);
      } else if (message[i] == '4'){
         AtoD += 4 * pow(10, strlen(message) - i);
      } else if (message[i] == '5'){
         AtoD += 5 * pow(10, strlen(message) - i);
      } else if (message[i] == '6'){
         AtoD += 6 * pow(10, strlen(message) - i);
      } else if (message[i] == '7'){
         AtoD += 7 * pow(10, strlen(message) - i);
      } else if (message[i] == '8'){
         AtoD += 8 * pow(10, strlen(message) - i);
      } else if (message[i] == '9'){
         AtoD += 9 * pow(10, strlen(message) - i);
      } else if (message[i] == '.'){
         AtoD = (AtoD/10);
         power = strlen(message) - i;
      }
      i++;
   } 
   if (message[0] == '-'){
      AtoD = -AtoD;
      AtoD = AtoD/(1*pow(10, power));
   } else {
      AtoD = AtoD/(1*pow(10, power));
   }
   return AtoD;
}

long myAtoL (char *message){
   long AtoL = 0;
   int i = 0;

   while (i < strlen(message)){
      if (message[i] == '1'){
         AtoL += 1 * pow(10, strlen(message)  - i);
      } else if (message[i] == '2'){
         AtoL += 2 *  pow(10, strlen(message) - i);
      } else if (message[i] == '3'){
         AtoL += 3 * pow(10, strlen(message) - i);
      } else if (message[i] == '4'){
         AtoL += 4 * pow(10, strlen(message) - i);
      } else if (message[i] == '5'){
         AtoL += 5 * pow(10, strlen(message) - i);
      } else if (message[i] == '6'){
         AtoL += 6 * pow(10, strlen(message) - i);
      } else if (message[i] == '7'){
         AtoL += 7 * pow(10, strlen(message) - i);
      } else if (message[i] == '8'){
         AtoL += 8 * pow(10, strlen(message) - i);
      } else if (message[i] == '9'){
         AtoL += 9 * pow(10, strlen(message) - i);
      }
      i++;
   }
   AtoL = AtoL/10;
   if (message[0] == '-'){
      AtoL = -AtoL;
   }
   return AtoL;
}
