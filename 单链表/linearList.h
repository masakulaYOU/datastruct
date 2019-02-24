#include <iostream>
#include <cstdlib>

//���Ա�
//enum bool{true, false};
template <typename T>
class LinearList
{
public:
    //LinearList();   //���캯��
    //~LinearList();  //��������
    virtual int Size() const = 0;   //������ἰ
    virtual int Length() const = 0; //��ǰ����
    virtual int Search(T &x) const = 0; //��������ֵx
    virtual int Locate(int i) const = 0;    //�ڱ��ж�λ��i��Ԫ��
    virtual bool getData(int i, T &x) const = 0;    //ȡ���е�i��Ԫ�ص�ֵ
    virtual void setData(int i, T &x) = 0;    //�޸ı��е�i��Ԫ�ص�ֵ
    virtual bool Insert(int i, T &x) = 0;   //�ڵ�i��Ԫ�غ����x
    virtual bool Remove(int i, T &x) = 0;   //ɾ����i������
    virtual bool IsEmpty() const = 0;   //���Ƿ�Ϊ��
    virtual bool IsFull() const = 0;    //���Ƿ�Ϊ��
    //virtual void Sort() = 0;    //������
    virtual void input() = 0;   //����
    virtual void output() = 0;  //���
    //virtual LinearList<T> operator=(LinearList<T> &L) = 0;  //����
};
