#include <iostream>
#include <cstdlib>

const int maxSize = 100;
template <typename T>
class Stack
{
public:
    virtual void push(const T& x) = 0;
    virtual bool pop(T& x) = 0;
    virtual bool getTop(T& x) = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0;
};
