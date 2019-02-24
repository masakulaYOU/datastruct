#include<iostream>
#include<cstdlib>

const int maxSize = 50;

template<class T>
class Queue
{
    virtual bool enQueue(const T& x) = 0; //新元素x进队列
    virtual bool deQueue(T& x) = 0; //队头元素出队列
    virtual bool getFront(T& x) = 0;    //读取队头元素的值
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0; //求队列元素个数

};
