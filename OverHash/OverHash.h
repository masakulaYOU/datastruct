#include <iostream>

template <class T>
struct Hnode
{
    int flag;
    T key;
};

template <class T>
class OverHash
{
private:
    int maxSize;
    int overSize;   // 溢出表长度
    Hnode<T>* nodes;
    Hnode<T>* overNodes;
public:
    OverHash() : maxSize(0), overSize(0) {}
    OverHash(int, int);
    void output();
    int numOfEmpty();
    void insertHash(int (*f)(T), T);
    int searchHash(int (*f)(T), T);
    void delHash(int (*f)(T), T);
};

template <class T>
OverHash<T>::OverHash(int sz, int osz)
{
    maxSize = sz; overSize = osz;
    nodes = new Hnode<T>[maxSize];
    overNodes = new Hnode<T>[overSize];
    int i;
    for(i = 0; i < maxSize; i++)
        nodes[i].flag = 0;
    for(i = 0; i < overSize; i++)
        overNodes[i].flag = 0;
}

template <class T>
void OverHash<T>::output()
{
    int i;
    std::cout << "Hash:" << std::endl;
    for(i = 0; i < maxSize; i++)
        if (nodes[i].flag == 0)
            std::cout << "<NULL>" << " ";
        else
            std::cout << "<" << nodes[i].key << "> ";
    std::cout << std::endl;

    std::cout << "overHash:" << std::endl;
    for(i = 0; i < overSize; i++)
        if (overNodes[i].flag == 0)
            std::cout << "<NULL>" << " ";
        else
            std::cout << "<" << overNodes[i].key << "> ";
    std::cout << std::endl;
}

template <class T>
int OverHash<T>::numOfEmpty()
{
    int count = 0;
    for(int i = 0; i < overSize; i++)
        if (overNodes[i].flag == 0)
            count++;
    return count;
}

template <class T>
void OverHash<T>::insertHash(int (*f)(T), T x)
{
    int k;
    k = (*f)(x);
    if (nodes[k - 1].flag == 0){ nodes[k - 1].flag = 1; nodes[k - 1].key = x;}
    else
    {
        k = 1;
        while (k <= overSize && overNodes[k - 1].flag) k++;
        if(k > overSize) std::cout << "overHash is full!" <<std::endl;
        else { overNodes[k - 1].flag = 1; overNodes[k - 1].key = x; }
    }
}


template <class T>
int OverHash<T>::searchHash(int (*f)(T), T x)
{
    int k, j = 0;
    k = (*f)(x);
    if (nodes[k - 1].flag == 0) return 0;
    if (nodes[k - 1].key == x) return k;
    k = 1;
    while(k <= overSize && overNodes[k - 1].flag && overNodes[k - 1].key != x) k++;
    if (overNodes[k - 1].flag && overNodes[k - 1].key == x) return k;
    return 0;
}


template <class T>
void OverHash<T>::delHash(int (*f)(T), T x)
{
    int k, j, kk;
    k = (*f)(x);
    if(nodes[k - 1].flag)
    {
        if (nodes[k - 1].key == x)
        {
            j = 1; kk = 0;
            while(j <= overSize && overNodes[j - 1].flag)
            {
                if ((*f)(overNodes[j - 1].key) == k) kk = j;
                j++;
            }
            if (kk != 0)
            {
                nodes[k - 1].key = overNodes[kk - 1].key;
                while(kk + 1 <= overSize && overNodes[kk].flag)
                {
                    overNodes[kk - 1].key = overNodes[kk].key;
                    kk++;
                }
                overNodes[kk - 1].flag = 0;
            }
            else nodes[k - 1].flag = 0;
        }
        else
        {
            j = 1;
            while(j <= overSize && overNodes[j - 1].flag && overNodes[j - 1].key != x) j++;
            if (overNodes[j - 1].key == x)
            {
                while(j + 1 <= overSize && overNodes[j].flag)
                {
                    overNodes[j - 1].key = overNodes[j].key;
                    j++;
                }
                overNodes[j - 1].flag = 0;
            }
            else
                std::cout << "can't find the key!" <<std::endl;
        }
    }
    else
        std::cout << "can't find the key!" <<std::endl;
}


