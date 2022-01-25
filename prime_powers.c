/* Description: Assignment 2
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

int p[101];

float power(float x, int p) {
    float res = 1;
    for (int i = 0; i < p; i++) {
        res *= x;
    }
    return res;
}

int main() {
    float a = 1.4142;

    //Compute primes
    for (int i = 2; i <= 100; i++) {
        p[i] = 1;
        for (int j = 2; j <= i; j++) {
            if (p[j] && i != j && i%j == 0) {
                p[i] = 0;
            }
        }
    }

    for (int i = 2; i <= 100; i++) {
        if (p[i]) {
            printf("p=%d, %f^%d = %f\n", i, a, i, power(a, i));
        }
    }

    
    return 0;
}