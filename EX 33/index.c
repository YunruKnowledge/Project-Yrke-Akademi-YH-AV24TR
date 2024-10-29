#include <stdint.h>
#include <stdio.h>

#define T(n) ((n) == 64 ? UINT64_MAX : ((1ULL << (n)) - 1))
#define SECONDS_iN_A_YEAR 31556926
#define MAX_NUM_OF_PIECES 64

int main(void) {
    uint64_t pieces;

    printf("Enter how many pieces you want to have on your 3-stick Hanoi tower: ");
    scanf("%lu", &pieces);

    if (pieces > MAX_NUM_OF_PIECES) {
        printf("The number of pieces cannot exceed 64.\n");
        return 1;
    }

    uint64_t moves = T(pieces);
    printf("It will minimum take [%lu] moves\n", moves);
    printf("It will take [%lu] years to complete! \n", (moves/SECONDS_iN_A_YEAR));
    
    return 0;
}
