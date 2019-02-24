#include <iostream>
#include <cstdlib>

using namespace std;

// 结点结构体
template <typename T>
struct CircLinkNode
{
    T data; //数据域
    CircLinkNode<T>* link;  //指针域
    CircLinkNode(CircLinkNode<T>* next = NULL):link(next){} //构造函数
    CircLinkNode(T d, CircLinkNode<T>* next = NULL):data(d),link(next){} //构造函数
};
