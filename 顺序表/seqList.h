#include<iostream>
#include<cstdlib>
#include "linearList.h"
using namespace std;
const int defaultSize = 100;
template <typename T>
class SeqList:public LinearList<T>
{
protected:
    T *data;    //存放数组
    int maxSize;    //最大容纳量
    int last;   //当前已存表项的最后位置
    void reSize(int newSize)
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
    };   //改变data数组空间大小
public:
    SeqList(int sz = defaultSize)
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
    };  //构造函数
    SeqList(SeqList<T>& L)
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
        for(int i = 1; i <= last + 1; i++)
        {
            L.getData(i, value); //将第i个元素的值赋值给value
            data[i - 1] = value; //赋值给data
        }
    }; //复制构造函数
    ~SeqList(){delete[] data;} //析构函数
    int Size() const {return maxSize;}  //表最大可容纳量
    int Length() const {return last + 1;}   //当前表长度
    int Search(T& x) const
    {
        for (int i = 0; i <= last; i++)
            if (data[i] == x)
                return i + 1; //顺序搜索
        return 0;
    }; //搜索x在表中位置，返回表项序号
    int Locate(int i) const
    {
        if (i >= 1 && i <= last + 1) return i;
        return 0;
    };    //定位第i个元素，返回表项序号
    bool getData(int i, T &x) const
    {
        if (i > 0 && i <= last + 1)
        {
            x = data[i - 1];
            return true;
        }
        return false;
    };    //取第i个表项
    bool setData(int i, T &x)
    {
        if (i > 0 && i < last + 1)
        {
            data[i - 1] = x;
            return true;
        }
        return false;
    };  //用x修改第i个表项的值
    bool Insert(int i, T &x)
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
    };   //在第i个元素前插入x
    bool Remove(int i, T &x)
    {
        if (last == -1) return false;   //表空 不能删除
        if (i < 1 || i > last + 1) return false;    //位置不合理
        x = data[i - 1];
        for (int j = i;j <= last; j++)
            data[j - 1] = data[j];
        last--;
        return true;
    };   //删除第i个表项，通过x返回表项的值
    bool IsEmpty() const {return last == -1 ? true : false;} //判断表空
    bool IsFull() const {return last == maxSize - 1 ? true : false;}  //判断表满
    void input()
    {
        cout << "开始建立顺序表，请输入表中元素个数：";
        int total;
        while(1)
        {
            cin >> total;        // 输入元素最后位置
            if (total <= maxSize ) break;
            cout << "表元素个数输入有误，范围不得超过" << maxSize  << ":";
        }
        for(int i = 0; i < total; i++)
        {
            cin >> data[i];
            cout << i + 1 << endl;
        }
        last = total - 1;
    };   //输入
    void output()
    {
        cout << "顺序表当前元素最后位置为：" << last + 1 << endl;
        for(int i = 0; i <= last; i++)
        {
            cout << "#" << i + 1 << ":" <<data[i] << endl;
        }
    };  //输出
    SeqList<T> operator = (SeqList<T>& L)
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
    };  //表整体赋值
};





