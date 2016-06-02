#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-ppexam.h"

//simple unit tests on the list
static void testList(void);
void showList (list l);

int main (int argc, char * argv[]){

	testList();
	printf("All tests passed ! You are awesome\n");
	return EXIT_SUCCESS;
}

void testList (void){

	// test a list with no nodes in it
    printf ("test an empty list\n");
    list l = malloc (sizeof (*l));
    assert (l !=NULL);
    l->head = NULL;  

    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
	showList (l);

    assert (l->head == NULL);
	
	// create 10 nodes on the stack 
    node nodes[10];
 
    // test a list with one node in it
    printf ("\ntest a list containing one node\n");
    l->head = &nodes[0];
    l->head->value = 41;
    l->head->next = NULL;  
    
    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[0]);  
    assert (l->head->value == 41);
    assert (l->head->next == NULL); 

    // test a list with two nodes in it
    printf ("\ntest a list containing two nodes\n");
    l->head = &nodes[0];
    nodes[0].value = 3;
    nodes[1].value = 1;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = NULL;
    
    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[1]);  
    assert (l->head->value == 1);
    assert (l->head->next == &nodes[0]); 
    assert (l->head->next->value == 3); 
    assert (l->head->next->next == NULL); 

    // test a list with three nodes in it
    printf ("\ntest a list containing three nodes\n");
    l->head = &nodes[0];
    nodes[0].value = 39;
    nodes[1].value = 6;
    nodes[2].value = 11;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[1]);  
    assert (l->head->value == 6);
    assert (l->head->next == &nodes[0]); 
    assert (l->head->next->value == 39); 
    assert (l->head->next->next == &nodes[2]); 
    assert (l->head->next->next->value == 11); 
    assert (l->head->next->next->next == NULL); 

    // test a list with four nodes in it
    printf ("\ntest a list containing four nodes\n");
    l->head = &nodes[0];
    nodes[0].value = 45;
    nodes[1].value = 33;
    nodes[2].value = 12;
    nodes[3].value = 444;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = NULL;
    
    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[1]);  
    assert (l->head->value == 33);
    assert (l->head->next == &nodes[0]); 
    assert (l->head->next->value == 45); 
    assert (l->head->next->next == &nodes[3]); 
    assert (l->head->next->next->value == 444); 
    assert (l->head->next->next->next == &nodes[2]);
    assert (l->head->next->next->next->value == 12); 


    // test a list with eight nodes in it
    printf ("\ntest a list containing eight nodes\n");
    l->head = &nodes[0];
    nodes[0].value = 0;
    nodes[1].value = 5;
    nodes[2].value = 32;
    nodes[3].value = 4;
    nodes[4].value = 4;
    nodes[5].value = 22;
    nodes[6].value = 676;
    nodes[7].value = 22;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = &nodes[4]; 
    nodes[4].next  = &nodes[5];
    nodes[5].next  = &nodes[6]; 
    nodes[6].next  = &nodes[7];
    nodes[7].next  = NULL;

    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[1]);  
    assert (l->head->value == 5);
    assert (l->head->next == &nodes[0]); 
    assert (l->head->next->value == 0); 
    assert (l->head->next->next == &nodes[3]); 
    assert (l->head->next->next->value == 4); 
    assert (l->head->next->next->next == &nodes[2]);
    assert (l->head->next->next->next->value == 32); 
    assert (l->head->next->next->next->next == &nodes[5]);
    assert (l->head->next->next->next->next->value == 22);  
    assert (l->head->next->next->next->next->next == &nodes[4]);
    assert (l->head->next->next->next->next->next->value == 4);
    assert (l->head->next->next->next->next->next->next == &nodes[7]);
    assert (l->head->next->next->next->next->next->next->value == 22);
    assert (l->head->next->next->next->next->next->next->next == &nodes[6]);
    assert (l->head->next->next->next->next->next->next->next->value == 676);
    assert (l->head->next->next->next->next->next->next->next->next == NULL);

    // test a list with nine nodes in it
    printf ("\ntest a list containing nine nodes\n");
    l->head = &nodes[0];
    nodes[0].value = 3;
    nodes[1].value = 65;
    nodes[2].value = 72;
    nodes[3].value = 3;
    nodes[4].value = 0;
    nodes[5].value = 232;
    nodes[6].value = 21;
    nodes[7].value = 7;
    nodes[8].value = 99;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = &nodes[4]; 
    nodes[4].next  = &nodes[5];
    nodes[5].next  = &nodes[6]; 
    nodes[6].next  = &nodes[7];
    nodes[7].next  = &nodes[8];
    nodes[8].next  = NULL;

    printf ("before pairwise swap..\n");
    printf("l is: ");
    showList (l);
    pairwiseSwap (l);
    printf ("after pairwise swap..\n");
    printf("l is: ");
    showList (l);

    assert (l->head == &nodes[1]);  
    assert (l->head->value == 65);
    assert (l->head->next == &nodes[0]); 
    assert (l->head->next->value == 3); 
    assert (l->head->next->next == &nodes[3]); 
    assert (l->head->next->next->value == 3); 
    assert (l->head->next->next->next == &nodes[2]);
    assert (l->head->next->next->next->value == 72); 
    assert (l->head->next->next->next->next == &nodes[5]);
    assert (l->head->next->next->next->next->value == 232);  
    assert (l->head->next->next->next->next->next == &nodes[4]);
    assert (l->head->next->next->next->next->next->value == 0);
    assert (l->head->next->next->next->next->next->next == &nodes[7]);
    assert (l->head->next->next->next->next->next->next->value == 7);
    assert (l->head->next->next->next->next->next->next->next == &nodes[6]);
    assert (l->head->next->next->next->next->next->next->next->value == 21);
    assert (l->head->next->next->next->next->next->next->next->next == &nodes[8]);
    assert (l->head->next->next->next->next->next->next->next->next->value == 99);
    assert (l->head->next->next->next->next->next->next->next->next->next == NULL);

}

void showList (list l) {
 
    assert (l !=NULL);
 
    // start at the first node
    link current = l->head;
    while (current != NULL) {
        printf ("[%d] -> ", current->value);
        current = current->next;
    }
    printf ("X\n");
}
