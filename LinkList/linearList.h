#include <iostream>
#include <cstdlib>

//线性表
//enum bool{true, false};
template <typename T>
class LinearList
{
public:
    //LinearList();   //构造函数
    //~LinearList();  //析构函数
    virtual int Size() const = 0;   //表最大提及
    virtual int Length() const = 0; //当前表长度
    virtual int Search(T &x) const = 0; //搜索给定值x
    virtual int Locate(int i) const = 0;    //在表中定位第i个元素
    virtual bool getData(int i, T &x) const = 0;    //取表中第i个元素的值
    virtual void setData(int i, T &x) = 0;    //修改表中第i个元素的值
    virtual bool Insert(int i, T &x) = 0;   //在第i个元素后插入x
    virtual bool Remove(int i, T &x) = 0;   //删除第i个表项
    virtual bool IsEmpty() const = 0;   //表是否为空
    virtual bool IsFull() const = 0;    //表是否为满
    //virtual void Sort() = 0;    //表排序
    virtual void input() = 0;   //输入
    virtual void output() = 0;  //输出
    //virtual LinearList<T> operator=(LinearList<T> &L) = 0;  //复制
};
