#include <stdio.h>
#include "magicSquare.h"

int main(void) {
    int square1[SIZE][SIZE] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int square2[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Testing square1:\n");
    printSquare(square1);
    if(isLoShuMagicSquare(square1))
        printf("square1 is a Lo Shu Magic Square!\n\n");
    else
        printf("square1 is NOT a Lo Shu Magic Square.\n\n");

    printf("Testing square2:\n");
    printSquare(square2);
    if(isLoShuMagicSquare(square2))
        printf("square2 is a Lo Shu Magic Square!\n");
    else
        printf("square2 is NOT a Lo Shu Magic Square.\n");

    return 0;
}