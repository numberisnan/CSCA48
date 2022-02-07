// Scratch space for our class on Feb. 3
//

#include<stdio.h>
#include<stdlib.h>

void fillTheArray(int* array)
{
   // Store some values in the array
   *array=25;
   *(array+1)=35;
   *(array+2)=45;
   *(array+3)=55;
   *(array+4)=65;
   
   printf("The array contains: ");
   for (int i=0; i<5; i++)
   {
       printf("%d, ",*(array+i)); 
   }
   printf("\n");            // Up to here!
}

int main()
{
    int some_array[5];
    int *p;
    
    p=&some_array[0];

    fillTheArray(some_array);    

    return 0;
}