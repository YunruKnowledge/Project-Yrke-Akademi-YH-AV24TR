#include <stdio.h>

enum rps
{
    rock = 1,
    paper,
    scissor
};
typedef struct player newPlayer;
struct player
{
    unsigned int input;
    unsigned int randomsght;
};
newPlayer player_1 = {0};
newPlayer player_2 = {0};

int runComparisionLogic(unsigned int value_1, unsigned int value_2)
{
    if (value_1 == rock && value_2 == scissor)
    {
        printf("Player 1 wins, played rock against scissors.\n");
    }
    else if (value_1 == paper && value_2 == rock)
    {
        printf("Player 1 wins, played paper against rock.\n");
    }
    else if (value_1 == scissor && value_2 == paper)
    {
        printf("Player 1 wins, played scissor against paper.\n");
    }
    else if (value_2 == rock && value_1 == scissor)
    {
        printf("Player 2 wins, played rock against scissors.\n");
    }
    else if (value_2 == paper && value_1 == rock)
    {
        printf("Player 2 wins, played paper against rock.\n");
    }
    else if (value_2 == scissor && value_1 == paper)
    {
        printf("Player 2 wins, played scissor against paper.\n");
    }
    else
    {
        printf("Draw, [%u] [%u]\n", value_1, value_2);
    }
    return 0;
}

int main(void)
{
    printf("Player 1 - Select your attack.\n");
    printf("1. Rock | 2. Paper | 3. Scissor\n");
    while (!player_1.input || player_1.input > 3)
    {
        if (player_1.input > 3)
        {
            printf("\nInvalid input - [%u]\n", player_1.input);
            printf("1. Rock | 2. Paper | 3. Scissor\n");
            scanf("%u", &player_1.input);
        }
        else
        {
            scanf("%u", &player_1.input);
        }
    }

    printf("Player 2 - Select your attack.\n");
    printf("1. Rock | 2. Paper | 3. Scissor\n");
    while (!player_2.input || player_2.input > 3)
    {
        if (player_2.input > 3)
        {
            printf("\nInvalid input - [%u]\n", player_2.input);
            printf("1. Rock | 2. Paper | 3. Scissor\n");
            scanf("%u", &player_2.input);
        }
        else
        {
            scanf("%u", &player_2.input);
        }
    }

    printf("Player 1 inputed: %i\n", player_1.input);
    printf("Player 2 inputed: %i\n", player_2.input);
    printf("\n\n\n\n");

    runComparisionLogic(player_1.input, player_2.input);

    return 0;
}