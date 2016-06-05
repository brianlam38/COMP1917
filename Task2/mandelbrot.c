/*
 *  mandelbrot.c
 *  by: Daniel Shougam and Brian Lam
 *  date: 24th April 2016
 *  Containing code created by Richard Buckland on 28/01/11.
 *  Copyright 2012 Licensed under Creative Commons SA-BY-NC 3.0. 
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>
#include "pixelColor.c"
#include "mandelbrot.h"

typedef unsigned char bits8;                        //defines a few types to be used later in the program and for structs
typedef struct _complexNum complexNum;
typedef struct _stringCoords stringCoords;

struct _stringCoords{
   char x[sizeof (double)];
   char y[sizeof (double)];
};

struct _complexNum{
   double re;
   double im; 
   double mod;
   float zoom;
};

complexNum extract(char *message);                    //All the functions that the program uses
double myAtoD(char *message);
float myAtoL(char *message);
int calculateMod(double re, double im);
int waitForConnection (int serverSocket);
int makeServerSocket (int portno);
void serveBMP (int socket, float startX, float startY, float zoomNum);
static void serveHTML(int socket);
static char *getx(char *message);                     //Tried making one function where you send 'x' or 'y' or 'z' in instead of having 3 
static char *gety(char *message);                     //Seperate functions but it didn't want to work :(
static char *getz(char *message);

#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 1000              // after serving this many pages the server will halt. Set it to 1000 to make life easier
#define ZOOM_START 9
#define BYTES_PER_PIXEL 3
#define OFFSET 54                                  //A few #defines for important values for the bmp header
#define SIZE 512
#define FILE_SIZE 787600

int main (int argc, char *argv[]) {
   
   printf ("************************************\n");            //Server code given to us
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   
   
   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n", DEFAULT_PORT);
   printf ("************************************\n");
   
   char request[REQUEST_BUFFER_SIZE];
   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);
      
      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation
      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      complexNum Coords = extract(request);
      if (Coords.re > 5 || Coords.im > 5 || Coords.zoom <= 0){      //Dodgy way to check if its a valid input. I have two bugs here. 
         serveHTML(connectionSocket);                               //1. Only works for the first bmp you request. If you want to change the coordinates
      } else {                                                      //Close the program and run it again. Don't know how to fix this since the code for 
         serveBMP(connectionSocket, Coords.re, Coords.im, Coords.zoom); //getting the coordinates from the url doesn't check for valid inputs and I don't
                                                                        //know how to fix that :(
                                                                        //2. The almondbread website gets a connection error whenever I try to open it.
      }
      // were we able to read any data from the connection?
            
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);
      
      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      // close the connection after sending the page- keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
   
   return EXIT_SUCCESS; 
}

void serveBMP (int socket, float startX, float startY, float zoomNum) {
   char* message;
   unsigned char bmp[FILE_SIZE] = {
        0x42, 0x4d, 0x63, 0x00,                      //BMP header file. Used lots of googling to figure out what numbers should be here
        0x0c, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00,
        0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x02, 
        0x00, 0x00, 0x00, 0x02,
        0x00, 0x00, 0x01, 0x00,
        0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x0c, 0x00, 0xc4, 0x0e,
        0x00, 0x00, 0xc4, 0x0e,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x00, 0x00, 
        0x00, 0x01 
   };

   int numBytes = (SIZE * SIZE * BYTES_PER_PIXEL);         //Code for generating the set
   int pos = 0;
   int i = 0;
   int j = 0;
   float sizeFloat = SIZE;
   complexNum c;
   if (zoomNum == ZOOM_START){                              //Maths to convert given x, y, and z coordinates to numbers that work with the code
      c.zoom = 1;                                           //to generate the set
      c.re = -((c.zoom/2) - startX);
      c.im = -((c.zoom/2) - startY);
   } else if (zoomNum > ZOOM_START) {
      c.zoom = 1/((zoomNum - ZOOM_START)*2);
      c.re = -((c.zoom/2) - startX);
      c.im = -((c.zoom/2) - startY);
   } else {
      c.zoom = ((ZOOM_START - zoomNum) * 2);
      c.re = -((c.zoom / 2) - startX);
      c.im = -((c.zoom / 2) - startY);
   }
   bits8 byte1;
   bits8 byte2;
   bits8 byte3;
   int k = OFFSET;
   while (pos < numBytes){
      while (j < SIZE){
         while(i < SIZE){
             byte1 = stepsToGreen(escapeSteps(c.re, c.im));
             byte2 = stepsToBlue(escapeSteps(c.re, c.im));
             byte3 = stepsToRed(escapeSteps(c.re, c.im));
             bmp[k] = byte1;
             bmp[k + 1] = byte2;
             bmp[k + 2] = byte3;
             i++;
             k+=BYTES_PER_PIXEL;
             pos+=BYTES_PER_PIXEL;
             c.re+=(c.zoom/sizeFloat);
         }
         i = 0;
         c.re = -((c.zoom/2) - startX);
         c.im += (c.zoom/sizeFloat);
         j++;
      }
   }


   // first send the http response header
   
   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
   
   // now send the BMP
   
   printf("Gonna serve that bmp now\n");
   write (socket, bmp, sizeof(bmp));
}

static void serveHTML(int socket) {

   char* message;

   //first send the http response header
   message = "HTTP/1.0 200 Found\n"
             "Content-Type: text/html\n"
             "\n";
   printf("About to send=> %s\n", message);
   write (socket, message, strlen (message));

   message = "<!DOCTYPE html>\n"
             "<script src=\"http://almondbread.cse.unsw.edu.au/tileviewer.js\"></script>"
             "\n";
   write (socket, message, strlen (message));
}

// start the server listening on the specified port number
int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   memset ((char *) &serverAddress, 0,sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );

   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again
   
   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}

complexNum extract (char *message){

   complexNum data;                            //Simple function that takes url and gets x, y, and z coords into doubles and floats to be used in the program

   char * x = getx(message);
   char * y = gety(message);
   char * z = getz(message);

   data.re = myAtoD(x);
   data.im = myAtoD(y);
   data.zoom = myAtoL(z);

   return data;
}

static char *getx(char *message){        //Gets the string version of the x coordinate
   int i = 0;
   int j = 0; 
   static char x[sizeof (double)];

   while (message[i] != 'x'){
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

static char *gety(char *message){        //Gets the string version of the y coordinate
   int i = 0;
   int j = 0; 
   static char y[sizeof (double)];

   while (message[i] != 'y'){
      i++;
   }
   i++;
   while (message[i] != '_'){
      y[j] = message[i];
      i++;
      j++;
   }
   return y;
}

static char *getz(char *message){             //Gets the string version of the z coordinate
   int i = 0;
   int j = 0; 
   static char z[sizeof (double)];

   while (message[i] != 'z'){
      i++;
   }
   i++;
   while (message[i] != '.'){
      z[j] = message[i];
      i++;
      j++;
   }
   return z;
}

double myAtoD(char *message){            //Converts a string to a double
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

float myAtoL(char *message){         //Converts a string to a float
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

int escapeSteps(double x, double y){                  //The function that figures out how many steps for a point to leave the set
   complexNum original;
   original.re = x;
   original.im = y;
   original.mod = calculateMod(original.re, original.im);
   complexNum old = original;
   complexNum new;
   new.re = 0;
   new.im = 0;
   new.mod = 0;
   int steps = 1;
      while (new.mod < 2){
         if (original.mod >= 2){
            return steps;
         }
         new.re = (old.re*old.re) - (old.im*old.im) + original.re;
         new.im = (2*old.re*old.im) + original.im;
         new.mod = calculateMod(new.re, new.im);
         steps++;
         if (steps == 256){
            return steps;
         }
         old = new;
   }
   return steps;
}

int calculateMod(double re, double im){          //Simple function to calculate the modulus of a point
   double modulus = 0;
   modulus = sqrt((re * re) + (im * im));
   return modulus;
}
