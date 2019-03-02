#include <iostream>

template <class T>
struct LHnode
{
    T key;              // 关键字
    LHnode<T>* next;    // 指针域
};

template <class T>
class LinkedHash
{
private:
    int maxSize;
    LHnode<T>** nodes;
public:
    LinkedHash() : maxSize(0) {}
    LinkedHash(int);
    void output();
    void insertHash(int (*f)(T), T);
    LHnode<T>* searchHash(int (*f)(T), T);
    void delHash(int (*f)(T), T);
};

template <class T>
LinkedHash<T>::LinkedHash(int sz)
{
    maxSize = sz;
    nodes = new LHnode<T>*[maxSize];
    for(int i = 0; i < maxSize; i++)
    {
        nodes[i] = NULL;
    }
}

template <class T>
void LinkedHash<T>::output()
{
    LHnode<T>* p;
    for(int i = 0; i < maxSize; i++)
    {
        p = nodes[i];
        std::cout << i + 1 << "  ";
        if (p == NULL) std::cout << "<NULL> ";
        else
            while (p != NULL)
            {
                std::cout << "------>";
                std::cout << p->key;
                p = p->next;
            }
        std::cout << std::endl;
    }
}


template <class T>
void LinkedHash<T>::insertHash(int (*f)(T), T x)
{
    LHnode<T>* p;
    int k;
    k = (*f)(x);
    p = new LHnode<T>;
    p->key = x;
    p->next = nodes[k - 1];
    nodes[k - 1] = p;
}

template <class T>
LHnode<T>* LinkedHash<T>::searchHash(int (*f)(T), T x)
{
    LHnode<T>* p;
    int k;
    k = (*f)(x);
    p = nodes[k - 1];
    while(p != NULL && p->key != x) p = p->next;
    return p;
}

template <class T>
void LinkedHash<T>::delHash(int (*f)(T), T x)
{
    LHnode<T>* p, * q;
    int k;
    k = (*f)(x);
    p = nodes[k - 1];
    q = NULL;
    while(p != NULL && p->key != x) { q = p; p = p->next; }
    if (p == NULL) std::cout << "can't find the key" << std::endl;
    else if (q != NULL) q->next = p->next;
    else nodes[k - 1] = p->next;
}


