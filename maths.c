#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define pi M_PI // from math.h
#define gw 21

int main(){
    float inc = 0.25;
    char out[gw];

    for (float i = 0; i <= 2*pi; i += inc){
        float value = sin(i);
        for (int j = 0; j < gw; j++) {
            out[j] = ' ';
        }
        out[10] = '|';
        out[(int)roundf(value*10)+10] = '*';
        for (int j = 0; j < gw; j++) {
            printf("%c", out[j]);
        }
        printf("\n");
    }

    /*
    TASKS:
    1) Create a for loop that prints the values of sin(x), wfor values of x from 0 to 2pi. Increment based on a variable value. 
    2) Print this with 1 number before the decimal point, and 3 after. Also, print these numbers on different lines.
    3) Print only the values whose absolute value are between .5 and .75, both positive and negative.
    4) Use break to exit the for loop once you have printed all positive values for sin(x).

    HANDIN:
    Now take what you've worked on, and write a program that prints out a graph of the function sin(x) 
    for values of x from 0 to 2π in increments of 0.25. Go to https://csca48.github.io/w21tutorials/W2/ for a picture and extra information.
    You only need to submit the .c file, make sure to name it properly. 
    
    Use the "ask for help" feature to bring me to your room. 
    Don't stress, we are only marking participation. 
    */

    return 0;
}