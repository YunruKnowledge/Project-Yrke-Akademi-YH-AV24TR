#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

#define MIN_NUM 0
#define MAX_NUM 99

#define MAX_AMOUNT_OF_TRYS 10

int getRandomNumber(int min, int max);

int main(void)
{
    int guessNumber = getRandomNumber(MIN_NUM, MAX_NUM);
    int userGuess;
    int trys = 0;

    cout << "******************************************" << endl;
    cout << "************** Game Started **************" << endl;
    cout << "******************************************" << endl;

    do
    {
        cout << trys << ") Guess a number [" << MIN_NUM << ", " << MAX_NUM << "]: ";
        cin >> userGuess;

        if (cin)
        {
            if (trys != MAX_AMOUNT_OF_TRYS)
            {
                if (userGuess > guessNumber)
                {
                    cout << "Sorry, too big. Try again!" << endl;
                    trys++;
                }
                else if (userGuess < guessNumber)
                {
                    cout << "Sorry, too small. Try again!" << endl;
                    trys++;
                }
                else if (userGuess == guessNumber)
                {
                    char newGame;
                    cout << "Well done! You guessed the secret." << endl;
                    cout << "Do you want to play a new game? (y/n): " << endl;

                    cin >> newGame;

                    do
                    {
                        if (tolower(newGame) == 'y')
                        {
                            guessNumber = getRandomNumber(MIN_NUM, MAX_NUM);
                            trys = 0;
                            break;
                        }
                        else if (tolower(newGame) == 'n')
                        {
                            exit(0);
                        }
                        else
                        {
                            cout << "Wrong Input! Input must be ether 'y' or 'n': ";
                            cin >> newGame;
                        }
                    } while (1);
                }
            }
            else
            {
                char newGame;
                cout << "No more trys!" << endl;
                cout << "Do you want to play a new game? (y/n): " << endl;

                cin >> newGame;

                do
                {
                    if (tolower(newGame) == 'y')
                    {
                        guessNumber = getRandomNumber(MIN_NUM, MAX_NUM);
                        trys = 0;
                        break;
                    }
                    else if (tolower(newGame) == 'n')
                    {
                        exit(0);
                    }
                    else
                    {
                        cout << "Wrong Input! Input must be ether 'y' or 'n': ";
                        cin >> newGame;
                    }
                } while (1);
            }
        }
        else
        {
            cout << "Input must be a number!" << endl;
        }

        cin.clear();
        cin.ignore();
    } while (1);

    return 0;
}

int getRandomNumber(int min, int max)
{
    if (min >= max)
        return 0;

    int *numbers = (int *)malloc(sizeof(int));
    if (!numbers)
        return 0;

    srand(time(NULL));
    return (min + rand() % (max - min));
}