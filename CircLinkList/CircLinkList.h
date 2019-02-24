#include <iostream>
#include <cstdlib>
#include "CircLinkNode.h"

using namespace std;

template<typename T>
class CircLinkList
{
private:
    CircLinkNode<T>* first, *last;
public:
    CircLinkList(const T& x);   //构造函数
    CircLinkList(CircLinkList<T>& L);   //复制构造函数
    ~CircLinkList();    //析构函数
    int Length() const; //循环列表长度
    bool IsEmpty() {return first->link == first ? true : false;}
    CircLinkNode<T>* getHead() const;
    void setHead(CircLinkNode<T>* p);
    CircLinkNode<T>* Search(T x);
    CirclinkNode<T>* Locate(int i);
    T* getData(int i);
    void setData(int i, T& x);
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
};

// 构造函数
template <typename T>
CircLinkList<T>::CircLinkList(const T& x)
{
    first = new CircLinkNode<T>(x);
    first->
}
