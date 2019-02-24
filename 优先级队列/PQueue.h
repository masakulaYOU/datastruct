#include <iostream>
#include <cassert>

const int defaultPQSize = 50;

template<class T>
class PQueue
{
private:
    T* pqelements;  //����
    int count;      //��ǰԪ�ظ���
    int maxSize;    //����
    void adjust();  //���е���
public:
    PQueue(int sz = defaultPQSize);
    ~PQueue(){delete[] pqelements;}
    bool Insert(const T& x);
    bool RemoveMin(T& x);   //ɾ����ͷԪ��
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

// ��������
// ����βԪ�ذ�������Ȩ��С�������ʵ�λ��
// ��������Ԫ�ذ�����Ȩ��С��������
template<class T>
void PQueue<T>::adjust()
{
    T temp = pqelements[count - 1]; //��βԪ��
    int j;
    for(j = count - 2; j >= 0; j--)
    {
        if(pqelements[j] <= temp) break; //���һ��Ԫ�رȵ����ڶ���Ԫ�ش�  ����ѭ��
        else pqelements[j + 1] = pqelements[j]; //�����

        pqelements[j] = temp;   //���뵽��ǰλ��
    }
}

// �����β
// Ȼ����е���
template<class T>
bool PQueue<T>::Insert(const T& x)
{
    if(isFull() == true) return false;
    pqelements[count++] = x;
    adjust();
    return true;
}

//ɾ�����ȼ�����Ԫ�أ�������Ԫ�أ�
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

