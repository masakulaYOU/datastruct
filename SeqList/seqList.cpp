#include<iostream>
#include<cstdlib>
#include "seqList.h"

using namespace std;

/*
    构造函数
    通过指定参数sz定义数组的长度
*/
template<typename T>
SeqList<T>::SeqList(int sz)
{
    if(sz > 0)
    {
        maxSize = sz;   //赋值表的最大长度
        last = -1;      //表的当前长度为空
        data = new T[maxSize];  //创建并保存数组
        if (data == NULL)
        {
            cerr << "存储分配错误！" << endl;
            exit(1);
        }
    }
}

/*
    赋值构造函数
    用参数表中给出的已有的顺序表初始化新建的顺序表
*/
template<typename T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    maxSize = L.Size(); //赋值最大长度
    last = L.Length() - 1; //当前表长
    T value;
    data = new T[maxSize];  //分配内存
    if(data == NULL)
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    for(int i = 1; i < last + 1; i++)
    {
        L.getData(i, value); //将第i个元素的值赋值给value
        data[i - 1] = value; //赋值给data
    }
}

/*
    私有函数
    扩充顺序表的存储数组空间大小
    新数组的元素个数为newSize
*/
template<typename T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize < 0)
    {
        cerr << "无效的数组大小！" << endl;
        exit(1);
    }
    if (newSize != maxSize)
    {
        T* newArray = new T[newSize];   //创建新数组
        if (newArray == NULL)
        {
            cerr << "存储分配错误！" << endl;
            exit(1);
        }
        int n = last + 1;
        T* srcptr = data;   //原数组首地址
        T* destptr = newArray;  //新数组的首地址
        while(n--)
            *destptr++ = *srcptr++; //循环赋值数组
        delete[] data;  //删除原数组
        data = newArray;//复制新数组
        maxSize = newSize;  //修改数组的容量
    }
}

/*
    搜索函数
    在表中顺序搜索与给定值x匹配的表项
    找到则函数返回该表项是第几个元素
    否则函数返回0
*/
template<typename T>
int SeqList<T>::Search(T &x) const
{
    for (int i = 0; i <= last; i++)
        if (data[i] == x)
            return i + 1; //顺序搜索
    return 0;
}

/*
    定位函数
    函数返回第i个表项的位置 1<= i <= last + 1
    否则返回0 定位失败
*/
template<typename T>
int SeqList<T>::Locate(int i) const
{
    if (i >= 1 && i <= last + 1) return i;
    return 0;
}

/*
    取值函数
    取第i个元素，其值通过x传递
    返回是否传递成功
*/
template<typename T>
bool SeqList<T>::getData(int i, T& x) const
{
    if (i > 0 && i < last + 1)
    {
        x = data[i - 1];
        return true;
    }
    return false;
}


/*
    修改第i个元素的值
*/
template<typename T>
void SeqList<T>::setData(int i, T& x)
{
    if (i > 0 && i < last + 1)
    {
        data[i - 1] = x;
        return true;
    }
    return false;
}


/*
    插入函数
    将新元素x插入到第i个元素之后
    函数返回插入成功的信息
    若插入成功，则返回true
    否则返回false
    i = 0就是将x插入第一个元素位置
*/
template<typename T>
bool SeqList<T>::Insert(int i, T& x)
{
    if (last == maxSize - 1) return false;  //表满，不能插入
    if (i < 0 || i > last + 1) return false;    //插入位置不合理
    for (int j = last; j >= i; j--)
    {
        data[j + 1] = data[j];  //依次后移，空出第i号位置
    }
    data[i] = x;    //将x赋值到第i号元素
    last++;         //最后位置+1
    return true;
}

/*
    移除函数
    从表中删除第i个元素，通过参数x返回删除的元素值
    函数返回删除成功的信息
    若删除成功则返回true
    否则返回false
*/
template<typename T>
bool SeqList<T>::Remove(int i, T& x)
{
    if (last == -1) return false;   //表空 不能删除
    if (i < 1 || i > last + 1) return false;    //位置不合理
    x = data[i - 1];
    for (int j = i;j <= last; j++)
        data[j - 1] = data[j];
    last--;
    return true;
}

/*
    输入函数
    通过标准输入逐个数据输入 建立顺序表
*/
template<typename T>
void SeqList<T>::input()
{
    cout << "开始建立顺序表，请输入表中元素个数：";
    while(1)
    {
        cin >> last;        // 输入元素最后位置
        if (last <= maxSize - 1) break;
        cout << "表元素个数输入有误，范围不得超过" << maxSize - 1 << ":";
    }
    for(int i = 0; i <= last; i++)
    {
        cin >> data[i];
        cout << i + 1 << endl;
    }
}

// 输出看书
template<typename T>
void SeqList<T>::output()
{
    cout << "顺序表当前元素最后位置为：" << last << endl;
    for(int i = 0; i <= last; i++)
    {
        cout << "#" << i + 1 << ":" <<data[i] << endl;
    }
}

// 重载
// 整体赋值
template<typename T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
    this->maxSize = L.Size(); //赋值最大长度
    this->last = L.Length() - 1; //当前表长
    T value;
    this->data = new T[maxSize];  //分配内存
    if(this->data == NULL)
    {
        cerr << "存储分配错误！" << endl;
        exit(1);
    }
    for(int i = 1; i < last + 1; i++)
    {
        L.getData(i, value); //将第i个元素的值赋值给value
        this->data[i - 1] = value; //赋值给data
    }
    return *this;
}

