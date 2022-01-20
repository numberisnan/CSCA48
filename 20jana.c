/* Description: letters something something add
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    for (char c = 'G'; c <= 'z'; c+=2) {
        printf("%c", c);
        if (c == 'K') {
            c = 'R';
        } else if (c == 'Z') {
            c = 'e';
        } else if (c == 'k') {
            c = 'r';
        }
    }

    return 0;
}