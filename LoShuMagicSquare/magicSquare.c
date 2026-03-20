#include <stdio.h>
#include "magicSquare.h"

bool isLoShuMagicSquare(int square[SIZE][SIZE]) {
    int magicSum = 15; // sum of rows, columns, and diagonals for 3x3 Lo Shu
    int sum;

    // Check rows
    for(int i = 0; i < SIZE; i++){
        sum = 0;
        for(int j = 0; j < SIZE; j++)
            sum += square[i][j];
        if(sum != magicSum) return false;
    }

    // Check columns
    for(int j = 0; j < SIZE; j++){
        sum = 0;
        for(int i = 0; i < SIZE; i++)
            sum += square[i][j];
        if(sum != magicSum) return false;
    }

    // Check diagonals
    sum = square[0][0] + square[1][1] + square[2][2];
    if(sum != magicSum) return false;

    sum = square[0][2] + square[1][1] + square[2][0];
    if(sum != magicSum) return false;

    return true;
}

void printSquare(int square[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        printf("[");
        for(int j = 0; j < SIZE; j++){
            printf("%d", square[i][j]);
            if(j < SIZE - 1) printf(" ");
        }
        printf("]\n");
    }
}