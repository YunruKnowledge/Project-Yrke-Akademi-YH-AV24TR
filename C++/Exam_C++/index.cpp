#include <cassert>
#include <iostream>
#include "Buffer.h"

int main(void)
{
    try
    {
        CircularBuffer<int, 5> buffer;

        assert(buffer.getSize() == 0);
        std::cout << "Creating Empty Buffer!" << std::endl;

        // Test Writeing into the buffer
        assert(buffer.write(10));
        assert(buffer.write(20));
        assert(buffer.write(30));
        std::cout << "Testing write function..." << std::endl;

        // Test getting size
        assert(buffer.getSize() == 3);
        std::cout << "Checking if size is correct after writing..." << std::endl;

        // Test Reading the buffer
        assert(buffer.read() == 10);
        assert(buffer.read() == 20);
        std::cout << "Testing read function..." << std::endl;

        // Test getting the size after moving the head
        assert(buffer.getSize() == 1);
        std::cout << "Checking if size is correct after writing..." << std::endl;

        // Test overwriting the buffer to check if its circular
        assert(buffer.write(40));
        assert(buffer.write(50));
        assert(buffer.write(60));
        assert(buffer.write(70));
        assert(buffer.write(80));
        std::cout << "Testing circular write function..." << std::endl;

        std::cout << "Buffer after adding to many items: " << buffer << " Note! its empty because head and tail are in same position!" << std::endl;

        // Test Reading again to move the head
        assert(buffer.read() == 40);
        assert(buffer.read() == 50);
        std::cout << "Testing circular read function..." << std::endl;

        // Print buffer from head to tail
        std::cout << "Buffer after reading items: " << buffer << std::endl;

        // Test size
        assert(buffer.getSize() == 3);
        std::cout << "Checking if size is correct after reading..." << std::endl;

        buffer.clear();

        // Test size after clearing
        assert(buffer.getSize() == 0);
        std::cout << "Checking if size is correct after clearing..." << std::endl;

        std::cout << "Buffer after clearing: " << buffer << std::endl;

        // Write to the freshly cleared buffer
        assert(buffer.write(10));
        assert(buffer.write(15));
        assert(buffer.write(20));
        assert(buffer.write(25));

        std::cout << "Testing writing new items into a clear buffer... " << std::endl;

        std::cout << "Buffer after adding new items: " << buffer << std::endl;

        // Check if average is correct
        assert(buffer.getAverage() == 17.5);
        std::cout << "Testing if average is correct... " << std::endl;
        std::cout << "Average: " << buffer.getAverage() << std::endl;

        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "All Test Passed!" << std::endl;

        buffer.clear();

        std::cout << buffer << std::endl;
    }
    catch (const std::runtime_error &e) // Throw an error if array is a nullptr
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}