/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

void makeLouder(char* c) { // Add exclamation after every word
    char s[100] = {*c};
    int newlen = 1; //Lenght of new string
    for (int i = 1; *(c+i-1) != '\0'; i++) {
        if ((*(c+i) == ' ' || *(c+i) == '\0') && /* Check if previous letter is space */ *(c+i-1) != ' ') {
            s[newlen] = '!';
            s[newlen+1] = ' ';
            newlen+=2;
        } else {
            s[newlen] = *(c+i);
            newlen++;
        }
    }

    //Write new string into old string
    for (int i = 0; i < newlen; i++) {
        *(c+i) = s[i];
    }
    
}

int main() {
    char str[100];
    for (int i = 0; i < 100; i++) str[i] = 0;
    gets(str); //I used a test case runner that I created. I attatched the test case file
    makeLouder(str);
    printf("%s", str);
    
    return 0;
}