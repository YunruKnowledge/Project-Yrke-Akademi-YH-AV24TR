#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

enum gamemode
{
    pvp,
    pve, // player vs ai
    ai   // ai vs ai
};

const char *moves[] = {"", "rock", "paper", "scissor"};
enum rps
{
    rock = 1,
    paper,
    scissor
};

typedef struct
{
    unsigned int input;
    char name[32];
    // unsigned int futurestuff;
} newPlayer;

newPlayer player_1 = {0};
newPlayer player_2 = {0};

void getPlayerInput(newPlayer *player)
{
    printf("\n\n"); // space out
    printf("%s - Select your attack.\n", player->name);
    printf("%i. Rock | %i. Paper | %i. Scissor\n", rock, paper, scissor);
    printf("User: ");

    while (1)
    {
        scanf("%u", &(player->input));
        if (player->input >= rock && player->input <= scissor)
        {
            break; // <---------------------------------------
        }
        else
        {
            printf("\n\n"); // space out
            printf("\nInvalid input of [%u]\n", player->input);
            printf("%i. Rock | %i. Paper | %i. Scissor\n\n", rock, paper, scissor);
            printf("User: ");
        };
    }
}

void getRandomInput(newPlayer *autoPlayer)
{
    autoPlayer->input = rand() % scissor + 1;
}

void runPrintLogic(newPlayer *play1, newPlayer *play2)
{
    if (play1->input == play2->input)
    {
        printf("It's a draw! Both played the same move.\n");
        return;
    }
    else if ((play1->input == rock && play2->input == scissor) ||
             (play1->input == paper && play2->input == rock) ||
             (play1->input == scissor && play2->input == paper))
    {
        printf("%s wins, played ", play1->name);
        printf("%s against %s.\n", moves[play1->input], moves[play2->input]);
    }
    else
    {
        printf("%s wins, played ", play2->name);
        printf("%s against %s.\n", moves[play2->input], moves[play1->input]);
    }
}

int main(void)
{
    srand(time(NULL));
    unsigned int currentGamemode;
    printf("Select game mode:\n");
    printf("%i. Player vs Player\n", pvp);
    printf("%i. Player vs AI\n", pve);
    printf("%i. AI vs AI\n", ai);
    printf("Enter mode: ");
    scanf("%u", &currentGamemode);

    switch (currentGamemode)
    {
    case pvp:
        strcpy(player_1.name, "Player 1");
        strcpy(player_2.name, "Player 2");
        getPlayerInput(&player_1);
        getPlayerInput(&player_2);
        break;
    case pve:
        strcpy(player_1.name, "Player 1");
        strcpy(player_2.name, "[AI] Player 2");
        getPlayerInput(&player_1);
        getRandomInput(&player_2);
        break;
    case ai:
        strcpy(player_1.name, "[AI] Magnus");
        strcpy(player_2.name, "[AI] Hikaru");
        getRandomInput(&player_1);
        getRandomInput(&player_2);
        break;
    default:
        printf("Invalid mode selected. Exiting...\n");

        return 1; // <-------------------------------
    }

    printf("\n\n"); // space out
    printf("Player 1 inputed: %i\n", player_1.input);
    printf("Player 2 inputed: %i\n", player_2.input);
    printf("\n");

    runPrintLogic(&player_1, &player_2);

    return 0;
}