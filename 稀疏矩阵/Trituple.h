// ϡ�������Ԫ��

#include<iostream>
#include<cstdlib>

const int defaultSize = 100;

template <class T>
struct Trituple
{
    int row, col;   //����Ԫ�ص����к�
    T value;
    Trituple<T>& operator=(Trituple<T>& x)  // ��㸳ֵ
    {
        row = x.row; col = x.col;
        value = x.value;
        return *this;
    }
};
