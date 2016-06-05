/*
   pixelColor.c
   date: April 24th 2016
   by: Daniel Shougam and Brian Lam
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pixelColor.h"

unsigned char stepsToRed(int steps) {
    unsigned char intensity;
    if (steps < 10){
        intensity = steps;
    } else if (steps > 250) {
        intensity = steps/2;
    } else {
        intensity = 0;
    }
    return intensity;
}

unsigned char stepsToGreen(int steps) {
    unsigned char intensity;
    if (steps < 10){
       intensity = 0;
    } else if(steps > 250){
       intensity = steps - 10;
    } else {
       intensity = steps;
    }
    return intensity;
}

unsigned char stepsToBlue(int steps) {          
    int intensity;
    if (steps < 10){
        intensity = steps/2;
    } else if (steps >250){
        intensity = 0;
    } else {
        intensity = steps;
    }
    return intensity;
}   
