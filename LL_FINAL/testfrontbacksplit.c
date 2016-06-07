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
    list sourceList = malloc (sizeof (*sourceList));
    assert (sourceList !=NULL);
    sourceList->head = NULL;  

    list frontList = malloc (sizeof (*frontList));
    assert (frontList !=NULL);
    frontList->head = NULL;  

    list backList = malloc (sizeof (*backList));
    assert (backList !=NULL);
    backList->head = NULL;  

    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == NULL); 
    assert (backList->head == NULL); 
    assert (sourceList->head == NULL);
    
    // create 10 nodes on the stack 
    node nodes[10];
 
    // test a list with one node in it
    printf ("\ntest a list containing one node\n");
    sourceList->head = &nodes[0];
    sourceList->head->value = 42;
    sourceList->head->next = NULL;  
    
    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 42);
    assert (frontList->head->next == NULL); 
    
    assert (backList->head == NULL); 
    assert (sourceList->head == NULL);


    // test a list with two nodes in it
    printf ("\ntest a list containing two nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 73;
    nodes[1].value = 21;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = NULL;
    
    printf ("before split..\n");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 73);
    assert (frontList->head->next == NULL); 
    
    assert (backList->head == &nodes[1]);  
    assert (backList->head->value == 21);
    assert (backList->head->next == NULL); 

    assert (sourceList->head == NULL);

    // test a list with three nodes in it
    printf ("\ntest a list containing three nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 1;
    nodes[1].value = 11;
    nodes[2].value = 101;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = NULL;
    
    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 1);
    assert (frontList->head->next == &nodes[1]);
    assert (frontList->head->next->value == 11);
    assert (frontList->head->next->next == NULL); 
    
    assert (backList->head == &nodes[2]);  
    assert (backList->head->value == 101);
    assert (backList->head->next == NULL); 

    assert (sourceList->head == NULL);

    // test a list with four nodes in it
    printf ("\ntest a list containing four nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 45;
    nodes[1].value = 33;
    nodes[2].value = 12;
    nodes[3].value = 444;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = NULL;
    
    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 45);
    assert (frontList->head->next == &nodes[1]);
    assert (frontList->head->next->value == 33);
    assert (frontList->head->next->next == NULL); 
    
    assert (backList->head == &nodes[2]);  
    assert (backList->head->value == 12);
    assert (backList->head->next == &nodes[3]);  
    assert (backList->head->next->value == 444);
    assert (backList->head->next->next == NULL); 

    assert (sourceList->head == NULL);

    // test a list with nine nodes in it
    printf ("\ntest a list containing nine nodes\n");
    sourceList->head = &nodes[0];
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
    
    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 3);
    assert (frontList->head->next == &nodes[1]);
    assert (frontList->head->next->value == 65);
    assert (frontList->head->next->next == &nodes[2]);
    assert (frontList->head->next->next->value == 72);
    assert (frontList->head->next->next->next == &nodes[3]);
    assert (frontList->head->next->next->next->value == 3);
    assert (frontList->head->next->next->next->next == &nodes[4]);
    assert (frontList->head->next->next->next->next->value == 0);
    assert (frontList->head->next->next->next->next->next == NULL);
    
    assert (backList->head == &nodes[5]);  
    assert (backList->head->value == 232);
    assert (backList->head->next == &nodes[6]);
    assert (backList->head->next->value == 21);
    assert (backList->head->next->next == &nodes[7]);
    assert (backList->head->next->next->value == 7);
    assert (backList->head->next->next->next == &nodes[8]);
    assert (backList->head->next->next->next->value == 99);
    assert (backList->head->next->next->next->next == NULL);

    assert (sourceList->head == NULL);

    // test a list with ten nodes in it
    printf ("\ntest a list containing ten nodes\n");
    sourceList->head = &nodes[0];
    nodes[0].value = 66;
    nodes[1].value = 808;
    nodes[2].value = 72;
    nodes[3].value = 2;
    nodes[4].value = 1;
    nodes[5].value = 2;
    nodes[6].value = 1;
    nodes[7].value = 66;
    nodes[8].value = 99999;
    nodes[9].value = 1003;
    nodes[0].next  = &nodes[1];
    nodes[1].next  = &nodes[2];
    nodes[2].next  = &nodes[3];
    nodes[3].next  = &nodes[4]; 
    nodes[4].next  = &nodes[5];
    nodes[5].next  = &nodes[6]; 
    nodes[6].next  = &nodes[7];
    nodes[7].next  = &nodes[8];
    nodes[8].next  = &nodes[9]; 
    nodes[9].next  = NULL;
    
    printf ("before split..\n");
    printf("SourceList is: ");
    showList (sourceList);
    frontBackSplit (sourceList, frontList, backList);
    printf ("after split..\n");
    printf("frontList is: ");
    showList (frontList);
    printf("backList is: ");
    showList (backList);
    printf("SourceList is: ");
    showList (sourceList);

    assert (frontList->head == &nodes[0]);  
    assert (frontList->head->value == 66);
    assert (frontList->head->next == &nodes[1]);
    assert (frontList->head->next->value == 808);
    assert (frontList->head->next->next == &nodes[2]);
    assert (frontList->head->next->next->value == 72);
    assert (frontList->head->next->next->next == &nodes[3]);
    assert (frontList->head->next->next->next->value == 2);
    assert (frontList->head->next->next->next->next == &nodes[4]);
    assert (frontList->head->next->next->next->next->value == 1);
    assert (frontList->head->next->next->next->next->next == NULL);
    
    assert (backList->head == &nodes[5]);  
    assert (backList->head->value == 2);
    assert (backList->head->next == &nodes[6]);
    assert (backList->head->next->value == 1);
    assert (backList->head->next->next == &nodes[7]);
    assert (backList->head->next->next->value == 66);
    assert (backList->head->next->next->next == &nodes[8]);
    assert (backList->head->next->next->next->value == 99999);
    assert (backList->head->next->next->next->next == &nodes[9]);
    assert (backList->head->next->next->next->next->value == 1003);
    assert (backList->head->next->next->next->next->next == NULL);
    
    assert (sourceList->head == NULL);

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