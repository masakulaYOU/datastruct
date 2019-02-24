#include<iostream>
#include<cstdlib>
#include "linkNode.h"

using namespace std;

// 链表类(带头节点)
template <typename T>
class LinkList
{
private:
    LinkNode<T>* first; //链表头指针
public:
    LinkList(){first = new LinkNode<T>;}    //空构造函数
    LinkList(const T& x) {first = new LinkNode<T>(x);}  // 指定起始节点的构造函数
    LinkList(LinkList<T>& L);   //复制构造函数
    ~LinkList(){makeEmpty();}   // 析构函数
    void makeEmpty();      //将链表置为空表
    int Length() const;     //链表长度
    LinkNode<T> *getHead() const { return first; }  //获取头节点
    LinkNode<T> *Search(T x);   //搜索含有数x的元素
    LinkNode<T> *Locate(int i) const; //搜索第i个元素的地址
    bool getData(int i,T& x) const; //取出第i个元素的值
    void setData(int i, T& x);  // 修改第i个元素的值为x
    bool Insert(int i,T& x);    //在第i个元素后插入x
    bool Remove(int i, T& x);   //删除第i个元素，并通过x返回该元素的值
    bool IsEmpty() {return first->link == NULL ? true : false;} //判断表空
    bool IsFull() {return false;} //判断表满 单链表没有长度限制
    // void Sort();    //排序
    void input();   //输入
    void output();  //输出
    LinkList<T>& operator = (LinkList<T>& L); //重载函数 赋值
};

/*
    复制构造函数
*/
template<typename T>
LinkList<T>::LinkList(LinkList<T>& L)
{
    T value;
    LinkNode<T>* srcptr = L.getHead();  //获取被复制结点的头指针
    LinkNode<T>* destptr = first = new LinkNode<T>; //创建一个当前结点和头结点指针
    while(srcptr->link != NULL)
    {
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value); //复制当前结点的链接
        destptr = destptr->link;    //当前指针前移
        srcptr = srcptr->link;      //被复制结点指针前移
    }
    destptr->link = NULL;   //最后一个结点的链接为空
}

/*
    将链表置为空表
*/
template<typename T>
void LinkList<T>::makeEmpty()
{
    LinkNode<T>* q;

    // 逐个删除
    while(first->link != NULL)
    {
        q = first->link;
        first->link = q->link;
        delete q;
    }
}

/*
    求链表长度
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
    搜索含有x的结点地址，没搜到就返回NULL
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
    搜索第i个元素的地址
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
    取第i个元素的值
    通过x将值传出
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
    修改第i个位置的值
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
    在第i个元素之后插入x
*/
template<typename T>
bool LinkList<T>::Insert(int i,T& x)
{
    LinkNode<T>* current = Locate(i);
    if (current == NULL) return false;
    LinkNode<T>* newNode = new LinkNode<T>(x);
    if (newNode == NULL) { cerr << "分配内存错误！" << endl; exit(1);}
    newNode->link = current->link;
    current->link = newNode;
    return true;
}

/*
    删除第i个元素
    通过x返回该元素
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
    输入函数
    两种方法：前插法  后插法
*/
template<typename T>
void LinkList<T>::input()
{
    T endTag;
    cout << "请输入结束标志：";
    cin >> endTag;
    cout << "请开始输入数据：" << endl;

    // 前插法数据输入
    LinkNode<T>* newNode;
    T value;
    makeEmpty();
    cin >> value;
    while(value != endTag)
    {
        newNode = new LinkNode<T>(value);
        if (newNode == NULL) { cerr << "存储分配错误！" << endl; exit(1); }
        newNode->link = first->link;
        first->link = newNode;
        cin >> value;
    }
}

/*
    输出函数
*/
template<typename T>
void LinkList<T>::output()
{
    LinkNode<T>* current = first->link;
    cout << "当前链表数据：";
    while(current != NULL)
    {
        cout<< current->data << "  ";
        current = current->link;
    }
    cout << endl;
}

/*
    重载函数
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




