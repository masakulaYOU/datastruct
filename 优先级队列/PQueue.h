#include <iostream>
#include <cassert>

const int defaultPQSize = 50;

template<class T>
class PQueue
{
private:
    T* pqelements;  //数组
    int count;      //当前元素个数
    int maxSize;    //容量
    void adjust();  //队列调整
public:
    PQueue(int sz = defaultPQSize);
    ~PQueue(){delete[] pqelements;}
    bool Insert(const T& x);
    bool RemoveMin(T& x);   //删除队头元素
    bool getFront(T& x) const;
    void makeEmpty() {count = 0;}
    bool isEmpty() const {return (count == 0) ? true : false;}
    bool isFull() const {return (count == maxSize) ? true : false;}
    int getSize() const { return count; }
} ;


template<class T>
PQueue<T>::PQueue(int sz):maxSize(sz), count(0)
{
    pqelements = new T[maxSize];
    assert(pqelements != NULL);
}

// 调整队列
// 将对尾元素按其优先权大小调整到适当位置
// 保持所有元素按优先权从小到大排列
template<class T>
void PQueue<T>::adjust()
{
    T temp = pqelements[count - 1]; //对尾元素
    int j;
    for(j = count - 2; j >= 0; j--)
    {
        if(pqelements[j] <= temp) break; //最后一个元素比倒数第二个元素大  跳出循环
        else pqelements[j + 1] = pqelements[j]; //往后调

        pqelements[j] = temp;   //插入到当前位置
    }
}

// 插入队尾
// 然后进行调整
template<class T>
bool PQueue<T>::Insert(const T& x)
{
    if(isFull() == true) return false;
    pqelements[count++] = x;
    adjust();
    return true;
}

//删除优先级最大的元素（即队首元素）
template<class T>
bool PQueue<T>::RemoveMin(T& x)
{
    if(isEmpty() == true) return false;
    x = pqelements[0];
    for(int i = 0; i < count; i++)
    {
        pqelements[i - 1] = pqelements[i];
    }
    count--;
    return true;
}

//
template<class T>
bool PQueue<T>::getFront(T& x)
{

}

