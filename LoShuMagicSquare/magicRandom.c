#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "magicSquare.h"

int main(void) {
    int square[3][3];
    int tries = 0;

    srand((unsigned)time(NULL));

    do {
        int numbers[9] = {1,2,3,4,5,6,7,8,9};

        // Shuffle numbers
        for(int i=8; i>0; i--){
            int j = rand() % (i+1);
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
        }

        // Fill square
        int k = 0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                square[i][j] = numbers[k++];

        tries++;
    } while (!isLoShu(square));

    // Print result
    printf("Found a Lo Shu Magic Square after %d tries:\n", tries);
    for(int i=0;i<3;i++){
        printf("[%d %d %d]\n", square[i][0], square[i][1], square[i][2]);
    }

    return 0;
}