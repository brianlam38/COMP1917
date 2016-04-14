/*
	LECTURE 17 - Repetition
*/

/*
	STORYWRITING & REPETITION

	Repetition:
	- Repetition in a story is important, for emphasis (flags that something is important if you use it over & over)
	- Repetition is also important as it lets you see differences --> Point out things that you missed
	- If you've done something once, the next time you don't have to talk about the whole thing again
	- You can just refer to it indirectly to the first time and ppl will get a whole lot of meaning without you actually
	having to say it.

	Fairytales and the "Rule of 3"
	- In fairytales, why do they repeat everything 3 times?
	- They do it, so that it creates a contrast.
	- E.g. Three Little Pigs
	--> A problem (create tension)
	--> A more serious problem (create more tension)
	--> Solve problem.
	--> Contrast makes it more interesting than if they just solved it straight away.

	PARABLE
	- Repetition of something that happens in someones everyday life.

	If you can refer to something outside of the book
	- Saves writer from having to saying anything about it
	- If you assume that the idea is already in the consciousness of someone reading your book
	- You can just hook into that reference and there will be a whole lot of stuff that you won't have to say

	Harry Potter (example of BAD REPETITION)
	- The whole series: "This happens, then this happens, and then this happens... something good happens and its the end."
	- Felt like it had no real structure & it was repeating over and over again. (for no real reason)
	- If the repetition doesn't give you anything, there's no point doing it.

	There is no point in putting repetition in things that aren't important.
	- If there are a lot of things that you don't need, just take out the stuff that isn't important.
*/

#include <stdio.h>
#include <stdlib.h>
#define LINE "*********\n" //For COOL repetition use

void drawChapter(int drawChapter); // Declaration for IMPROVED #2
void singVerse(int batCount); // For the BAT PROGRAM

/*
	chapters.c program (NOOB METHOD)

	Repetition for printf isunnecessary --> if need change later, you'll need to change ALL
*/

int main(int argc, char * argv[]) { // argc = arg count

	printf ("*********\n");
	printf ("Chapter 1\n");
	printf ("*********\n"); 

	return EXIT_SUCCESS;
}

/*
	chapters.c program (COOL METHOD)
*/

int main(int argc, char * argv[]) { // argc = arg count

	printf (LINE); // Using #define
	printf ("Chapter 1\n");
	printf (LINE);

	return EXIT_SUCCESS;
}

void drawLine(void) {
	printf ("*********\n");
}

/*
	IMPROVED chapters.c program (printing out Chapter #2)
*/

int main(int argc, char * argv[]) { // argc = arg count

	printf (LINE); // Using #define
	printf ("Chapter 1\n");
	printf (LINE);

	printf ("\n\n\n\n\n\n");

	printf (LINE)
	printf ("Chapter 2\n");
	printf (LINE);

	return EXIT_SUCCESS;
}

void drawLine(void) {

// REPETITION STILL EXISTS IN THE PROGRAMS ABOVE (repetition of printf)
// How do we get rid of this repetition?

/*
	IMPROVED #2 chapters.c program (printing out Chapter #2)
*/

int main(int argc, char * argv[]) { // argc = arg count

	drawChapter (1); // Replacing repetition of the above example + calling the drawChapter void function below

	printf ("\n\n\n\n\n\n");

	drawChapter (2); // This is a TINY BIT of duplication leftover that we can fix!

	return EXIT_SUCCESS;
}

void drawChapter(int drawChapter) {
	printf (LINE);
	printf ("Chapter %d\n", chapterNumber);
	printf (LINE);
}

// REPETITION STILL EXISTS IN THE PROGRAMS ABOVE (repetition of printf)
// How do we get rid of this repetition?

/*
	BAGEL RECIPE / Abstraction / Good use of repetition

	Recipes are awesome because they use a lot of abstraction

	For example, one instruction would be to "Knead the dough for 10 minutes"
	- If we don't understand what "knead" means, we can just do a Google search which can describe what the action is
	- Technically, this is similar to a "Function Call"
	- You could describe the whole kneading process in the recipe, but that would be a waste of space.
	- An action, such as kneading the dough is used in many recipes, therefore its better if we just have
	"one function in one page" that describes how we do it, rather than repeating these instructions for kneading
	the dough in every single recipe.
	- Not only does this save space, but its also more efficient because if someone needs to change the instructions
	on how to knead dough, they would only need to change that ONE page, rather than changing everything.
*/

<----------INTRODUCTION TO LOOPS---------------->

/*
	IMPROVED #3 (LOOPS) chapters.c program
*/

int main(int argc, char * argv[]) { // argc = arg count

	int chapterNumber;
	chapterNumber = 0;

	int chapterCount = 11;

	while (chapterNumber < chapterCount) { // " while (HowManyTimes) { While some condition
		drawChapter (chapterNumber);
		printf ("\n\n\n\n\n\n");
		chapterNumber = chapterNumber + 1; // So an INFINITE LOOP doesn't occur and the WHILE condition is met
	}

	return EXIT_SUCCESS;
}

void drawChapter(int drawChapter) {
	printf (LINE);
	printf ("Chapter %d\n", chapterNumber);
	printf (LINE);
}

/*
	ADDITIONAL BAT PROGRAM
*/

int main(int argc, char * argv[]) { // argc = arg count

	int chapterNumber;
	chapterNumber = 0;

	int maxNumberOfBats = 11;

	while (batCount < maxNumberOfBats) { // " while (HowManyTimes) { While some condition
		singVerse (batCount);
		printf ("\n\n\n");
		batCount += 1; // "PLUS-EQUALS" is the same as "chapterNumber + 1"
	}
	
	return EXIT_SUCCESS;
}

void singVerse(int batCount) {
	printf ("%d bats sitting in my belfrey\n", batCount);
	printf ("1 bat flies in through the door\n");
	batCount++; // Increases value by one. Does NOT coincide with batCount += in the int main program as
				// it is just a copy the same thing outside / above.
	prinft ("that makes my %d bats sitting in my belfrey\n", batCount);
	printf ("but wait, there's more..."\n);
}













