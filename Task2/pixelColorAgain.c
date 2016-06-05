/*

Creating a fiery red colour.

Using an exponential function to increment intensity for RED and GREEN colours.
Blue remains constant at 0 intensity.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pixelColor.h"

#define STEPS_RED 127 // Max iterations for the red function
#define STEPS_GREEN 128 // Min iterations for the green function
#define MAX_STEPS 256

unsigned char stepsToRed(int steps) {
    unsigned char intensity;
    if (steps < 200){
       intensity = steps;
    } else if (steps > 200 && steps < 240){
       intensity = steps/2;
    } else if (steps == 256){
       intensity = 0;
    } else {
       intensity = steps - 10;
    }
    return intensity;
}

unsigned char stepsToGreen(int steps) {
    unsigned char intensity;
    if (steps < 200) {
       intensity = steps/10;
    } else if (steps > 200 && steps < 240) {
       intensity = steps;
    } else if (steps == 256){
       intensity = 0;
    } else {
       intensity = steps/2;
    }
    return intensity;
}

unsigned char stepsToBlue(int steps) {            /* BLUE remains constant */
    unsigned char intensity;
    intensity = 0;
    return intensity;
}   
