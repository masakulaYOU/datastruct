#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Stack.h"
#include "linkNode.h"

template<typename T>
class LinkedStack;

template<typename T>
std::ostream& operator<<(std::ostream& os, LinkedStack<T>& L);

template<typename T>
class LinkedStack:public Stack<T>
{
private:
    LinkNode<T>* top;   //栈顶指针
public:
    LinkedStack():top(NULL){}
    ~LinkedStack(){makeEmpty();}
    void makeEmpty();
    void push(const T& x);
    bool pop(T& x);
    bool getTop(T& x);
    bool isEmpty() const {return (top->link == NULL) ? true : false;}
    bool isFull() const {return false;}
    int getSize() const;
    friend std::ostream& operator<< <> (std::ostream& os, LinkedStack& L);
};

template<typename T>
void LinkedStack<T>::makeEmpty()
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
template<typename T>
void LinkedStack<T>::push(const T& x)
{
    top = new LinkNode<T>(x, top);
    assert(top != NULL);
}


template<typename T>
bool LinkedStack<T>::pop(T& x)
{
    if(isEmpty() == true) return false;
    LinkNode<T>* p = top;
    top = top->link;
    x = p->data;
    delete p;
    return true;
}

template<typename T>
bool LinkedStack<T>::getTop(T& x)
{
    if(isEmpty() == true) return false;
    x = top->data;
    return true;
}

template<typename T>
int LinkedStack<T>::getSize() const
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

template<typename T>
std::ostream& operator<<(std::ostream& os, LinkedStack<T>& L)
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




