#include <iostream>

template <class T>
struct Hnode
{
    int flag;
    T key;
};

template <class T>
class RndHash
{
private:
    int maxSize;
    Hnode<T>* nodes;    //Hash表存储空间首地址
    int* rnd;           //随机数序列存储空间首地址
public:
    RndHash() : maxSize(0) {}
    RndHash(int);
    void output();
    int numOfEmpty();
    void insertHash(int (*f)(T), T);
    int searchHash(int (*f)(T), T);
};

template <class T>
RndHash<T>::RndHash(int sz)
{
    int k, r;
    maxSize = sz;
    nodes = new Hnode<T>[maxSize];
    for(int i = 0; i < maxSize; i++)
        nodes[i].flag = 0;
    rnd = new int[maxSize];
    r = 1;
    // 创建伪随机数序列
    for(k = 0; k < maxSize; k++)
    {
        r = r * 5;
        if (r >= 4 * maxSize)
            r = r - 4 * maxSize;
        rnd[k] = r / 4;
    }
}


template <class T>
void RndHash<T>::output()
{
    for(int i = 0; i < maxSize; i++)
        if(nodes[i].flag == 0)
            std::cout << "<NULL>" << " ";
        else
            std::cout << "<" << nodes[i].key << "> ";
    std::cout << std::endl;
}

template <class T>
int RndHash<T>::numOfEmpty()
{
    int count = 0;
    for(int i = 0; i < maxSize; i++)
        if (nodes[i].flag == 0)
            count ++;
    return count;
}

template <class T>
void RndHash<T>::insertHash(int (*f)(T), T x)
{
    int j = 0;
    if(numOfEmpty() == 0) { std::cout << "表已满" << std::endl; return; }
    int k = (*f)(x);
    while(nodes[k - 1].flag)
    {
        k = k + rnd[j];
        if(k > maxSize) k -= maxSize;
        j++;
    }
    nodes[k - 1].key = x;
    nodes[k - 1].flag = 1;
}

template <class T>
int RndHash<T>::searchHash(int (*f)(T), T x)
{
    int j = 0;
    int k = (*f)(x);
    while(nodes[k - 1].flag && nodes[k - 1].key != x)
    {
        k = k + rnd[j];
        if (k > maxSize) k -= maxSize;
        j++;
    }
    if (nodes[k - 1].flag && nodes[k - 1].key == x)
        return k;
    return 0;
}

