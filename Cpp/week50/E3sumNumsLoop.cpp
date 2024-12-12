#include <iostream>

int main(void)
{
    int N;
    std::cout << "input a value" << std::endl;
    std::cin >> N >> std::endl;

        int sumValue = 0;
     for (int i = 0; i < N; i++)
    {
        sumValue += i;
    }

    std::cout << "The all the numbers up to " << N << " summed up together is " << sumValue << std::endl;

    return 0;
}