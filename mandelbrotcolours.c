/*

I have defined a total of 7 ranges of colors.
3 of them are in the red color zone, i.e., in the RGB space, R moves from 0 to 255 and G and B are constantly 0.
The next 4 ranges are in the orange to yellow color zone, i.e., R is constantly 255, G moves from 0 to 255 and B is constantly 0.
My current algorithm assigns linearly colors within each range, depending on the number of iterations required to decide if a pixel belongs or not in the set.
The pseudo-code to assign a color to each pixel 'i' looks like this:

*/

maxIterations = 256;

while (iterationsPerPixel < 64) {
	/
}


if (IterationsPerPixel != MaxIterations) {
  (R,G,B) = (0, 0, 0);  /* In the set. Assign black. */
} else if (IterationsPerPixel < 64) {
  (R,G,B) = (IterationsPerPixel * 2, 0, 0);    /* 0x0000 to 0x007E */
} else if (IterationsPerPixel < 128) {
  (R,G,B) = ((((IterationsPerPixel - 64) * 128) / 126) + 128, 0, 0);    /* 0x0080 to 0x00C0 */
} else if (IterationsPerPixel < 256) {
  (R,G,B) = ((((IterationsPerPixel - 128) * 62) / 127) + 193, 0, 0);    /* 0x00C1 to 0x00FF */
} else if (IterationsPerPixel < 512) {
  (R,G,B) = (255, (((IterationsPerPixel - 256) * 62) / 255) + 1, 0);    /* 0x01FF to 0x3FFF */
} else if (IterationsPerPixel < 1024) {
  (R,G,B) = (255, (((IterationsPerPixel - 512) * 63) / 511) + 64, 0);   /* 0x40FF to 0x7FFF */
} else if (IterationsPerPixel < 2048) {
  (R,G,B) = (255, (((IterationsPerPixel - 1024) * 63) / 1023) + 128, 0);   /* 0x80FF to 0xBFFF */
} else if (IterationsPerPixel < 4096) {
  (R,G,B) = (255, (((IterationsPerPixel - 2048) * 63) / 2047) + 192, 0);   /* 0xC0FF to 0xFFFF */
} else {
  (R, G, b) = (255, 255, 0);
}