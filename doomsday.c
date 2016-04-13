/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by BRIAN LAM
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7
 
int dayOfWeek (int doomsday, int leapYear, int month, int day);
 
int main (int argc, char * argv[]) {
   // EXACT DOOMSDAYS
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);
   // DOOMSDAY + 1
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
   // NON LEAP YEAR Feb and March
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2, 27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3,  0) == THURSDAY);
   // LEAP YEAR TESTS JAN and FEB
   assert (dayOfWeek (THURSDAY,  TRUE,   1,  4) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   1, 10) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   2, 29) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   2, 14) == WEDNESDAY);
   // LEAP YEAR TESTS NON JAN and FEB
   assert (dayOfWeek (THURSDAY,  TRUE,   3, 27) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   4,  5) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   5,  9) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   6,  6) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   7, 11) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   8,  8) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,   9,  5) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  10, 10) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  11,  7) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  TRUE,  12, 12) == THURSDAY);
   // BRIAN'S TESTS - First day of every month - NON LEAP YEAR
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  1) == TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  2,  1) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3,  1) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  1) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  5,  1) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  6,  1) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  7,  1) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  8,  1) == THURSDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  1) == SUNDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 10,  1) == TUESDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 11,  1) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE, 12,  1) == SUNDAY);

   // OTHER LEAP YEAR TESTS
   assert (dayOfWeek (THURSDAY, TRUE, 2, 2) == FRIDAY);
   assert (dayOfWeek (FRIDAY,   TRUE, 2, 4) == MONDAY);
   assert (dayOfWeek (SATURDAY, TRUE, 2, 8) == SATURDAY);
   assert (dayOfWeek (SUNDAY,   TRUE, 2, 29) == SUNDAY);
   assert (dayOfWeek (MONDAY,   TRUE, 2, 28) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   TRUE, 2, 17) == THURSDAY);
   assert (dayOfWeek (WEDNESDAY, TRUE, 2, 1) == WEDNESDAY);
   assert (dayOfWeek (THURSDAY, TRUE, 1, 29) == MONDAY);
   assert (dayOfWeek (FRIDAY,   TRUE, 1, 1) == TUESDAY);
   assert (dayOfWeek (SATURDAY, TRUE, 1, 30) == THURSDAY);
 
   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;
   dayOfWeek = 0; // Declaring the variable for testing purposes --> DELETE WHEN COMPLETED

   // Parsing values into the function
   //scanf ("%d %d %d %d", &doomsday, &leapYear, &month, &day);

   // NON LEAP YEAR + satisfying 4/4 6/6 8/8 10/10 12/12 conditions
   if (month == 4) {
      dayOfWeek = (((day + 7) - 4) % 7 + doomsday) % 7;     
   } else if (month == 6) {
      dayOfWeek = (((day + 7) - 6) % 7 + doomsday) % 7;
   } else if (month == 8) {
      dayOfWeek = (((day + 14) - 8) % 7 + doomsday) % 7;
   } else if (month == 10) {
      dayOfWeek = (((day + 14) - 10) % 7 + doomsday) % 7;
   } else if (month == 12) {
      dayOfWeek = (((day + 14) - 12) % 7 + doomsday) % 7;
   }

   // NON LEAP YEAR + satisfying 5/9 9/5 conditions
   if (month == 5) {
      dayOfWeek = (((day + 14) - 9) % 7 + doomsday) % 7;
   }

   if (month == 9) {
      dayOfWeek = (((day + 14) - 5) % 7 + doomsday) % 7;
   }

   // NON LEAP YEAR + satisfying 7/11 11/7 conditions
   if (month == 7) {
      dayOfWeek = (((day + 14) - 11) % 7 + doomsday) % 7;
   }

   if (month == 11) {
      dayOfWeek = (((day + 7) - 7) % 7 + doomsday) % 7;
   }

   // NON LEAP YEAR + satisfying MONTH 3 (where doomsday = 0/3) (doomsday for FEB & MARCH)
   if (month == 3) {
      dayOfWeek = (day % 7 + doomsday) % 7;
   }

   if (month == 2) {
      dayOfWeek = ((day % 7 + doomsday) % 7) % 7;
   }

   // NON LEAP YEAR + satisfying MONTH 1 (where doomsday = 3/1)
   if (month == 1 && leapYear == FALSE) {
      dayOfWeek = (((day + 21) - 3) % 7 + doomsday) % 7;
   }

   // LEAP YEAR TESTS January and February
   if (month == 1 && leapYear == TRUE) {
      dayOfWeek = (((day + 21) - 4) % 7 + doomsday) % 7;
   }

   if (month == 2 && leapYear == TRUE) {
      dayOfWeek = (((day + 35) - 29) % 7 + doomsday) % 7;
   }

   // LEAP YEAR TESTS NON January and February

   if (month == 3 && leapYear == TRUE) {
      dayOfWeek = (day % 7 + doomsday) % 7;
   }

   if (month == 4 && leapYear == TRUE) {
      dayOfWeek = (((day + 7) - 4) % 7 + doomsday) % 7;
   }

   if (month == 5 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 9) % 7 + doomsday) % 7;
   }

   if (month == 6 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 6) % 7 + doomsday) % 7;
   }

   if (month == 7 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 11) % 7 + doomsday) % 7;
   }

   if (month == 8 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 8) % 7 + doomsday) % 7;
   }

   if (month == 9 && leapYear == TRUE) {
      dayOfWeek = (((day + 7) - 5) % 7 + doomsday) % 7;
   }

   if (month == 10 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 10) % 7 + doomsday) % 7;
   }

   if (month == 11 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 7) % 7 + doomsday) % 7;
   }

   if (month == 12 && leapYear == TRUE) {
      dayOfWeek = (((day + 14) - 12) % 7 + doomsday) % 7;
   }
 
   return (dayOfWeek);
}
 
 