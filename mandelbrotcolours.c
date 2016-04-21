/*

(1) I have defined a total of 8 ranges of COLOURS for 8 sections of STEPS
(2) FIRST 3 = of them are in the red colour zone
    i.e., in the RGB space, R moves from 0 to 255 and G and B are constantly 0.
(3) NEXT 5 = are in the orange to yellow colour zone
    i.e., R is constantly 255, G moves from 0 to 255 and B is constantly 0.
(4) This algorithm assigns colors within each range, depending on the number of iterations required
    to decide if a pixel belongs or not in the set.

*/

// Using RGB ranges (0-255,0-255,0) to create a fiery red and orange colour.
// This process can be repeated for other shades, such as a "winter blue" shade.

#include <stdio.h>
#include <stdlib.h>
#include "pixelColor.h"
#include "mandelbrot.h"

#define STEPS_SECTION_1 32
#define STEPS_SECTION_2 64
#define STEPS_SECTION_3 96
#define STEPS_SECTION_4 128
#define STEPS_SECTION_5 160
#define STEPS_SECTION_6 192
#define STEPS_SECTION_7 224
#define STEPS_SECTION_8 256 // Maximum iterations

unsigned char stepsToRed (int steps) {
    unsigned char intensity;
    if (steps <= STEPS_SECTION_1) {                /* RED SHADE 1 */
        intensity = (steps + STEPS_SECTION_2);
    } else if (steps <= STEPS_SECTION_2) {         /* RED SHADE 2 */
        intensity = (steps + STEPS_SECTION_3);
    } else if (steps <= STEPS_SECTION_3) {         /* RED SHADE 3 */
        intensity = (steps + STEPS_SECTION_4);
    } else if (steps <= STEPS_SECTION_4) {         /* ORANGE TO YELLOW 1 */
        intensity = 255;
    } else if (steps <= STEPS_SECTION_5) {         /* ORANGE TO YELLOW 2 */
        intensity = 255;
    } else if (steps <= STEPS_SECTION_6) {         /* ORANGE TO YELLOW 3 */
        intensity = 255;
    } else if (steps <= STEPS_SECTION_7) {         /* ORANGE TO YELLOW 4 */
        intensity = 255;
    } else if (steps == STEPS_SECTION_8) {         /* In set. Assign black */
        intensity = 0;
    }
    return intensity;
}

unsigned char stepsToGreen (int steps) {
    unsigned char intensity;
    if (steps <= STEPS_SECTION_1) {                /* RED SHADE 1 */
        intensity = 0;
    } else if (steps <= STEPS_SECTION_2) {         /* RED SHADE 2 */
        intensity = 0;
    } else if (steps <= STEPS_SECTION_3) {         /* RED SHADE 3 */
        intensity = 0;
    } else if (steps <= STEPS_SECTION_4) {         /* ORANGE TO YELLOW 1 */
        intensity = ((steps + STEPS_SECTION_5)/2);
    } else if (steps <= STEPS_SECTION_5) {         /* ORANGE TO YELLOW 2 */
        intensity = ((steps + STEPS_SECTION_6)/2);
    } else if (steps <= STEPS_SECTION_6) {         /* ORANGE TO YELLOW 3 */
        intensity = ((steps + STEPS_SECTION_7)/2);
    } else if (steps <= STEPS_SECTION_7) {          /* ORANGE TO YELLOW 4 */
        intensity = ((steps + STEPS_SECTION_8)/2);
    } else if (steps == STEPS_SECTION_8) {         /* In set. Assign black */
        intensity = 0;
    }
    return intensity;
}

unsigned char stepsToBlue (int steps) {            /* BLUE remains constant */
    unsigned char intensity;
    if (steps <= STEPS_SECTION_8) {
        intensity = 0;
    }
    return intensity;
}