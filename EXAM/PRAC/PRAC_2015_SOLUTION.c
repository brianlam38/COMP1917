//Unofficial Practice Prac Exam Solution 2015
//Created by Michael Simarta

#include <stdio.h>
#include <stdlib.h>
#define MAX_BOWLS 21
#define ALL_PINS_DOWN 10

void displayBowls (char array[]);
int calculateSpare(char array[], int i);
int calculateStrike(char array[], int i);
int calculateTotal(char array[]);

int main (int argc, char* argv[]) {
    char character = getchar();
    char arrayOfBowls[MAX_BOWLS] = {};
    int index = 0;
    int total = 0;

    //gets up to 21 characters and put it in the array
    while (character != EOF && index < MAX_BOWLS) {

        //check that the character is valid in bowling (but not the order)
        if (character == 'X' || character == '/' || character == ' ' || 
            character == '-' || (character >= '1' && character <= '9')) {
            arrayOfBowls[index] = character;
            index++;
        }
		
        character = getchar();
    }

    displayBowls(arrayOfBowls);
    total = calculateTotal(arrayOfBowls);
    printf("\ntotal score: %d\n", total);

}

int calculateTotal(char array[]) {
    int counter = 0;
    int score = 0;

    //determine what kind of calculation is needed, 
    //we do not count the last bowl (it's bonus)
    while (counter < MAX_BOWLS-1) {

        //need at least 2 more bowls if it's a strike otherwise it's bonus 
        //and calculated in the function
        if (array[counter] == 'X' && counter < MAX_BOWLS - 2) {
            score += calculateStrike(array, counter);

        //need at least 1 more bowl if it's a spare otherwise it's bonus 
        //and calculated in the function
        //skips ahead of the number and save time calculating the spare
        } else if (array[counter+1] == '/') {
            score += calculateSpare(array, counter+1);
            counter++;

        //add the number (remember this is in ascii value, so -'0' is required)
        //do not add the last bowl because it's only for bonus
        } else if (array[counter] >= '1' && array[counter] <= '9') {
            score += array[counter] - '0';
        }

        counter++;

        //feel free to comment any of the printf lines out
        //printf ("After Bowl %d, I score %d\n", counter, score);
        if (((counter % 2 == 0) && counter > 1) || counter == MAX_BOWLS-1) {
            printf ("After Frame %d, I score %d\n", counter/2, score);
        }
    }
    return score;
}

int calculateSpare(char array[], int i) {
    int score = ALL_PINS_DOWN;
    i++;

    //check for bonus
    if (i != MAX_BOWLS) {

        if (array[i] >= '1' && array[i] <= '9') {
            score += array[i] - '0';

        //just add 10
        } else if (array[i] == 'X') {
            score += ALL_PINS_DOWN;
        }

        // spare or space will not occur in the next bowl, 
        // no point calculating a - which gives 0
    }
    return score;
}

int calculateStrike(char array[], int i) {
    int score = ALL_PINS_DOWN;
    int bowls = 2;
    i++;

    //check for next 2 bowls
    while (i < MAX_BOWLS && bowls > 0) {

        //just add 10 and reduce 2 bowls, spare cannot be first bowl of a frame
        //this condition must be before numbers or dash condition
        if (array[i+1] == '/') {
            score += ALL_PINS_DOWN;
            bowls -= 2;

        //add the number and reduce 1 bowl
        } else if (array[i] >= '1' && array[i] <= '9') {
            score += array[i] - '0';
            bowls--;

        //add 10 and reduce 1 bowl
        } else if (array[i] == 'X') {
            score += ALL_PINS_DOWN;
            bowls--;

        //no score added but it is still a bowl
        } else if (array[i] == '-') {
            bowls--;
        }
        i++;
    }
    return score;
}

void displayBowls (char array[]) {
    int i = 0;
    while (i < MAX_BOWLS) {
        printf("%c", array[i]);
        i++;
    }
    printf("\nread %d chars\n", i);
}

