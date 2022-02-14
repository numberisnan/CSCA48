////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
int rowsum(int sq[6][6], int row) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += sq[row][i];
    }

    return sum;
}

int colsum(int sq[6][6], int col) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += sq[i][col];
    }

    return sum;
}

int unknownsinrow(int sq[6][6], int row) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (sq[row][i] == -1) {
            sum++;
        }
    }
    return sum;
}

int unkownsincolumn(int sq[6][6], int col) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (sq[i][col] == -1) {
            sum++;
        }
    }
    return sum;
}

int solved(int square[6][6]) {
    for (int i = 0; i < 6; i++) {
        if (unknownsinrow(square, i)) {
            return 0;
        }
    }

    return 1;
}

int getvalue(int sq[6][6]) {
    for (int i = 0; i < 6; i++) {
        if (!unknownsinrow(sq, i)) {
            return rowsum(sq, i);
        } else if (!unkownsincolumn(sq, i)) {
            return colsum(sq, i);
        }
    } 
    return -1;
}

void solvesingleunknownrow(int sq[6][6], int row, int value) {
    // Find index of unknown
    int ind = -1;
    for (int i = 0; i < 6; i++) {
        if (sq[row][i] == -1) {
            ind = i;
        }
    }

    // Sum all the others
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += sq[row][i];
    }
    sum++; //Undo adding -1

    //Replace
    sq[row][ind] = value - sum;

}

void solvesingleunknowncol(int sq[6][6], int col, int value) {
    // Find index of unknown
    int ind = -1;
    for (int i = 0; i < 6; i++) {
        if (sq[i][col] == -1) {
            ind = i;
        }
    }

    // Sum all the others
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += sq[i][col];
    }
    sum++; //Undo adding -1

    //Replace
    sq[ind][col] = value - sum;

}

void solveMagicSquare(int square[6][6])
{
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////

int value = getvalue(square);
while (!solved(square)) {
    for (int i = 0; i < 6; i++) {
        if (unknownsinrow(square, i) == 1) {
            solvesingleunknownrow(square, i, value);
        }
        if (unkownsincolumn(square, i) == 1) {
            solvesingleunknowncol(square, i, value);
        } 
    }
}

}


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
