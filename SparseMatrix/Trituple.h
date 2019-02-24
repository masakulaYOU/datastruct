// 稀疏矩阵三元组

#include<iostream>
#include<cstdlib>

const int defaultSize = 100;

template <class T>
struct Trituple
{
    int row, col;   //非零元素的行列号
    T value;
    Trituple<T>& operator=(Trituple<T>& x)  // 结点赋值
    {
        row = x.row; col = x.col;
        value = x.value;
        return *this;
    }
};
