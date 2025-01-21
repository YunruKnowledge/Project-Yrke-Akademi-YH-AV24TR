#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

bool getRandomNumberInRange(int min, int max, int amount, std::vector<unsigned int> &v);
bool isPrime(unsigned int num);
bool comp(int a, int b);

void removePrime(std::vector<unsigned int> &v);
void sortVector(std::vector<unsigned int> &v);
void printVector(std::vector<unsigned int> v);

int main(void)
{
    std::vector<unsigned int> v;

    std::cout << "------------------------" << std::endl;
    std::cout << "Vector" << std::endl;
    std::cout << "------------------------" << std::endl;

    getRandomNumberInRange(100, 10000, 1000, v);
    printVector(v);

    std::cout << "------------------------" << std::endl;
    std::cout << "Vector after removing prime numbers" << std::endl;
    std::cout << "------------------------";

    removePrime(v);
    printVector(v);

    std::cout << "------------------------" << std::endl;
    std::cout << "Sorted vector" << std::endl;
    std::cout << "------------------------" << std::endl;

    sortVector(v);
    printVector(v);

    return 0;
}

bool getRandomNumberInRange(int min, int max, int amount, std::vector<unsigned int> &v)
{
    srand(time(0));
    for (size_t i = 0; i < amount; i++)
    {
        int random = min + (rand() % ((max - min) + 1));
        v.push_back(random);
    }

    return v.size() == amount;
}

void removePrime(std::vector<unsigned int> &v)
{
    for (auto i = v.begin(); i != v.end();)
    {
        if (isPrime(*i))
        {
            i = v.erase(i);
        }
        else
        {
            i++;
        }
    }

    std::cout << std::endl;
}

bool isPrime(unsigned int num)
{
    bool status{true};

    if (num % 2 == 0)
        status = false;

    for (unsigned i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            status = false;
            break;
        }
    }

    return status;
}

void printVector(std::vector<unsigned int> v)
{
    for (auto i : v)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void sortVector(std::vector<unsigned int> &v)
{
    std::sort(v.begin(), v.end(), comp);
}

bool comp(int a, int b)
{
    return a < b;
}