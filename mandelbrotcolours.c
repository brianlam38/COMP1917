/*

(1) I have defined a total of 7 ranges of COLOURS for 7 sections of STEPS
(2) FIRST 3 = of them are in the red colour zone
    i.e., in the RGB space, R moves from 0 to 255 and G and B are constantly 0.
(3) NEXT 4 = are in the orange to yellow colour zone
    i.e., R is constantly 255, G moves from 0 to 255 and B is constantly 0.
(4) This algorithm assigns linearly colors within each range, depending on the number of iterations required
    to decide if a pixel belongs or not in the set.

*/

// Using RGB ranges (0-255,0-255,0) to create a fiery red and orange colour.

#include <stdio.h>
#include <stdlib.h>
#include "pixelColor.h"
#include "mandelbrot.h"

#define STEPS_SECTION_1 37
#define STEPS_SECTION_2 74
#define STEPS_SECTION_3 111
#define STEPS_SECTION_4 148
#define STEPS_SECTION_5 185
#define STEPS_SECTION_6 222
#define STEPS_SECTION_7 256 // Maximum iteration

unsigned char stepsToRed (int steps) {
    unsigned char intensity;
    if (steps <= STEPS_SECTION_1) {             /* RED SHADE 1 */
        intensity = ((steps * 2) + 50));
    } else if (steps <= STEPS_SECTION_2) {      /* RED SHADE 2 */
        intensity = ((steps * 1.66) + 75));
    } else if (steps <= STEPS_SECTION_3) {      /* RED SHADE 3 */
        intensity = ((steps * 1.33) + 100));
    } else if (steps <= STEPS_SECTION_4) {      /* ORANGE TO YELLOW 1 */
        intensity = 255;
    } else if (steps <= STEPS_SECTION_5) {      /* ORANGE TO YELLOW 2 */
        intensity = 255;
    } else if (steps <= STEPS_SECTION_6) {      /* ORANGE TO YELLOW 3 */
        intensity = 255;
    } else if (steps < STEPS_SECTION_7) {       /* ORANGE TO YELLOW 4 */
        intensity = 255;
    } else if (steps == STEPS_SECTION_7 {       /* In set. Assign black */
        intensity = 0;
    }
    return intensity;
}

unsigned char stepsToGreen (int steps) {
    unsigned char intensity;
    if (steps <= STEPS_SECTION_1) {             /* RED SHADE 1 */
        intensity = 0;
    } else if (steps <= STEPS_SECTION_2) {      /* RED SHADE 2 */
        intensity = 0;
    } else if (steps <= STEPS_SECTION_3) {      /* RED SHADE 3 */
        intensity = 0);
    } else if (steps <= STEPS_SECTION_4) {      /* ORANGE TO YELLOW 1 */
        intensity = ((steps * 1.25) + 30);
    } else if (steps <= STEPS_SECTION_5) {      /* ORANGE TO YELLOW 2 */
        intensity = ((steps * 1.12) + 60);
    } else if (steps <= STEPS_SECTION_6) {      /* ORANGE TO YELLOW 3 */
        intensity = ((steps * 1.06) + 90);
    } else if (steps < STEPS_SECTION_7) {       /* ORANGE TO YELLOW 4 */
        intensity = ((steps * 1.03) - 10);
    } else if (steps == STEPS_SECTION_7) {      /* In set. Assign black */
        intensity = 0;
    }
    return intensity;
}

unsigned char stepsToBlue (int steps) {
    unsigned char intensity;
    if (steps <= STEPS_SECTION_7) {
        intensity = 0;
    }
    return intensity;
}