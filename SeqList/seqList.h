#include<iostream>
#include<cstdlib>
#include "linearList.h"
using namespace std;
const int defaultSize = 100;
template <typename T>
class SeqList:public LinearList<T>
{
protected:
    T *data;    //�������
    int maxSize;    //���������
    int last;   //��ǰ�Ѵ��������λ��
    void reSize(int newSize)
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
    };   //�ı�data����ռ��С
public:
    SeqList(int sz = defaultSize)
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
    };  //���캯��
    SeqList(SeqList<T>& L)
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
        for(int i = 1; i <= last + 1; i++)
        {
            L.getData(i, value); //����i��Ԫ�ص�ֵ��ֵ��value
            data[i - 1] = value; //��ֵ��data
        }
    }; //���ƹ��캯��
    ~SeqList(){delete[] data;} //��������
    int Size() const {return maxSize;}  //������������
    int Length() const {return last + 1;}   //��ǰ����
    int Search(T& x) const
    {
        for (int i = 0; i <= last; i++)
            if (data[i] == x)
                return i + 1; //˳������
        return 0;
    }; //����x�ڱ���λ�ã����ر������
    int Locate(int i) const
    {
        if (i >= 1 && i <= last + 1) return i;
        return 0;
    };    //��λ��i��Ԫ�أ����ر������
    bool getData(int i, T &x) const
    {
        if (i > 0 && i <= last + 1)
        {
            x = data[i - 1];
            return true;
        }
        return false;
    };    //ȡ��i������
    bool setData(int i, T &x)
    {
        if (i > 0 && i < last + 1)
        {
            data[i - 1] = x;
            return true;
        }
        return false;
    };  //��x�޸ĵ�i�������ֵ
    bool Insert(int i, T &x)
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
    };   //�ڵ�i��Ԫ��ǰ����x
    bool Remove(int i, T &x)
    {
        if (last == -1) return false;   //��� ����ɾ��
        if (i < 1 || i > last + 1) return false;    //λ�ò�����
        x = data[i - 1];
        for (int j = i;j <= last; j++)
            data[j - 1] = data[j];
        last--;
        return true;
    };   //ɾ����i�����ͨ��x���ر����ֵ
    bool IsEmpty() const {return last == -1 ? true : false;} //�жϱ��
    bool IsFull() const {return last == maxSize - 1 ? true : false;}  //�жϱ���
    void input()
    {
        cout << "��ʼ����˳������������Ԫ�ظ�����";
        int total;
        while(1)
        {
            cin >> total;        // ����Ԫ�����λ��
            if (total <= maxSize ) break;
            cout << "��Ԫ�ظ����������󣬷�Χ���ó���" << maxSize  << ":";
        }
        for(int i = 0; i < total; i++)
        {
            cin >> data[i];
            cout << i + 1 << endl;
        }
        last = total - 1;
    };   //����
    void output()
    {
        cout << "˳���ǰԪ�����λ��Ϊ��" << last + 1 << endl;
        for(int i = 0; i <= last; i++)
        {
            cout << "#" << i + 1 << ":" <<data[i] << endl;
        }
    };  //���
    SeqList<T> operator = (SeqList<T>& L)
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
    };  //�����帳ֵ
};





