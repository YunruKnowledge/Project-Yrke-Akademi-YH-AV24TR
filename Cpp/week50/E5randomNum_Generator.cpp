#include <iostream>
#include <random>
#include <unistd.h> //usleep

int main()
{

    int arrNums[10];

    std::random_device dev;                                                // seed
    std::mt19937 rng(dev());                                               // takes the seed,
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99); // type, minn and max val

    int randomNumber = dist6(rng); // feed the time to rand.

    constexpr int sizeOfArray = 10;
    // foreach loop, but not good in embedded.(soufien and khan said)
    for (int &_N : arrNums) // everything inside the array will be randomised.
    {
        _N = dist6(rng);
    }

    int holder = 0;

    std::cout << "** The unsorted array: **\v" << std::endl;
    do
    {
        std::cout << "Position:" << holder << std::endl;
        std::cout << arrNums[holder] << '\v' << std::endl;

        holder++;
    } while (holder < sizeOfArray);

    /*  Sort array  */
    std::cout << "~~ The sorted array: ~~\v" << std::endl;

    int tempHold;
    bool swapped = false;

    for (int i = 0; i < sizeOfArray; i++)
    {
        swapped = false;
        for (int j = 0; j < sizeOfArray - i - 1; j++)
        {

            if (arrNums[j] > arrNums[j + 1])
            {
                tempHold = arrNums[j];       // copy of 10
                arrNums[j] = arrNums[j + 1]; // move 5 to i(start)
                arrNums[j + 1] = tempHold;   // copy of 10 goes to right of 5.
                swapped = true;
                // usleep(1000000); // yarim saniye
            }

        }
            if (!swapped)
            {
                std::cout << "**** STOPPED BECAUSE EVERYTHING IS ALREADY SORTED! ****" << std::endl;
                break;
            }
    }

    printf("\n");

    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("### ARR pos %i is %i\n", i, arrNums[i]);
    }

    return 0;
}