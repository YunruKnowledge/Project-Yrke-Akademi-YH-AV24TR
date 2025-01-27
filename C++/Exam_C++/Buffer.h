/**
 * @file Buffer.h
 * @author Lazar Roksandic (roksandiclazar@gmail.com)
 * @brief Library for Circular Buffer using arrays
 * @version 0.1
 * @date 2025-01-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef Buffer_H
#define Buffer_H

#include <iostream>
#include <type_traits>
#include <stdexcept>

/**
 * @brief A class for  creating circlear buffer array using template
 *
 * @tparam T type of array
 * @tparam N max size for the array
 * @tparam std::enable_if_t<std::is_arithmetic_v<T>> allow only numbers
 */
template <typename T, size_t N, typename = std::enable_if_t<std::is_arithmetic_v<T> > >
class CircularBuffer
{
    static constexpr size_t MIN_LENGTH = 4;

    static_assert(N > MIN_LENGTH, "Size is out of range!");

    T array[N];

    int head;
    int tail;

public:
    /**
     * @brief Delete Copy Contractor
     *
     */
    CircularBuffer(const CircularBuffer &) = delete;
    CircularBuffer &operator=(const CircularBuffer &) = delete;

    /**
     * @brief Overload the << to print all unread items form the buffer
     *
     * @param os you print
     * @param cb circular buffer your reading
     * @return std::ostream& all the unread items from the given buffer
     */
    friend std::ostream &operator<<(std::ostream &os, CircularBuffer &cb)
    {
        int _head{cb.head};
        int _tail{cb.tail};

        if (_head != _tail)
        {
            os << '[';

            for (size_t i = _head; i != _tail; i = (i + 1) % N)
            {
                if (i != _head)
                    os << ", ";

                os << cb.array[i];
            }

            os << ']';
        }
        else
        {
            os << "[]";
        }

        return os;
    }

public:
    /**
     * @brief Construct a new Circular Buffer object
     *
     */
    CircularBuffer() : head{-1}, tail{0} {};

    /**
     * @brief Read the latest added value from the circular buffer
     *
     * @return T item that you read
     */
    T read(void)
    {
        if (head == -1)
            head = 0;

        if ((head + 1 > N))
            head = 0;

        T item = array[head];
        head = (head + 1) % N;

        return item;
    }

    /**
     * @brief Function to write items to the circular buffer
     *
     * @param item you want to write into the buffer
     * @return true if you write it successfully
     * @return false if you couldn't write it successfully
     */
    bool write(T item)
    {
        if (isFull())
        {
            head = (head + 1) % N;
        }

        array[tail] = item;
        tail = (tail + 1) % N;

        return true;
    }

    /**
     * @brief Get the Size of Circular Buffer
     *
     * @return int amount of unread items in a buffer
     */
    int getSize(void)
    {
        int _size{0};
        int _head{head};
        int _tail{tail};

        if (_head == -1)
            _head = 0;

        for (size_t i = _head; i != _tail; i++)
        {
            if (i >= N)
                i = 0;

            _size++;
        }

        return (isFull()) ? N : _size;
    }

    /**
     * @brief Function to check if Circular Buffer is full
     *
     * @return true if its full
     * @return false if its not full
     */
    bool isFull(void) { return tail == head; }

    /**
     * @brief Function to clear the buffer
     *
     */
    void clear(void)
    {
        head = -1;
        tail = 0;
    };

    /**
     * @brief Get the Average value from the circular buffer
     *
     * @return double average from all unread valuse from the buffer
     */
    double getAverage(void)
    {
        int _head{head};
        int _tail{tail};
        double sum{0};

        if (_head == -1)
            _head = 0;

        while (_head != _tail)
        {
            sum += array[_head];
            _head = (_head + 1) % N;
        }

        return (getSize() > 0) ? (sum / getSize()) : 0.0;
    }

    /**
     * @brief Destroy the Circular Buffer object
     *
     */
    ~CircularBuffer() = default;
};

#endif // !*