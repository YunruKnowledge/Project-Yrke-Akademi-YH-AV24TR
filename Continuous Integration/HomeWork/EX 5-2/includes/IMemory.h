#ifndef IMEMORY_H
#define IMEMORY_H

#include <cstddef>

struct IMemory
{
    virtual void *malloc(size_t size) = 0;
    virtual void free(void *ptr) = 0;

    virtual ~IMemory() {};
};

#endif // !IMEMORY_H