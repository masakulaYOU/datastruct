#include <iostream>
/*
// 模板声明
template <class T>
class DataList;

template <class T>
DataList<T> operator+(DataList<T>& left, DataList<T>& right);
*/
template <class T>
class DataList
{
private:
    int maxSize;    // 有序表容量
    int currentSize;// 当前容量
    T* data;           // 有序表存储空间首地址
public:
    DataList():maxSize(0), currentSize(0){}
    DataList(int sz):maxSize(sz), currentSize(0){ data = new T[maxSize];}
    int searchList(T x);    // 顺序表查找
    bool insertList(T x);    // 顺序表插入
    bool deleteList(T x);    // 顺序表删除
    void output();          // 输出
    DataList<T> operator+(DataList<T>& x); //有序表合并
};

// 对分查找
template <class T>
int DataList<T>::searchList(T x)
{
    int i = 1, j = currentSize, k;
    while(i <= j)
    {
        k = (i + j) / 2;    //中间元素下标
        if (data[k - 1] == x) return (k - 1);   //找到返回
        if (data[k - 1] >  x) j = k - 1;        //比指定值大，取前半部
        if (data[k - 1] <  x) i = k + 1;        //比指定值小，取后半部
    }
    return -1;  // 找不到，返回-1
}

// 插入
template <class T>
bool DataList<T>::insertList(T x)
{
    int k;
    if (currentSize == maxSize) return false;  // 表满，不能插入
    k = currentSize - 1;
    while(data[k] > x) //从最后一个元素开始查找
    {
        // 后移
        data[k + 1] = data[k];
        k--;
    }
    data[k + 1] = x;
    currentSize++;
    return true;
}

// 删除
template <class T>
bool DataList<T>::deleteList(T x)
{
    int i, k;
    k = searchList(x);  //查找被删除位置的位置
    if (k == -1) return false;   // 查找失败

    for(i = k; i < currentSize - 1; i++)
        data[i] = data[i + 1];  //后移
    currentSize--;
    return true;
}

// 输出
template <class T>
void DataList<T>::output()
{
    int i;
    std::cout << "total lenth: " << currentSize << std::endl;
    for(i = 0; i < currentSize; i++)
        std::cout << data[i] << "\t";
    std::cout << std::endl;
    return;
}

// 有序表合并
template <class T>
DataList<T> DataList<T>::operator+(DataList<T>& x)
{
    int k = 0, i = 0, j = 0;
    DataList<T> result;
    result.data = new T[currentSize + x.currentSize];
    while(i < currentSize && j < x.currentSize)
    {
        if(data[i] <= x.data[j])    //一个一个比较着插入
        {
            // 左边的小于等于右边
            result.data[k] = data[i];
            i++;
        }
        else
        {
            // 左边的大于右边的
            result.data[k] = x.data[j];
            j++;
        }
        k++;
    }

    if (i < currentSize) // 左边的没复制完
        for(; i < currentSize;i++,k++)
            result.data[k] = data[i];
    else   //右边的没有复制完
        for(; j < x.currentSize;j++,k++)
            result.data[k] = x.data[j];

    result.maxSize = maxSize + x.maxSize;
    result.currentSize = currentSize + x.currentSize;

    return result;
}

