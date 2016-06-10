#include <stdio.h>
#include <stdlib.h>
int ten (int n);
int main (int argc, char *argv[]) {
   printf ("%d\n", ten (9876));
return 0; }
int ten (int n) {
   int Ten = 10;
   if (n < 10) {
      Ten = n % Ten;
   } else {
      Ten = ten ((n % Ten) + ten (n / Ten));
   }
return Ten; }