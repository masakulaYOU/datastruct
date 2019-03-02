#include <iostream>

template <class T>
struct HNode    // 线性Hash表结点
{
    int flag;   // 标志表项的空与非空
    T key;      // 关键字
};

template <class T>
class LinearHash
{
private:
    int currentSize;    // 表长度
    HNode<T>* data;    // 线性Hash表存储空间首地址
public:
    LinearHash():currentSize(0){}
    LinearHash(int);
    void output();
    int numOfEmpty();                   //检测Hash表中空项个数
    void insertHash(int (*f)(T), T);    //插入
    int searchHash(int (*f)(T), T);     //查找
};

template <class T>
LinearHash<T>::LinearHash(int m)
{
    int k;
    currentSize = m;
    data = new HNode<T>[currentSize];
    for(k = 0; k < currentSize; k++)
    {
        data[k].flag = 0;
    }
}


template<class T>
void LinearHash<T>::output()
{
    int k;
    for(k = 0; k < currentSize; k++)
    {
        if(data[k].flag == 0)
            std::cout << "<NULL>" << " ";
        else std::cout << "<" << data[k].key << ">";
    }
    std::cout << std::endl;
    return;
}

// 检测线性Hash表中空项个数
template <class T>
int LinearHash<T>::numOfEmpty()
{
    int k, count = 0;
    for(k = 0; k < currentSize; k++)
        if(data[k].flag == 0)
            count++;
    return count;
}

// 插入
template<class T>
void LinearHash<T>::insertHash(int (*f)(T), T x)
{
    int k;
    if(numOfEmpty() == 0) return;  //表满
    k = (*f)(x);    //计算Hash码
    while(data[k-1].flag)   // 该项不空
    {
        k++;
        if(k == currentSize + 1) k = 1; //下一项
    }
    data[k - 1].key = x;
    data[k - 1].flag = 1;
    return;
}

// 查找
template <class T>
int LinearHash<T>::searchHash(int (*f)(T), T x)
{
    int k;
    k = (*f)(x);    // 计算Hash码
    while(data[k - 1].flag && data[k - 1].key != x)
    {
        k = k + 1;
        if (k == currentSize + 1) k = 1;
    }
    if (data[k - 1].flag && data[k - 1].key == x) return k;
    return 0;
}


