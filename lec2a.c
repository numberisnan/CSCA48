/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

float e(int a, int b, float z) {
    printf("%d %d %f",a,b,z);
    return a + b + z; //Converts a and b to float
}

int main() {
    int a=5,b=7;
    float z = 3.1416;

    float res = e(a,b,z);
    printf("\n%f", res);
    return 0;
}