#include<iostream>
#include<cstdlib>
#include "linkNode.h"

using namespace std;

// ������(��ͷ�ڵ�)
template <typename T>
class LinkList
{
private:
    LinkNode<T>* first; //����ͷָ��
public:
    LinkList(){first = new LinkNode<T>;}    //�չ��캯��
    LinkList(const T& x) {first = new LinkNode<T>(x);}  // ָ����ʼ�ڵ�Ĺ��캯��
    LinkList(LinkList<T>& L);   //���ƹ��캯��
    ~LinkList(){makeEmpty();}   // ��������
    void makeEmpty();      //��������Ϊ�ձ�
    int Length() const;     //������
    LinkNode<T> *getHead() const { return first; }  //��ȡͷ�ڵ�
    LinkNode<T> *Search(T x);   //����������x��Ԫ��
    LinkNode<T> *Locate(int i) const; //������i��Ԫ�صĵ�ַ
    bool getData(int i,T& x) const; //ȡ����i��Ԫ�ص�ֵ
    void setData(int i, T& x);  // �޸ĵ�i��Ԫ�ص�ֵΪx
    bool Insert(int i,T& x);    //�ڵ�i��Ԫ�غ����x
    bool Remove(int i, T& x);   //ɾ����i��Ԫ�أ���ͨ��x���ظ�Ԫ�ص�ֵ
    bool IsEmpty() {return first->link == NULL ? true : false;} //�жϱ��
    bool IsFull() {return false;} //�жϱ��� ������û�г�������
    // void Sort();    //����
    void input();   //����
    void output();  //���
    LinkList<T>& operator = (LinkList<T>& L); //���غ��� ��ֵ
};

/*
    ���ƹ��캯��
*/
template<typename T>
LinkList<T>::LinkList(LinkList<T>& L)
{
    T value;
    LinkNode<T>* srcptr = L.getHead();  //��ȡ�����ƽ���ͷָ��
    LinkNode<T>* destptr = first = new LinkNode<T>; //����һ����ǰ����ͷ���ָ��
    while(srcptr->link != NULL)
    {
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value); //���Ƶ�ǰ��������
        destptr = destptr->link;    //��ǰָ��ǰ��
        srcptr = srcptr->link;      //�����ƽ��ָ��ǰ��
    }
    destptr->link = NULL;   //���һ����������Ϊ��
}

/*
    ��������Ϊ�ձ�
*/
template<typename T>
void LinkList<T>::makeEmpty()
{
    LinkNode<T>* q;

    // ���ɾ��
    while(first->link != NULL)
    {
        q = first->link;
        first->link = q->link;
        delete q;
    }
}

/*
    ��������
*/
template<typename T>
int LinkList<T>::Length() const
{
    LinkNode<T>* p = first->link;
    int count = 0;
    while(p != NULL){
        p = p->link;
        count++;
    }
    return count;
}

/*
    ��������x�Ľ���ַ��û�ѵ��ͷ���NULL
*/
template<typename T>
LinkNode<T>* LinkList<T>::Search(T x)
{
    LinkNode<T>* current = first->link;
    while(current != NULL)
    {
        if(current->data == x) break;
        else current = current->link;
    }
    return current;
}

/*
    ������i��Ԫ�صĵ�ַ
*/
template<typename T>
LinkNode<T>* LinkList<T>::Locate(int i) const
{
    if(i < 0) return NULL;
    LinkNode<T>* current = first->link;
    int k = 0;
    while(current != NULL && k < i)
    {
        current = current->link;
        k++;
    }
    return current;
}

/*
    ȡ��i��Ԫ�ص�ֵ
    ͨ��x��ֵ����
*/
template<typename T>
bool LinkList<T>::getData(int i,T& x) const
{
    if (i <= 0) return NULL;
    LinkNode<T>* current = Locate(i);
    if (current == NULL) return false;
    else
    {
        x = current->data;
        return true;
    }
}

/*
    �޸ĵ�i��λ�õ�ֵ
*/
template<typename T>
void LinkList<T>::setData(int i, T& x)
{
    if(i <= 0) return;
    LinkNode<T>* current = Locate(i);
    if (current != NULL)
    {
        current->data = x;
    }
    return;
}

/*
    �ڵ�i��Ԫ��֮�����x
*/
template<typename T>
bool LinkList<T>::Insert(int i,T& x)
{
    LinkNode<T>* current = Locate(i);
    if (current == NULL) return false;
    LinkNode<T>* newNode = new LinkNode<T>(x);
    if (newNode == NULL) { cerr << "�����ڴ����" << endl; exit(1);}
    newNode->link = current->link;
    current->link = newNode;
    return true;
}

/*
    ɾ����i��Ԫ��
    ͨ��x���ظ�Ԫ��
*/
template<typename T>
bool LinkList<T>::Remove(int i, T& x)
{
    LinkNode<T>* current = Locate(i - 1);
    if (current == NULL || current->link == NULL) return false;
    LinkNode<T>* del = current->link;
    current->link = del->link;
    x = del->data;
    delete del;
    return true;
}

/*
    ���뺯��
    ���ַ�����ǰ�巨  ��巨
*/
template<typename T>
void LinkList<T>::input()
{
    T endTag;
    cout << "�����������־��";
    cin >> endTag;
    cout << "�뿪ʼ�������ݣ�" << endl;

    // ǰ�巨��������
    LinkNode<T>* newNode;
    T value;
    makeEmpty();
    cin >> value;
    while(value != endTag)
    {
        newNode = new LinkNode<T>(value);
        if (newNode == NULL) { cerr << "�洢�������" << endl; exit(1); }
        newNode->link = first->link;
        first->link = newNode;
        cin >> value;
    }
}

/*
    �������
*/
template<typename T>
void LinkList<T>::output()
{
    LinkNode<T>* current = first->link;
    cout << "��ǰ�������ݣ�";
    while(current != NULL)
    {
        cout<< current->data << "  ";
        current = current->link;
    }
    cout << endl;
}

/*
    ���غ���
*/
template<typename T>
LinkList<T>& LinkList<T>::operator=(LinkList<T>& L)
{
    T value;
    LinkNode<T>* srcptr = L.getHead();
    LinkNode<T>* destptr = first = new LinkNode<T>;
    while(srcptr->link != NULL)
    {
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        destptr = destptr->link;
        srcptr = srcptr->link;
    }
    destptr->link = NULL;
    return *this;
}




