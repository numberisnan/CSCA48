/* Description: chocc
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

int arr[90];

int main() {
    for (int i = 0; i < 90; i++) {
        if (!(i%3)) {
            arr[i] = 2;
        } else {
            arr[i] = 1;
        }
    }
    for (int i = 0; i < 90; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}