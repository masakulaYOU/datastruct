#include <iostream>
#include "BinTreeNode.h"
#include "Stack.h"

template <class T>
class BinaryTree;

template <class T>
std::ostream& operator << (std::ostream& os, BinaryTree<T>& Tree);

template <class T>
std::istream& operator >> (std::istream& in, BinaryTree<T>& Tree);

template <class T>
class BinaryTree
{
protected:
    BinTreeNode<T>* root;
    T RefValue;
    void CreateBinTree(std::istream& in, BinTreeNode<T>*& subTree, T refValue); // ������
    void CreateBinNode(std::istream& in, BinTreeNode<T>*& subTree, T refValue, int type); // �������
    void Traverse(BinTreeNode<T>* subTree, std::ostream& os);   //ǰ��������
    void destory(BinTreeNode<T>*& subTree); // ɾ��
    bool isEmpty(){ return (root == NULL) ? true : false; } //������
    int Height() { return Height(root);}
    friend std::istream& operator >> <> (std::istream& in, BinaryTree& Tree);
    friend std::ostream& operator << <> (std::ostream& os, BinaryTree& Tree);
public:
    BinaryTree() : root(NULL){}
    BinaryTree(T value): RefValue(value), root(NULL){}
    //BinaryTree(BinaryTree<T>& s);   // ���ƹ��캯��
    ~BinaryTree(){destory(root);}   // ��������
    //int Height(BinTreeNode<T>*& subTree);  // �������߶�
};

// ���ƹ��캯��
//template <class T>
//BinaryTree<T>::BinaryTree(BinaryTree<T>& s)
//{

//}

// ɾ��
template <class T>
void BinaryTree<T>::destory(BinTreeNode<T>*& subTree)
{
    if(subTree != NULL)
    {
        destory(subTree->leftChild);
        destory(subTree->rightChild);
        delete subTree;
    }
}


/*
    ǰ��������
*/
template <class T>
void BinaryTree<T>::Traverse(BinTreeNode<T>* subTree, std::ostream& os)
{
    if(subTree != NULL)
    {
        os << subTree->data << ' ';
        Traverse(subTree->leftChild, os);
        Traverse(subTree->rightChild, os);
    }
}

template <class T>
std::istream& operator >> (std::istream& in, BinaryTree<T>& Tree)
{
    Tree.CreateBinTree(in, Tree.root, Tree.RefValue);
    return in;
}

template <class T>
std::ostream& operator << (std::ostream& os, BinaryTree<T>& Tree)
{
    os << "��������ǰ�������" << std::endl;
    Tree.Traverse(Tree.root, os);
    return os;
}

template <class T>
void BinaryTree<T>::CreateBinTree(std::istream& in, BinTreeNode<T>*& subTree, T refValue)
{
    BinTreeNode<T>* p;
    T x;
    std::cout << "��������ڵ�:" << std::endl;
    in >> x;    //����
    if(x == refValue) return; //�������
    p = new BinTreeNode<T>;
    p->data = x;
    p->leftChild = NULL;
    p->rightChild = NULL;
    subTree = p;    // �޸ĸ��ڵ��ֵ
    CreateBinNode(in,subTree,refValue,1);
    CreateBinNode(in,subTree,refValue,2);

    return;
}

template <class T>
void BinaryTree<T>::CreateBinNode(std::istream& in, BinTreeNode<T>*& subTree, T refValue, int type)
{
    BinTreeNode<T>* p;
    T x;
    std::cout << "������ڵ�ֵ��" << refValue << "Ϊ������־��:" << std::endl;
    in >> x;
    if(x != refValue)
    {
        p = new BinTreeNode<T>;
        p->data = x;
        p->leftChild = NULL;
        p->rightChild = NULL;
        if(type == 1) subTree->leftChild = p;
        if(type == 2) subTree->rightChild = p;
        CreateBinNode(in, p, refValue, 1);
        CreateBinNode(in, p, refValue, 2);
    }
    return;
}
/*
// �����ĸ߶�
template <class T>
int BinaryTree<T>::Height(BinTreeNode<T>*& subTree)
{
    int depth = 0;  // ��ǰ���

}
*/










