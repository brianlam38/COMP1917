{

p1 = p2;							 // assign p1 the memory address value of p2 / p1 stores address of b
printf ("value of p1 is %u \n", p1); // value of p1 = memory address p2 (after assigning p1 = p2)
printf ("value of b is %d \n", *p1); // value of b = 10, using *p1 (p1 now has address of p2, storing value of b)

}