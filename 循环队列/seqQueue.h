/*
    循环队列
*/

#include<iostream>
#include<cassert>
#include "queue.h"

template<class T>
class SeqQueue;

template<class T>
std::ostream& operator<<(std::ostream& os, SeqQueue<T>& s);

template<class T>
class SeqQueue:public Queue<T>
{
private:
    int rear, front;    //对尾与对头指针
    T* elements;       //存放队列元素的数组
    int maxSize;        //队列最大可容纳元素个数
public:
    SeqQueue(int sz = 10);  //构造函数
    ~SeqQueue(){delete[] elements;}
    bool enQueue(const T& x);   //进队列
    bool deQueue(T& x); //出队列
    bool getFront(T& x);    //队头元素的值
    bool isEmpty() const {return (front == rear) ? true : false;}
    bool isFull() const {return ((rear + 1) % maxSize == front) ? true : false;}
    int getSize() const {return (rear - front + maxSize) % maxSize; }
    friend std::ostream& operator << <> (std::ostream& os, SeqQueue& s);
};

template<class T>
SeqQueue<T>::SeqQueue(int sz):front(0),rear(0),maxSize(sz)
{
    elements = new T[maxSize];
    assert(elements != NULL);
}

// 进队列
template<class T>
bool SeqQueue<T>::enQueue(const T& x)
{
    if(isFull() == true) return false;
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

// 出队列
template<class T>
bool SeqQueue<T>::deQueue(T& x)
{
    if(isEmpty() == true) return false;
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

// 队头元素的值
template<class T>
bool SeqQueue<T>::getFront(T& x)
{
    if(isEmpty() == true) return false;
    x = elements[front];
    return true;
}

template<class T>
std::ostream& operator<<(std::ostream& os, SeqQueue<T>& s)
{
    os << "front = " << s.front << ", rear = " << s.rear << std::endl;
    for(int i = s.front; i != s.rear; i = (i + 1) % s.maxSize)
        os << i << ": "<< s.elements[i] << std::endl;
    return os;
}

