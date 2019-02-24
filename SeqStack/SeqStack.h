#include <iostream>
#include <cstdlib>
#include <cassert>
#include "Stack.h"

const int stackIncreament = 20; //  栈溢出时扩展空间的增量

template<typename T>
class SeqStack;

template<typename T>
std::ostream& operator<<(std::ostream& os, SeqStack<T>& s);


template<typename T>
class SeqStack: public Stack<T>
{
private:
    T *elements;    //栈数组
    int top;    //栈顶指针
    int maxSize;    //栈容量
    void overflowProcess(); //栈溢出处理
    friend std::ostream& operator<< <>(std::ostream& os, SeqStack& s);
public:
    SeqStack(int sz = 50);
    ~SeqStack() { delete[] elements; }
    void push(const T& x);
    bool pop(T& x);
    bool getTop(T& x);
    bool isEmpty() const {return (top == -1) ? true : false;}
    bool isFull() const {return (top == maxSize - 1) ? true : false;}
    int getSize() const { return top + 1; }
    void makeEmpty() { top = -1; }

};

// 构造函数
template<typename T>
SeqStack<T>::SeqStack(int sz):top(-1), maxSize(sz)
{
    elements = new T[maxSize];
    assert(elements != NULL);   //断言 动态存储分配成功与否
}

// 栈溢出处理
// 扩展栈的空间
template<typename T>
void SeqStack<T>::overflowProcess()
{
    T* newArray = new T[maxSize + stackIncreament];
    if (newArray == NULL) { std::cerr << "存储分配失败" << std::endl; exit(1); }
    for(int i = 0; i <= top; i++)
        newArray[i] = elements[i];
    maxSize = maxSize + stackIncreament;
    delete[] elements;
    elements = newArray;
}

// 进栈操作
template<typename T>
void SeqStack<T>::push(const T& x)
{
    if (isFull() == true) overflowProcess();
    elements[++top] = x;
}


// 出栈操作
template<typename T>
bool SeqStack<T>::pop(T& x)
{
    if (isEmpty() == true) return false;
    x = elements[top--];
    return true;
}

//获取栈顶元素
template<typename T>
bool SeqStack<T>::getTop(T& x)
{
    if (isEmpty() == true) return false;
    x = elements[top];
    return true;
}

// 重载输出操作符
template<typename T>
std::ostream& operator<<(std::ostream& os, SeqStack<T>& s)
{
    os << "top = " << s.top << std::endl;
    for(int i = 0;i <= s.top; i++)
        os << i << ":" << s.elements[i] << std::endl;
    return os;

}


