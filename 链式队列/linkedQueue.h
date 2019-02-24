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

//�ͷ����н��

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

//��ջ
template<class T>
bool LinkedQueue<T>::enQueue(const T& x)
{
    //�ն���ʱ ���Ƕ�ͷҲ�Ƕ�β
    if (front == NULL)
    {
        front = rear = new LinkNode<T>(x);
        if(front == NULL) return false; //������ʧ��
    }
    // �ǿն��� �����β rearָ����Ԫ��
    else
    {
        rear->link = new LinkNode<T>(x);
        if (rear->link == NULL) return false; //����ʧ��
        rear = rear->link;  //��β����
    }
}

// ��ջ
template<class T>
bool LinkedQueue<T>::deQueue(T &x)
{
    //�ն��� ʧ��
    if (isEmpty() == true) return false;
    //ȡ������Ԫ��
    LinkNode<T>* p = front;
    x = p->data;
    front = front->link;
    delete p;
    return true;
}

//ȡ������Ԫ�ص�ֵ
template<class T>
bool LinkedQueue<T>::getFront(T& x)
{
    if(isEmpty() == true) return false;
    x = front->data;
    return true;
}

// ��ȡ����
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

// ����
template<class T>
std::ostream& operator<<(std::ostream& os, LinkedQueue<T>& L)
{
    os << "�����е�Ԫ����" << L.getSize() << "��" << std::endl;
    LinkNode<T>* p = L.front;
    int i = 0;
    while(p != NULL)
    {
        os << ++i << ": " << p->data << std::endl;
        p = p->link;
    }
    return os;
}
