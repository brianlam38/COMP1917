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
   // DAY AFTER DOOMSDAYS
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
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
 
   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
 
int getDayOfWeek(int doomsday, int day, int offset) {
   return (((day + DAYSINAFORTNIGHT) - offset) % DAYSINAWEEK + doomsday);
}

int dayOfWeek (int doomsday, int leapYear, int month, int day) {
   int dayOfWeek;
   dayOfWeek = 0; // Declaring the variable for testing purposes --> DELETE WHEN COMPLETED

   // Parsing values into the function
   //scanf ("%d %d %d %d", &doomsday, &leapYear, &month, &day);

   // NON LEAP YEAR + satisfying 4/4 6/6 8/8 10/10 12/12 conditions
   if (month == JULY) {
      
         dayOfWeek = getDayOfWeek(4);
      
   } else if (month == 6) {
      dayOfWeek = ((day - 6) % 7 + doomsday);
      if (day < 6) {
         dayOfWeek = (((day + 7) - 6) % 7 + doomsday);
      }
   } else if (month == 8) {
      dayOfWeek = ((day - 8) % 7 + doomsday);
      if (day < 8) {
         dayOfWeek = (((day + 14) - 8) % 7 + doomsday);
      }
   } else if (month == 10) {
      dayOfWeek = ((day - 10) % 7 + doomsday);
      if (day < 10) {
         dayOfWeek = (((day + 14) - 10) % 7 + doomsday);
      }
   } else if (month == 12) {
      dayOfWeek = ((day - 12) % 7 + doomsday);
      if (day < 12) {
         dayOfWeek = (((day + 14) - 12) % 7 + doomsday);
      }
   }

   // NON LEAP YEAR + satisfying 5/9 9/5 conditions
   if (month == 5) {
      dayOfWeek = ((day - 9) % 7 + doomsday);
      if (day < 9) {
         dayOfWeek = (((day + 14) - 9) % 7 + doomsday);
      }
   }

   // NON LEAP YEAR + satisfying 7/11 11/7 conditions
   if (month == 7) {
      dayOfWeek = ((day - 11) % 7 + doomsday);
      if (day < 11) {
         dayOfWeek = (((day + 14) - 11) % 7 + doomsday);
      }
   }

   if (month == 11) {
      dayOfWeek = ((day - 7) % 7 + doomsday);
      if (day < 7) {
         dayOfWeek = (((day + 7) - 7) % 7 + doomsday);
      }
   }

   // NON LEAP YEAR + satisfying MONTH 3 (where doomsday = 0/3) (doomsday for FEB & MARCH)
   if (month == 3) {
      dayOfWeek = ((day % 7 + doomsday) % 7);
   }

   if (month == 2) {
      dayOfWeek = ((day % 7 + doomsday) % 7);
   }




   // INSERT YOUR CODE HERE
   // QUESTION: Which day of the week (0-6) does xTH DAY / y MONTH fall on?
   // NOTE1: Year doesn't matter. Only LEAPYEAR vs YEAR + DOOMSDAY on the specific year.

   // THE INPUTS ARE THE ASSERTS
   // POSSIBLY WRITE THE CODE TO GET IT TO RUN FIRST, AND THEN ADD MORE OF YOUR OWN TESTS (See unit testing) (Add more asserts)
   // 1. Parse in the doomsday integer -->
   // 2. Assign the integer to the doomsdays -->
   // 3. Calculate what day the inputted int month and int day will fall under
   // 4. Assign the answer to dayOfWeek and return it --> returns the DAY that the user wants to find out.

 
   return (dayOfWeek);
}
 
 