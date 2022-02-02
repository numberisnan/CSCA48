// TODO: Complete StringBeans and call it in main
// Draw the memory model as stringbeans returns, then join room 4 to show me your memory model!
// At the end of the tutorial, simply rename this file to Week4_Tutorial_studentNo.c and submit it
#include<stdio.h>

void StringBeans(char a[100], char b[100], int n[10]) {
    int swap;
    char temp;
    for (int i = 0; i < 10; i++) {
        swap = n[i];
        temp = a[swap];
        a[swap] = b[swap];
        b[swap] = temp;
    }
}

int main(){
    char OneStr[100] = "This is String #1";
    char TwoStr[100] = "I suspect this is String #2";
    int replArray[10] = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};

    StringBeans(OneStr, TwoStr, replArray);

    printf("%s", OneStr);

    /*
    StringBeans(str, str, int[]) takes two strings and an int array (wink wink look above)
    The function goes through the int array and swaps the items in the strings at those indices
    For example, if the first value in the array is 3, swap the characters in the two strings that are at index 3

    Figure out how this function would work (what will it return, if anything?) and implement it!
    */
}