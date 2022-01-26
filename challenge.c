#include<stdio.h>

float blipbleep(int c, int l, int r){
    // Draw the memory model at this point in time (starting from main, at this exact point before the return statement below is called)
    return c + l + r;
}


float blipblop (char q, int c, int l){
    int r = c + l;

    char e = 'm';

    return blipbleep(c, l, r);
}



float blipbloop (char c, int m){
    float q = m/3;

    char l = c;

    return blipblop(l,5, 2);
}

int main(){
    float q;
    q = blipbloop('a', 3);
    printf("blip %.3f", q);
}