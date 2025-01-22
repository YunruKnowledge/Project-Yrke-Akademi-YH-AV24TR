/**
 * @file index.cpp  
 * @author Lazar Roksandic
 * @brief Array template that is movable but not copiable 
 * @version 0.1
 * @date 2025-01-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <initializer_list>
#include <iostream>
#include <utility>

template <typename T>
class Array
{
    T *ptr;
    size_t size;

public:
    Array() = default;

    Array(const Array &) = delete;
    Array &operator=(const Array &) = delete;

    Array(Array &&that) noexcept : size{that.size}, ptr{that.ptr}
    {
        that.ptr = nullptr;
        that.size = 0;
    }

    Array &operator=(Array &&that) noexcept
    {
        if (this != &that)
        {
            delete ptr;

            ptr = that.ptr;
            size = that.size;

            that.ptr = nullptr;
            that.size = 0;
        }

        return *this;
    }

    T &operator[](int index)
    {
        if (index >= size)
        {
            throw std::range_error("Index is out of range!");
        }

        return ptr[index];
    }

    friend std::ostream &operator<<(std::ostream &os, const Array &arr)
    {
        os << "[";
        for (size_t i = 0; i < arr.size; i++)
        {
            if (i == arr.size - 1)
            {
                os << arr.ptr[i];
            }
            else
            {
                os << arr.ptr[i] << ", ";
            }
        }
        os << "]";

        return os;
    }

public:
    Array(size_t _size) : size{_size}, ptr{new T[_size]{}} {}

    Array(std::initializer_list<T> _list) : size(_list.size()), ptr(new T[_list.size()]{})
    {
        const T *it = _list.begin();
        T *temp = ptr;

        while (it != _list.end())
        {
            *temp = *it;
            ++it;
            ++temp;
        }
    }

    int getSize(void) { return size; }

    void resize(size_t _size)
    {
        if (_size < size)
        {
            T *temp = new T[_size]{};

            for (size_t i = 0; i < _size; i++)
            {
                temp[i] = ptr[i];
            }

            ptr = temp;
            size = _size;
        }
        else if (_size > size)
        {
            T *temp = new T[_size]{};

            for (size_t i = 0; i < size; i++)
            {
                temp[i] = ptr[i];
            }

            ptr = temp;
            size = _size;
        }
        else
        {
            ;
        }
    }

    ~Array() { delete[] ptr; }
};

int main(void)
{
    Array<int> arr{1, 2, 3, 4, 5};

    try
    {
        arr.resize(3);
        std::cout << arr << std::endl;
        std::cout << arr.getSize() << std::endl;

        Array<int> newArray{std::move(arr)};
        std::cout << newArray << std::endl;
        std::cout << newArray.getSize() << std::endl;

        arr = std::move(newArray);
        std::cout << arr << std::endl;
        std::cout << arr.getSize() << std::endl;
    }
    catch (std::range_error e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}