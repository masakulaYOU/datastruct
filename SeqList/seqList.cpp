#include<iostream>
#include<cstdlib>
#include "seqList.h"

using namespace std;

/*
    ���캯��
    ͨ��ָ������sz��������ĳ���
*/
template<typename T>
SeqList<T>::SeqList(int sz)
{
    if(sz > 0)
    {
        maxSize = sz;   //��ֵ�����󳤶�
        last = -1;      //��ĵ�ǰ����Ϊ��
        data = new T[maxSize];  //��������������
        if (data == NULL)
        {
            cerr << "�洢�������" << endl;
            exit(1);
        }
    }
}

/*
    ��ֵ���캯��
    �ò������и��������е�˳����ʼ���½���˳���
*/
template<typename T>
SeqList<T>::SeqList(SeqList<T> &L)
{
    maxSize = L.Size(); //��ֵ��󳤶�
    last = L.Length() - 1; //��ǰ��
    T value;
    data = new T[maxSize];  //�����ڴ�
    if(data == NULL)
    {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    for(int i = 1; i < last + 1; i++)
    {
        L.getData(i, value); //����i��Ԫ�ص�ֵ��ֵ��value
        data[i - 1] = value; //��ֵ��data
    }
}

/*
    ˽�к���
    ����˳���Ĵ洢����ռ��С
    �������Ԫ�ظ���ΪnewSize
*/
template<typename T>
void SeqList<T>::reSize(int newSize)
{
    if (newSize < 0)
    {
        cerr << "��Ч�������С��" << endl;
        exit(1);
    }
    if (newSize != maxSize)
    {
        T* newArray = new T[newSize];   //����������
        if (newArray == NULL)
        {
            cerr << "�洢�������" << endl;
            exit(1);
        }
        int n = last + 1;
        T* srcptr = data;   //ԭ�����׵�ַ
        T* destptr = newArray;  //��������׵�ַ
        while(n--)
            *destptr++ = *srcptr++; //ѭ����ֵ����
        delete[] data;  //ɾ��ԭ����
        data = newArray;//����������
        maxSize = newSize;  //�޸����������
    }
}

/*
    ��������
    �ڱ���˳�����������ֵxƥ��ı���
    �ҵ��������ظñ����ǵڼ���Ԫ��
    ����������0
*/
template<typename T>
int SeqList<T>::Search(T &x) const
{
    for (int i = 0; i <= last; i++)
        if (data[i] == x)
            return i + 1; //˳������
    return 0;
}

/*
    ��λ����
    �������ص�i�������λ�� 1<= i <= last + 1
    ���򷵻�0 ��λʧ��
*/
template<typename T>
int SeqList<T>::Locate(int i) const
{
    if (i >= 1 && i <= last + 1) return i;
    return 0;
}

/*
    ȡֵ����
    ȡ��i��Ԫ�أ���ֵͨ��x����
    �����Ƿ񴫵ݳɹ�
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
    �޸ĵ�i��Ԫ�ص�ֵ
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
    ���뺯��
    ����Ԫ��x���뵽��i��Ԫ��֮��
    �������ز���ɹ�����Ϣ
    ������ɹ����򷵻�true
    ���򷵻�false
    i = 0���ǽ�x�����һ��Ԫ��λ��
*/
template<typename T>
bool SeqList<T>::Insert(int i, T& x)
{
    if (last == maxSize - 1) return false;  //���������ܲ���
    if (i < 0 || i > last + 1) return false;    //����λ�ò�����
    for (int j = last; j >= i; j--)
    {
        data[j + 1] = data[j];  //���κ��ƣ��ճ���i��λ��
    }
    data[i] = x;    //��x��ֵ����i��Ԫ��
    last++;         //���λ��+1
    return true;
}

/*
    �Ƴ�����
    �ӱ���ɾ����i��Ԫ�أ�ͨ������x����ɾ����Ԫ��ֵ
    ��������ɾ���ɹ�����Ϣ
    ��ɾ���ɹ��򷵻�true
    ���򷵻�false
*/
template<typename T>
bool SeqList<T>::Remove(int i, T& x)
{
    if (last == -1) return false;   //��� ����ɾ��
    if (i < 1 || i > last + 1) return false;    //λ�ò�����
    x = data[i - 1];
    for (int j = i;j <= last; j++)
        data[j - 1] = data[j];
    last--;
    return true;
}

/*
    ���뺯��
    ͨ����׼��������������� ����˳���
*/
template<typename T>
void SeqList<T>::input()
{
    cout << "��ʼ����˳������������Ԫ�ظ�����";
    while(1)
    {
        cin >> last;        // ����Ԫ�����λ��
        if (last <= maxSize - 1) break;
        cout << "��Ԫ�ظ����������󣬷�Χ���ó���" << maxSize - 1 << ":";
    }
    for(int i = 0; i <= last; i++)
    {
        cin >> data[i];
        cout << i + 1 << endl;
    }
}

// �������
template<typename T>
void SeqList<T>::output()
{
    cout << "˳���ǰԪ�����λ��Ϊ��" << last << endl;
    for(int i = 0; i <= last; i++)
    {
        cout << "#" << i + 1 << ":" <<data[i] << endl;
    }
}

// ����
// ���帳ֵ
template<typename T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
    this->maxSize = L.Size(); //��ֵ��󳤶�
    this->last = L.Length() - 1; //��ǰ��
    T value;
    this->data = new T[maxSize];  //�����ڴ�
    if(this->data == NULL)
    {
        cerr << "�洢�������" << endl;
        exit(1);
    }
    for(int i = 1; i < last + 1; i++)
    {
        L.getData(i, value); //����i��Ԫ�ص�ֵ��ֵ��value
        this->data[i - 1] = value; //��ֵ��data
    }
    return *this;
}

