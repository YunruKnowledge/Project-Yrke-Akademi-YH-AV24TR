#include <iostream>
#include <type_traits>

template <typename T>
class Range
{
public:
    friend std::ostream &operator<<(std::ostream &os, const Range &range)
    {
        os << "{" << range.x << ", " << range.y << "}";
        return os;
    }

public:
    T x;
    T y;
};

template <typename Tp, typename T>
T map(Tp value, Range<Tp> range_a, Range<T> range_b)
{
    static_assert(std::is_arithmetic_v<Tp> && std::is_arithmetic_v<T>);
    return (((range_b.y - range_b.x) / (range_a.y - range_b.x)) * (value - range_a.x) + range_b.x);
};

int main(void)
{
    Range<float> a{0.0f, 3.3f};
    Range<int> b{0, 1023};

    std::cout << map(0.5f, a, b) << std::endl;

    return 0;
}