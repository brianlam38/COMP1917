#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list-partition.h"

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
    printf ("\nTest 1: an empty list [] = [] \n");
    list sourceList = malloc (sizeof (struct _list));
    assert (sourceList !=NULL);
    sourceList->head = NULL;  

    printf ("before partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
    partition(sourceList);
    printf ("after..\n");
    printf("sourceList is: ");
    showList (sourceList);
    assert (sourceList->head == NULL);
	
    
    // create 10 nodes on the stack 
    node nodes[10];
 
    // test a list with one node in it
    printf ("\nTest 2: one node in list [42] = [42]\n");
    sourceList->head = &nodes[0];
    sourceList->head->value = 42;
    sourceList->head->next = NULL;  
    
    printf ("before partition..\n");
    printf("SourceList is: ");
    showList (sourceList);
    partition (sourceList);
    printf ("after..\n");
    printf("sourceList is: ");
    showList (sourceList);
  

    assert (sourceList->head == &nodes[0]);  
    assert (sourceList->head->value == 42);
    assert (sourceList->head->next == NULL); 
	
    
   
    // test a list with two nodes in it
    printf ("\nTest 3:  A list containing two nodes [73,21] = [21,73]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 73;
    nodes[1].value = 21;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[1]);  
    assert (sourceList->head->value == 21);
 
    assert (sourceList->head->next == &nodes[0]);  
    assert (sourceList->head->next->value == 73);
    assert (sourceList->head->next->next == NULL); 
    
   
    // test a list with two nodes in it
    printf ("\nTest 4:  A list containing two nodes [21,73] = [21,73]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 21;
    nodes[1].value = 73;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[0]);  
    assert (sourceList->head->value == 21);
 
    assert (sourceList->head->next == &nodes[1]);  
    assert (sourceList->head->next->value == 73);
    assert (sourceList->head->next->next == NULL); 


   
    printf ("\nTest 5:  A list containing three nodes [21,24,22] = [21,24,22]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 21;
    nodes[1].value = 24;
    nodes[2].value = 22;
    
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[0]);  
    assert (sourceList->head->value == 21);
 
    assert (sourceList->head->next == &nodes[1]);  
    assert (sourceList->head->next->value == 24);
    assert (sourceList->head->next->next == &nodes[2]);
    assert (sourceList->head->next->next->value == 22);
    assert (sourceList->head->next->next->next == NULL);

    printf ("\nTest 6:  A list containing three nodes [21,20,22] = [20,21,22]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 21;
    nodes[1].value = 20;
    nodes[2].value = 22;
    
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[1]);  
    assert (sourceList->head->value == 20);
 
    assert (sourceList->head->next == &nodes[0]);  
    assert (sourceList->head->next->value == 21);
    assert (sourceList->head->next->next == &nodes[2]);
    assert (sourceList->head->next->next->value == 22);
    assert (sourceList->head->next->next->next == NULL);

    printf ("\nTest 7:  A list containing three nodes [21,22,20] = [20,21,22]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 21;
    nodes[1].value = 22;
    nodes[2].value = 20;
    
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[2]);  
    assert (sourceList->head->value == 20);
 
    assert (sourceList->head->next == &nodes[0]);  
    assert (sourceList->head->next->value == 21);
    assert (sourceList->head->next->next == &nodes[1]);
    assert (sourceList->head->next->next->value == 22);
    assert (sourceList->head->next->next->next == NULL);


    printf ("\nTest 9:  A list with duplcate values [21,21,21] = [21,21,21]\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 21;
    nodes[1].value = 21;
    nodes[2].value = 21;
    
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before partition..\n");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("sourceList is: ");
    showList (sourceList);
   

    assert (sourceList->head == &nodes[0]);  
    assert (sourceList->head->value == 21);
 
    assert (sourceList->head->next == &nodes[1]);  
    assert (sourceList->head->next->value == 21);
    assert (sourceList->head->next->next == &nodes[2]);
    assert (sourceList->head->next->next->value == 21);
    assert (sourceList->head->next->next->next == NULL);
    




    // test a list with four nodes in it
    printf ("\nTest 10: a list containing four nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 45;
    nodes[1].value = 33;
    nodes[2].value = 12;
    nodes[3].value = 444;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = NULL;
    
    printf ("before partition..\n");
    printf("SourceList is: ");
    showList (sourceList);

    partition (sourceList);
    printf ("after partition..\n");
    printf("SourceList is: ");
    showList (sourceList);

    assert (sourceList->head == &nodes[1]);  
    assert (sourceList->head->value == 33);
    assert (sourceList->head->next == &nodes[2]);
    assert (sourceList->head->next->value == 12);
    assert (sourceList->head->next->next == &nodes[0]);
    assert (sourceList->head->next->next->value == 45);
    assert (sourceList->head->next->next->next == &nodes[3]);
    assert (sourceList->head->next->next->next->value == 444);  
    assert (sourceList->head->next->next->next->next == NULL);  

    
    // test a list with nine nodes in it
    printf ("\nTest 11: a list containing ten nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 33;
    nodes[1].value = 65;
    nodes[2].value = 32;
    nodes[3].value = 90;
    nodes[4].value = 1;
    nodes[5].value = 232;
    nodes[6].value = 21;
    nodes[7].value = 77;
    nodes[8].value = 2;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = &nodes[4]; 
    nodes[4].next  = &nodes[5];
    nodes[5].next  = &nodes[6]; 
    nodes[6].next  = &nodes[7];
    nodes[7].next  = &nodes[8];
    nodes[8].next  = NULL;
    
    printf ("before partition..\n");
    printf("SourceList is: ");
    showList (sourceList);
    partition (sourceList);
    printf ("after partition..\n");
    printf("SourceList is: ");
    showList (sourceList);

    assert (sourceList->head == &nodes[2]);  
    assert (sourceList->head->value == 32);
    assert (sourceList->head->next == &nodes[4]);
    assert (sourceList->head->next->value == 1);
    assert (sourceList->head->next->next == &nodes[6]);
    assert (sourceList->head->next->next->value == 21);
    assert (sourceList->head->next->next->next == &nodes[8]);
    assert (sourceList->head->next->next->next->value == 2);
    assert (sourceList->head->next->next->next->next == &nodes[0]);
    assert (sourceList->head->next->next->next->next->value == 33);
    assert (sourceList->head->next->next->next->next->next == &nodes[1]);
    assert (sourceList->head->next->next->next->next->next->value == 65);
    assert (sourceList->head->next->next->next->next->next->next == &nodes[3]);
    assert (sourceList->head->next->next->next->next->next->next->value == 90);
    assert (sourceList->head->next->next->next->next->next->next->next == &nodes[5]);
    assert (sourceList->head->next->next->next->next->next->next->next->value == 232);
    assert (sourceList->head->next->next->next->next->next->next->next->next == &nodes[7]);
    assert (sourceList->head->next->next->next->next->next->next->next->next->value == 77);
    assert (sourceList->head->next->next->next->next->next->next->next->next->next == NULL);

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
