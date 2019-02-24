#include<iostream>
#include<cstdlib>

const int maxSize = 50;

template<class T>
class Queue
{
    virtual bool enQueue(const T& x) = 0; //��Ԫ��x������
    virtual bool deQueue(T& x) = 0; //��ͷԪ�س�����
    virtual bool getFront(T& x) = 0;    //��ȡ��ͷԪ�ص�ֵ
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0; //�����Ԫ�ظ���

};
