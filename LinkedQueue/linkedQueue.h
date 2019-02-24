#include <iostream>
#include "linkNode.h"
#include "queue.h"

template<class T>
class LinkedQueue;

template<class T>
std::ostream& operator<<(std::ostream& os, LinkedQueue<T>& L);

template<class T>
class LinkedQueue : public Queue<T>
{
private:
    LinkNode<T>* front, * rear;
public:
    LinkedQueue():rear(NULL), front(NULL){}
    ~LinkedQueue(){makeEmpty();}
    void makeEmpty();
    bool enQueue(const T& x);
    bool deQueue(T& x);
    bool getFront(T& x);
    bool isEmpty() const {return (front == NULL) ? true : false;}
    bool isFull() const {return false;}
    int getSize() const;
    friend std::ostream& operator<<<>(std::ostream& os, LinkedQueue& L);
};

//释放所有结点

template<class T>
void LinkedQueue<T>::makeEmpty()
{
    LinkNode<T>* p;
    while(front != NULL)
    {
        p = front;
        front = front->link;
        delete p;
    }
}

//进栈
template<class T>
bool LinkedQueue<T>::enQueue(const T& x)
{
    //空队列时 既是队头也是队尾
    if (front == NULL)
    {
        front = rear = new LinkNode<T>(x);
        if(front == NULL) return false; //分配结点失败
    }
    // 非空队列 加入队尾 rear指向新元素
    else
    {
        rear->link = new LinkNode<T>(x);
        if (rear->link == NULL) return false; //分配失败
        rear = rear->link;  //队尾后移
    }
}

// 出栈
template<class T>
bool LinkedQueue<T>::deQueue(T &x)
{
    //空队列 失败
    if (isEmpty() == true) return false;
    //取出队首元素
    LinkNode<T>* p = front;
    x = p->data;
    front = front->link;
    delete p;
    return true;
}

//取出队首元素的值
template<class T>
bool LinkedQueue<T>::getFront(T& x)
{
    if(isEmpty() == true) return false;
    x = front->data;
    return true;
}

// 获取长度
template<class T>
int LinkedQueue<T>::getSize() const
{
    LinkNode<T>* p = front;
    int num = 0;
    while(p != NULL)
    {
        p = p->link;
        num++;
    }
    return num;
}

// 重载
template<class T>
std::ostream& operator<<(std::ostream& os, LinkedQueue<T>& L)
{
    os << "队列中的元素有" << L.getSize() << "个" << std::endl;
    LinkNode<T>* p = L.front;
    int i = 0;
    while(p != NULL)
    {
        os << ++i << ": " << p->data << std::endl;
        p = p->link;
    }
    return os;
}
