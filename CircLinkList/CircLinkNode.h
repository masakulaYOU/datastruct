#include <iostream>
#include <cstdlib>

using namespace std;

// ���ṹ��
template <typename T>
struct CircLinkNode
{
    T data; //������
    CircLinkNode<T>* link;  //ָ����
    CircLinkNode(CircLinkNode<T>* next = NULL):link(next){} //���캯��
    CircLinkNode(T d, CircLinkNode<T>* next = NULL):data(d),link(next){} //���캯��
};
