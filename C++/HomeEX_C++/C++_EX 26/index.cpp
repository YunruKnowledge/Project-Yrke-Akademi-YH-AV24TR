#include <iostream>
#include <type_traits>

constexpr int ARRAY_SIZE = 5;

template <typename T, size_t size, typename = std::enable_if_t<std::is_array_v<T[size]>>>
void print(const T (&array)[size])
{
    static_assert(std::is_array<T[size]>::value == true, "Passed value is not an array!");

    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i] << std::endl;
    }
}

template <typename T, size_t size>
using pPrint = void (*)(const T(&array)[size]);


int main(void)
{
    int arr[ARRAY_SIZE]{0, 1, 2, 3, 4};

    pPrint<int, ARRAY_SIZE> p = print<int, ARRAY_SIZE>;
    p(arr);

    return 0;
}           