///////////////////////////////////////////////////////
// CSC A48 - Winter 2022 Exercise 3 starter
//
// (c) F. Estrada, Jan 2022
//
// Read carefully the comments in this starter file and
// complete the required sections
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
// DO NOT INCLUDE ANY OTHER LIBRARIES FOR THIS EXERCISE
#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// GLOBAL data!
// In practice, we would rarely use global variables in our
// program except for very specialized cases. However, we
// haven't yet learned how to move arrays from one function
// to another (that's next week!) - so for this week, we will
// use a couple global arrays to do our work.
//
// Remember, global variables (as seen in Unit 2) live outside
// any of the functions in our program in terms of memory 
// model, and can be accessed/changed by any function in our
// code.
int the_primes[100];
int the_integers[100];
int the_factors[100];
//
// END of global data declarations
////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// Functions to be completed, read the description carefully
/////////////////////////////////////////////////////////

void factorize(int idx)
{
 ////////////////////////////////////////////////////////
 // This function receives the index of an entry in
 // the array of integers 'the_integers'. It takes
 // whatever entry is in the array, and produces a list
 // of prime factors which are then stored in the
 // array called the_factors[].
 //
 // Example, suppose idx=1
 //          the_integers[1]=50  // This is just an example,
 //                              // it could be ANY number
 //
 // The prime factors of 50 are:
 //  2, 5, 5  (50 = 2*5*5, where 2, and 5 are prime numbers)
 //
 // So this function would store these prime factors in order
 // in the 'the_factors' array:
 //
 // the_factors[0]=2
 // the_factors[1]=5
 // the_factors[2]=5
 // the_factors[3]=-1
 //
 // Notice that the function stored a '-1' at the end of the
 // list of prime factors. This is so we know we reached the
 // end of the list of prime factors because different numbers
 // will fewer or more prime factors.
 //
 // If you're still unsure what's going on here, it may be a
 // good idea to spend a bit of time reviewing primes and
 // prime factors online.
 ///////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////////////////////////
 
 int n = the_integers[idx];
 int curr = n;
 int i = 2;
 int arrayindex = 0;
 int primeflag;
 for (;i <= n && curr > 1; i++) {
   primeflag = 0;
   for (int j = 0; j < 100; j++) { //See if i is a prime in our list
     if (i == the_primes[j]) {
       primeflag = 1;
     }
   }
   if (primeflag && curr%i == 0) {
     the_factors[arrayindex] = i;
     curr /= i;
     arrayindex++;
     i--; // So it can try to devide by i again
   }
 }
 the_factors[arrayindex] = -1;
}

int is_prime(int x)
{
 //////////////////////////////////////////////////////////
 // This function tests x and returns 1 if x is prime, and
 // 0 if x is not prime.
 //
 // You're NOT allowed to use functions from the math
 // library here.
 //
 // x can be any arbitrary integer number.
 /////////////////////////////////////////////////////////

 /////////////////////////////////////////////////////////
 // TO DO: Complete this function
 /////////////////////////////////////////////////////////
 if (x < 2) {
   return 0;
 }
 for (int i = 2; i < x; i++) {
   if (!(x%i)) {
     return 0;
   }
 }

 return 1;
}


void primitive(void)
{
 ///////////////////////////////////////////////////////////
 //
 // This function finds and stores the first 100 prime numbers
 // in the 'the_primes' array. It must make use of the
 // is_prime() function.
 //
 // 1 is NOT a prime (despite arguments to the contrary)
 //
 // There are no input arguments, and no return value.
 //
 ////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////////////////////////

 int primes = 0;
 int i = 2;
 while (primes < 100) {
   if (is_prime(i)) {
     the_primes[primes] = i;
     primes++;
   }
   i++;
 }

}

// You DO NOT need to change any code below this line

#ifndef __TESTING	// <-- DO NOT REMOVE THESE COMPILER DIRECTIVES
			// they are required for our auto-testing
int main()
{
 // You do not need to change ANYTHING in main(). All your work
 // happens in the functions above.
 for (int i=0; i<100; i++)
 {
  // Just initializing our global arrays so there's no junk in them
  the_factors[i]=0;
  the_primes[i]=0;
 }


 // Fill in some integer values in the 'the_integers' array
 // since we go over the entire array and put values in it, 
 // we didn't need to intialize it in the for loop above!
 for (int i=0; i<100; i++)
  the_integers[i]=i+2;

 // Call your function to generate the list of the first 100 primes
 primitive();
 // Print out your list of prime numbers
 printf("The first 100 primes are: ");
 for (int i=0; i<100; i++)
  printf("%d, ",the_primes[i]);
 printf("\n");

 // Now factorize each of the numbers in 'the_integers' and print out
 // the list of prime factors
 printf("**** Printing out factorizations now:\n");
 for (int i=0; i<100; i++)
 {
  factorize(i);
  printf("x=%d, factors: ",the_integers[i]);
  for (int j=0; j<100; j++)
  {
    if (the_factors[j]==-1) break;	// A good use of break!
    printf("%d, ",the_factors[j]);
  }
  printf("\n");
 }

 return 0;
} 
#endif			// <-- DO NOT REMOVE THESE COMPILER DIRECTIVES
			// they are required for our auto-testing
