/*
	LECTURE 20 - FUNCTIONS & FRAMES
*/

// Freeze what I'm doing completely
// Go off and do something else
// Go back to where I was before
What information do I need to record in there (the FRAME), so that I can resume the lecture?
"I was about to write a function to encode a string"

Delegation
- Getting many people to solve one big job
- But how do you get many people to work together to solve one thing?

Flow of control (booking flight to Munich example)
- Having conversation with Richard
- Calls another function (Book Error Plane Function)
- Conversation continues while the function is operating

Functions give abstraction
- You won't have a jumbled function which deals with Booking Error Planes, having a conversation and
other things.
- Everyone just does one thing.

COMPUTER SCIENCE SAYINGS:
- "You do things once, and once only" (OAOO)
- "Don't Repeat Yourself" (DRY)

In computing when you have an interruption, you need to write down what you're doing
- You set up a FRAME and then you write down what you're doing
- You go do that other thing and then you come back and look at the FRAME and you continue

EACH FUNCTION SHOULD BE RESPONSIBLE FOR JUST ONE THING

GOOD THING ABOUT FUNCTIONS:
(1) Abstraction
- Giving good organisation
(2) Code Re-use
- Reduce repetition in program code
(3) Discrete
- Separate (self contained) and do a whole thing
- We want a "job" to be self-contained so that it can be done without taking away time from elsewhere

FUNCTIONS IN PRACTICE:
- Computer runs top down
- Computer reaches function and needs to run it (freeze what it is currently doing)
- Computer jumps to the other function and does all of its stuff
- When completed, computer will go back to what it was doing before (and needs to remember WHERE to go back)
--> A computer sets up something called a FRAME (area of memory where it writes down what it was up to)
--> The FRAME resets all the context.
--> The Compiler sets it all up / Microprocessor runs it / C abstracts all of it.

FRAMES & HACKING:
- Stack OverFlow Attack:
--> Important OS program is running
--> Then it runs a user program (with minimal power)
--> While it runs your program, you fiddle around with the FRAME and you make it jump back to somewhere else
	e.g. a super user creation function, that lets you create a super user etc.




