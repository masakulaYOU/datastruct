#include <iostream>
#include <cstdlib>
#include <cassert>
#include "linkNode.h"

template<class T>
class Stack;

template<class T>
std::ostream& operator<<(std::ostream& os, Stack<T>& L);

template<class T>
class Stack
{
private:
    LinkNode<T>* top;   //栈顶指针
public:
    Stack():top(NULL){}
    ~Stack(){makeEmpty();}
    void makeEmpty();
    void push(const T& x);
    bool pop(T& x);
    bool getTop(T& x);
    bool isEmpty() const {return (top->link == NULL) ? true : false;}
    bool isFull() const {return false;}
    int getSize() const;
    friend std::ostream& operator<< <> (std::ostream& os, Stack& L);
};

template<class T>
void Stack<T>::makeEmpty()
{
    LinkNode<T>* p;
    while(top != NULL)
    {
        p = top;
        top = top->link;
        delete p;
    }
}

// 前插法？？？
template<class T>
void Stack<T>::push(const T& x)
{
    top = new LinkNode<T>(x, top);
    assert(top != NULL);
}


template<class T>
bool Stack<T>::pop(T& x)
{
    if(isEmpty() == true) return false;
    LinkNode<T>* p = top;
    top = top->link;
    x = p->data;
    delete p;
    return true;
}

template<class T>
bool Stack<T>::getTop(T& x)
{
    if(isEmpty() == true) return false;
    x = top->data;
    return true;
}

template<class T>
int Stack<T>::getSize() const
{
    LinkNode<T>* p = top;
    int num = 0;
    while( p!= NULL)
    {
        p = p->link;
        num++;
    }
    return num;
}

template<class T>
std::ostream& operator<<(std::ostream& os, Stack<T>& L)
{
    os << "栈中元素个数=" << L.getSize() << std::endl;
    LinkNode<T>* p = L.top;
    int i = 0;
    while(p != NULL)
    {
        os << ++i << ":" << p->data << std::endl;
        p = p->link;
    }
    return os;
}




