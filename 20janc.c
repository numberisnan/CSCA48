/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char str[100] = "apples";
    char coded[100];

    for (int i = 0; str[i] != '\0'; i++) {
        coded[i] = str[i] + 3; //It will loop back itself
        if (coded[i] == '\0') {
            //Nice try
            coded[i]++;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", coded[i]);
    }
    
    return 0;
}