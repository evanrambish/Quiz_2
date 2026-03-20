#include "magicSquare.h"
#include <stdio.h>
#include <stdlib.h>

int isLoShu(int square[3][3]) {
    int magicSum = 15; // sum for 3x3 Lo Shu
    // Check rows
    for(int i=0;i<3;i++){
        int rowSum = 0;
        for(int j=0;j<3;j++)
            rowSum += square[i][j];
        if(rowSum != magicSum) return 0;
    }
    // Check columns
    for(int j=0;j<3;j++){
        int colSum = 0;
        for(int i=0;i<3;i++)
            colSum += square[i][j];
        if(colSum != magicSum) return 0;
    }
    // Check diagonals
    if(square[0][0]+square[1][1]+square[2][2] != magicSum) return 0;
    if(square[0][2]+square[1][1]+square[2][0] != magicSum) return 0;

    return 1;
}

void printSquare(int square[3][3]){
    for(int i=0;i<3;i++){
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }
}

void fillRandomSquare(int square[3][3]){
    int used[10] = {0}; // index 1-9
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int n;
            do { n = rand()%9 + 1; } while(used[n]);
            used[n] = 1;
            square[i][j] = n;
        }
    }
}