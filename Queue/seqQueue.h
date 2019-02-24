/*
    ѭ������
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
    int rear, front;    //��β���ͷָ��
    T* elements;       //��Ŷ���Ԫ�ص�����
    int maxSize;        //������������Ԫ�ظ���
public:
    SeqQueue(int sz = 10);  //���캯��
    ~SeqQueue(){delete[] elements;}
    bool enQueue(const T& x);   //������
    bool deQueue(T& x); //������
    bool getFront(T& x);    //��ͷԪ�ص�ֵ
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

// ������
template<class T>
bool SeqQueue<T>::enQueue(const T& x)
{
    if(isFull() == true) return false;
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
}

// ������
template<class T>
bool SeqQueue<T>::deQueue(T& x)
{
    if(isEmpty() == true) return false;
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
}

// ��ͷԪ�ص�ֵ
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

