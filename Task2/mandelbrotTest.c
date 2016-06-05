// sample unit tests for the escapeSteps function

// to run these tests:
//   1. rename or comment out the main function in mandelbrot.c
//   2. compile the tests using
//     gcc -Wall -Werror -O -std=c99 -o mandelbrotTest mandelbrot.c mandelbrotTest.c
//   3. run mandelbrotTest

// richard buckland
// 29 april 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "mandelbrot.h"

static void testEscapeSteps(void) {
   printf (" Testing escapeTests ...\n");
   printf (
     "  (using a few sample unit tests only - the automarker "
     "will use more tests)\n"
   );

   assert (escapeSteps (100.0, 100.0) == 1);
   assert (escapeSteps (0.0, 0.0)     == 256);

   assert (escapeSteps (-1.5000000000000, -1.5000000000000) == 1);
   assert (escapeSteps (-1.4250000000000, -1.4250000000000) == 1);
   assert (escapeSteps (-1.3500000000000, -1.3500000000000) == 2);
   assert (escapeSteps (-1.2750000000000, -1.2750000000000) == 2);
   assert (escapeSteps (-1.2000000000000, -1.2000000000000) == 2);
   assert (escapeSteps (-1.1250000000000, -1.1250000000000) == 3);
   assert (escapeSteps (-1.0500000000000, -1.0500000000000) == 3);
   assert (escapeSteps (-0.9750000000000, -0.9750000000000) == 3);
   assert (escapeSteps (-0.9000000000000, -0.9000000000000) == 3);
   assert (escapeSteps (-0.8250000000000, -0.8250000000000) == 4);
   assert (escapeSteps (-0.7500000000000, -0.7500000000000) == 4);
   assert (escapeSteps (-0.6750000000000, -0.6750000000000) == 6);
   assert (escapeSteps (-0.6000000000000, -0.6000000000000) == 12);
   assert (escapeSteps (-0.5250000000000, -0.5250000000000) == 157);
   assert (escapeSteps (-0.4500000000000, -0.4500000000000) == 256);
   assert (escapeSteps (-0.3750000000000, -0.3750000000000) == 256);
   assert (escapeSteps (-0.3000000000000, -0.3000000000000) == 256);
   assert (escapeSteps (-0.2250000000000, -0.2250000000000) == 256);
   assert (escapeSteps (-0.1500000000000, -0.1500000000000) == 256);
   assert (escapeSteps (-0.0750000000000, -0.0750000000000) == 256);
   assert (escapeSteps (-0.0000000000000, -0.0000000000000) == 256);

   assert (escapeSteps (-0.5400000000000, 0.5600000000000) == 256);
   assert (escapeSteps (-0.5475000000000, 0.5650000000000) == 58);
   assert (escapeSteps (-0.5550000000000, 0.5700000000000) == 28);
   assert (escapeSteps (-0.5625000000000, 0.5750000000000) == 22);
   assert (escapeSteps (-0.5700000000000, 0.5800000000000) == 20);
   assert (escapeSteps (-0.5775000000000, 0.5850000000000) == 15);
   assert (escapeSteps (-0.5850000000000, 0.5900000000000) == 13);
   assert (escapeSteps (-0.5925000000000, 0.5950000000000) == 12);
   assert (escapeSteps (-0.6000000000000, 0.6000000000000) == 12);

   assert (escapeSteps (0.2283000000000, -0.5566000000000) == 20);
   assert (escapeSteps (0.2272500000000, -0.5545000000000) == 19);
   assert (escapeSteps (0.2262000000000, -0.5524000000000) == 19);
   assert (escapeSteps (0.2251500000000, -0.5503000000000) == 20);
   assert (escapeSteps (0.2241000000000, -0.5482000000000) == 20);
   assert (escapeSteps (0.2230500000000, -0.5461000000000) == 21);
   assert (escapeSteps (0.2220000000000, -0.5440000000000) == 22);
   assert (escapeSteps (0.2209500000000, -0.5419000000000) == 23);
   assert (escapeSteps (0.2199000000000, -0.5398000000000) == 26);
   assert (escapeSteps (0.2188500000000, -0.5377000000000) == 256);
   assert (escapeSteps (0.2178000000000, -0.5356000000000) == 91);
   assert (escapeSteps (0.2167500000000, -0.5335000000000) == 256);

   assert (escapeSteps (-0.5441250000000, 0.5627500000000) == 119);
   assert (escapeSteps (-0.5445000000000, 0.5630000000000) == 88);
   assert (escapeSteps (-0.5448750000000, 0.5632500000000) == 83);
   assert (escapeSteps (-0.5452500000000, 0.5635000000000) == 86);
   assert (escapeSteps (-0.5456250000000, 0.5637500000000) == 74);
   assert (escapeSteps (-0.5460000000000, 0.5640000000000) == 73);
   assert (escapeSteps (-0.5463750000000, 0.5642500000000) == 125);
   assert (escapeSteps (-0.5467500000000, 0.5645000000000) == 75);
   assert (escapeSteps (-0.5471250000000, 0.5647500000000) == 60);
   assert (escapeSteps (-0.5475000000000, 0.5650000000000) == 58);

   assert (escapeSteps (0.2525812510000, 0.0000004051626) == 60);
   assert (escapeSteps (0.2524546884500, 0.0000004049095) == 61);
   assert (escapeSteps (0.2523281259000, 0.0000004046564) == 63);
   assert (escapeSteps (0.2522015633500, 0.0000004044033) == 65);
   assert (escapeSteps (0.2520750008000, 0.0000004041502) == 67);
   assert (escapeSteps (0.2519484382500, 0.0000004038971) == 69);
   assert (escapeSteps (0.2518218757000, 0.0000004036441) == 72);
   assert (escapeSteps (0.2516953131500, 0.0000004033910) == 74);
   assert (escapeSteps (0.2515687506000, 0.0000004031379) == 77);
   assert (escapeSteps (0.2514421880500, 0.0000004028848) == 81);
   assert (escapeSteps (0.2513156255000, 0.0000004026317) == 85);
   assert (escapeSteps (0.2511890629500, 0.0000004023786) == 89);
   assert (escapeSteps (0.2510625004000, 0.0000004021255) == 94);
   assert (escapeSteps (0.2509359378500, 0.0000004018724) == 101);
   assert (escapeSteps (0.2508093753000, 0.0000004016193) == 108);
   assert (escapeSteps (0.2506828127500, 0.0000004013662) == 118);
   assert (escapeSteps (0.2505562502000, 0.0000004011132) == 131);
   assert (escapeSteps (0.2504296876500, 0.0000004008601) == 150);
   assert (escapeSteps (0.2503031251000, 0.0000004006070) == 179);
   assert (escapeSteps (0.2501765625500, 0.0000004003539) == 235);
   assert (escapeSteps (0.2500500000000, 0.0000004001008) == 256);

   assert (escapeSteps (0.3565670191423, 0.1094322101123) == 254);
   assert (escapeSteps (0.3565670191416, 0.1094322101120) == 255);
   assert (escapeSteps (0.3565670191409, 0.1094322101118) == 256);
   assert (escapeSteps (0.3565670950000, 0.1094322330000) == 222);
   assert (escapeSteps (0.3565670912300, 0.1094322318625) == 222);
   assert (escapeSteps (0.3565670874600, 0.1094322307250) == 222);
   assert (escapeSteps (0.3565670836900, 0.1094322295875) == 222);
   assert (escapeSteps (0.3565670799200, 0.1094322284500) == 222);
   assert (escapeSteps (0.3565670761500, 0.1094322273125) == 222);
   assert (escapeSteps (0.3565670723800, 0.1094322261750) == 222);
   assert (escapeSteps (0.3565670686100, 0.1094322250375) == 223);
   assert (escapeSteps (0.3565670648400, 0.1094322239000) == 223);
   assert (escapeSteps (0.3565670610700, 0.1094322227625) == 224);
   assert (escapeSteps (0.3565670573000, 0.1094322216250) == 225);
   assert (escapeSteps (0.3565670535300, 0.1094322204875) == 256);
   assert (escapeSteps (0.3565670497600, 0.1094322193500) == 256);
   assert (escapeSteps (0.3565670459900, 0.1094322182125) == 237);
   assert (escapeSteps (0.3565670422200, 0.1094322170750) == 233);
   assert (escapeSteps (0.3565670384500, 0.1094322159375) == 232);
   assert (escapeSteps (0.3565670346800, 0.1094322148000) == 232);
   assert (escapeSteps (0.3565670309100, 0.1094322136625) == 232);
   assert (escapeSteps (0.3565670271400, 0.1094322125250) == 233);
   assert (escapeSteps (0.3565670233700, 0.1094322113875) == 234);
   assert (escapeSteps (0.3565670196000, 0.1094322102500) == 243);


   printf (" ... escapeSteps tests passed!\n");
}
