// Scratch space for our class on Feb. 3
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 2

void makeItLoud(char *src, char *dst)
{
   // Goes over the source string, and inserts an exclamation '!' sign after each word,
   // src="Hello world"
   // dst="Hello! world!"
    
   // Do this with pointers :)
   char* start = src;
   char* dststart = dst;
   while (*src != '\0' && src-start < MAX_STR_LEN-1 && dst-dststart < MAX_STR_LEN-1) {
       if (*src == ' ' && (src == start || *(src-1) != ' ')) { //If this char is space and last char was not space
           *dst = '!';
           *(dst+1) = ' ';
           dst+=2;
       } else {
           *dst = *src;
           dst++;
       }
       src++;
   }
   *dst = '!';
   *(dst+1) = '\0';
    
}

int main()
{
    char my_string[MAX_STR_LEN]="I am a string, \n\n\n kind of stringy\n\n";
    char destination[MAX_STR_LEN]="";

    
    printf("The source string is %s\n",my_string);
    makeItLoud(my_string,&destination[0]);
    printf("The result string is %s\n",destination);     
    
    return 0;
}

// Functions in the string library (for instance, strlen());

