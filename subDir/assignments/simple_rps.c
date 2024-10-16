#include <stdio.h>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

int main(void)
{
    int player1, player2;

    printf("Rock, Paper, Scissors Game!\n");
    printf("Enter 1 for Rock, 2 for Paper, 3 for Scissors.\n");

    printf("Player 1, advance your attack: ");
    scanf("%d", &player1);

    printf("Player 2, counter with: ");
    scanf("%d", &player2);

    if (player1 < ROCK || player1 > SCISSOR || player2 < ROCK || player2 > SCISSOR)
    {
        printf("Invalid input! Please enter 1, 2, or 3.\n");
    }
    else if (player1 == player2)
    {
        printf("It's a tie!\n");
    }
    else if ((player1 == ROCK && player2 == SCISSOR) ||
             (player1 == PAPER && player2 == ROCK) ||
             (player1 == SCISSOR && player2 == PAPER))
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

    return 0;
}
