/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

void replace_i_with_j(char stringy[5]) {
    for (int i = 0; i<5; i++) {
        if (stringy[i] == 'i') stringy[i] = 'j';
    }
}

int main() {
    char my_string[5] = "hi!";

    replace_i_with_j(my_string);

    printf("The rresult of calling the replace_i_with_j is %s\n", my_string);
    return 0;
}