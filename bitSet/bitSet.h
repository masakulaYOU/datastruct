#include <iostream>
#include <cassert>
#include "Set.h"

const int defaultSize = 50;

template <class T>
class bitSet;
template <class T>
std::istream& operator >> (std::istream& in, bitSet<T>& R);
template <class T>
std::ostream& operator << (std::ostream& os, bitSet<T>& R);
// 用位向量来存储集合元素
// 这些集合元素只具有证书类型，集合元素的范围在0到setSize - 1之间
// 数组采用16位无符号短整数实现位映射
template <class T>
class bitSet
{
private:
    int setSize;    //集合大小
    int vectorSize; //位数组大小
    unsigned short* bitVector;  //存储集合元素的位数组
public:
    bitSet(int sz = defaultSize);
    bitSet(const bitSet<T>& R);
    ~bitSet(){delete[] bitVector;}
    void makeEmpty()
        { for(int i = 0; i < vectorSize; i++) bitVector[i] = 0; }
    unsigned short getMember(const T x);
    void putMember(const T x, unsigned short v);
    bool addMember(const T x);
    bool delMember(const T x);
    bitSet<T>& operator = (const bitSet<T>& R);
    bitSet<T>& operator + (const bitSet<T>& R);
    bitSet<T>& operator * (const bitSet<T>& R);
    bitSet<T>& operator - (const bitSet<T>& R);
    bool contains(const T);
    bool subSet(bitSet<T>& R);
    bool operator == (bitSet<T>& R);
    friend std::istream& operator >> <> (std::istream& in, bitSet& R);
    friend std::ostream& operator << <> (std::ostream& os, bitSet& R);
};


template <class T>
bitSet<T>::bitSet(int sz) : setSize(sz)
{
    assert(setSize > 0);
    vectorSize = (setSize + 15) >> 4;   //存储数组大小 16位*个数
    bitVector = new unsigned short [vectorSize];
    assert(bitVector != NULL);
    for(int i = 0; i < vectorSize; i++) bitVector[i] = 0;
}

template <class T>
bitSet<T>::bitSet(const bitSet<T>& R)
{
    setSize = R.setSize;
    vectorSize = R.vectorSize;
    bitVector = new unsigned short[vectorSize];
    assert(bitVector != NULL);
    for(int i = 0; i < vectorSize; i++) bitVector[i] = R.bitVector[i];
}



template <class T>
unsigned short bitSet<T>::getMember(const T x)
{
    int ad = x / 16, id = x % 16;
    unsigned short elem = bitVector[ad];
    return ((elem >> (15 - id)) % 2);
}

template <class T>
void bitSet<T>::putMember(const T x, unsigned short v)
{
    int ad = x / 16, id = x % 16;
    unsigned short elem = bitVector[ad];
    unsigned short temp = elem >> (15 - id);
    elem = elem << (id + 1);
    if(temp % 2 == 0 && v == 1) temp = temp + 1;
    else if(temp % 2 == 1 && v == 0) temp = temp - 1;
    bitVector[ad] = (temp << (15 - id)) | (elem >> (id + 1));
}


template <class T>
bool bitSet<T>::addMember(const T x)
{
    assert(x >= 0 && x < setSize);
    if (getMember(x) == 0)
    {
        putMember(x, 1);
        return true;
    }
    return false;
}

template <class T>
bool bitSet<T>::delMember(const T x)
{
    assert(x >= 0 && x < setSize);
    if (getMember(x) == 1)
    {
        putMember(x,0);
        return true;
    }
    return false;
}

template <class T>
bitSet<T>& bitSet<T>::operator = (const bitSet<T>& R)
{
    assert(vectorSize == R.vectorSize);  // 判断两集合大小是否相等
    bitSet<T> temp(vectorSize);
    for(int i = 0; i < vectorSize; i++)
        temp.bitVector[i] = R.bitVector[i];
    return temp;
}

template <class T>
bitSet<T>& bitSet<T>::operator + (const bitSet<T>& R)
{
    assert(vectorSize == R.vectorSize);  // 判断两集合大小是否相等
    bitSet<T> temp(vectorSize);
    for(int i = 0; i < vectorSize; i++)
        temp.bitVector[i] = bitVector[i] | R.bitVector[i];
    return temp;
}

template <class T>
bitSet<T>& bitSet<T>::operator * (const bitSet<T>& R)
{
    assert(vectorSize == R.vectorSize);  // 判断两集合大小是否相等
    bitSet<T> temp(vectorSize);
    for(int i = 0; i < vectorSize; i++)
        temp.bitVector[i] = bitVector[i] & R.bitVector[i];
    return temp;
}

template <class T>
bitSet<T>& bitSet<T>::operator - (const bitSet<T>& R)
{
    assert(vectorSize == R.vectorSize);  // 判断两集合大小是否相等
    bitSet<T> temp(vectorSize);
    for(int i = 0; i < vectorSize; i++)
        temp.bitVector[i] = bitVector[i] & !R.bitVector[i];
    return temp;
}

template <class T>
bool bitSet<T>::contains(const T x)
{
    assert(x >= 0 && x <= setSize);
    return (getMember(x) == 1) ? true : false;
}

template <class T>
bool bitSet<T>::subSet(bitSet<T>& R)
{
    assert(setSize == R.setSize);
    for(int i = 0; i < vectorSize; i++)
        if (bitVector[i] & !R.bitVector[i])
            return false;
    return true;
}

template <class T>
bool bitSet<T>::operator == (bitSet<T>& R)
{
    if (vectorSize != R.vectorSize) return false;
    for(int i = 0; i < vectorSize; i++)
        if (bitVector[i] != R.bitVector[i])
            return false;
    return true;
}

template <class T>
std::istream& operator >> (std::istream& in, bitSet<T>& R)
{

}

template <class T>
std::ostream& operator << (std::ostream& os, bitSet<T>& R)
{
    for(int i = 0; i < R.vectorSize; i++)
        os << R.bitVector[i] << " ";
    os << std::endl;
    return os;
}



