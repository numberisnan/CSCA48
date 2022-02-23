/////////////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// BONUS exercise - fun with pointers (Take 2)
//
// (c) 2022 F. Estrada
/////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#define MAX_STR_LEN 2048

int isVow(char c) {
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}

void splitVowels(char *strA, char *strB)
{
 // This function uses pointers (YOU MUST NOT USE ARRAY
 // NOTATION) to move all the vowels from string_A to
 // string_B leaving in string_A only the remaining text.
 // An example of this is shown in the exercise description
 // on Quercus.
 // **** DO NOT include string.h ****

 // TO DO:
 // Complete this function!
 // YOU ARE NOT ALLOWED TO USE FUNCTIONS IN THE STRING LIBRARY

 char* cons = (char*)calloc(MAX_STR_LEN, sizeof(char));
 char* consstart = cons;
 for (char* c = strA; *c != '\0'; c++) {
    if (isVow(*c)) {
        *strB = *c;
        strB++;
    } else {
        *cons = *c;
        cons++;
    }
 }
 *cons = '\0';
 *strB = '\0';

 //Copy cons to strA
 int i;
 for (i = 0; *(consstart+i) != '\0'; i++) {
    *(strA+i) = *(consstart+i);
 }
 *(strA+i) = '\0';
}


// Do not change anything in main() please
#ifndef __TESTING
int main()
{
 // The quote below if by Henry David Thoreau
 char string1[MAX_STR_LEN];
 fgets(string1, MAX_STR_LEN, stdin);
 char string1_vowels[MAX_STR_LEN];
 char string2[MAX_STR_LEN];
 fgets(string2, MAX_STR_LEN, stdin);
 char string2_vowels[MAX_STR_LEN];

 // DO NOT CHANGE ANYTHING in main()

 printf("%s\n\n",string1);
 splitVowels(&string1[0],&string1_vowels[0]);
 printf("%s\n\n",string1);
 printf("%s\n\n",string1_vowels);
 printf("%s\n\n",string2);
 splitVowels(&string2[0],&string2_vowels[0]);
 printf("%s\n\n",string2);
 printf("%s\n\n",string2_vowels);

 return 0;
}
#endif
