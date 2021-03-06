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
    void CreateBinTree(std::istream& in, BinTreeNode<T>*& subTree, T refValue); // 创建树
    void CreateBinNode(std::istream& in, BinTreeNode<T>*& subTree, T refValue, int type); // 创建结点
    void Traverse(BinTreeNode<T>* subTree, std::ostream& os);   //前序遍历输出
    void destory(BinTreeNode<T>*& subTree); // 删除
    bool isEmpty(){ return (root == NULL) ? true : false; } //判树空
    int Height(BinTreeNode<T>* subTree) const;  // 返回树高度
    int Size(BinTreeNode<T>* subTree) const;    //结点总数
    void preOrder(void (* visit)(BinTreeNode<T>* p))
        { preOrder(root, visit); }   //前序遍历
    void inOrder(void (* visit)(BinTreeNode<T>* p))
        { inOrder(root, visit); }   // 中序遍历
    void postOrder(void (* visit)(BinTreeNode<T>* p))
        { postOrder(root, visit); }
    friend std::istream& operator >> <> (std::istream& in, BinaryTree& Tree);
    friend std::ostream& operator << <> (std::ostream& os, BinaryTree& Tree);
public:
    BinaryTree() : root(NULL){}
    BinaryTree(T value): RefValue(value), root(NULL){}
    //BinaryTree(BinaryTree<T>& s);   // 复制构造函数
    ~BinaryTree(){destory(root);}   // 析构函数
    int height() const { return Height(root);}
    int size() const {return Size(root);}
    void preOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p));   // 前序遍历
    void inOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p));   // 中序遍历
    void postOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p)); // 后序遍历
};

// 复制构造函数
//template <class T>
//BinaryTree<T>::BinaryTree(BinaryTree<T>& s)
//{

//}

// 删除
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
    前序遍历输出
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
    os << "二叉树的前序遍历：" << std::endl;
    Tree.Traverse(Tree.root, os);
    return os;
}

template <class T>
void BinaryTree<T>::CreateBinTree(std::istream& in, BinTreeNode<T>*& subTree, T refValue)
{
    BinTreeNode<T>* p;
    T x;
    std::cout << "请输入根节点:" << std::endl;
    in >> x;    //输入
    if(x == refValue) return; //结束标记
    p = new BinTreeNode<T>;
    p->data = x;
    p->leftChild = NULL;
    p->rightChild = NULL;
    subTree = p;    // 修改根节点的值
    CreateBinNode(in,subTree,refValue,1);
    CreateBinNode(in,subTree,refValue,2);

    return;
}

template <class T>
void BinaryTree<T>::CreateBinNode(std::istream& in, BinTreeNode<T>*& subTree, T refValue, int type)
{
    BinTreeNode<T>* p;
    T x;
    std::cout << "输入各节点值（" << refValue << "为结束标志）:" << std::endl;
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

// 求树的高度
template <class T>
int BinaryTree<T>::Height(BinTreeNode<T>* subTree) const
{
    if(subTree == NULL) return 0;
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return (i < j) ? j + 1 : i + 1;
}



// 前序遍历
template <class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p))
{
    if(subTree != NULL)
    {
        visit(subTree);
        preOrder(subTree->leftChild, visit);
        preOrder(subTree->rightChild, visit);
    }
}

// 中序遍历

template <class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p))
{
    if(subTree != NULL)
    {
        inOrder(subTree->leftChild, visit);
        visit(subTree);
        inOrder(subTree->rightChild, visit);
    }
}

// 后续遍历
template <class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>& subTree, void (* visit)(BinTreeNode<T>* p))
{
    if (subTree != NULL)
    {
        postOrder(subTree->leftChild, visit);
        postOrder(subTree->rightChild, visit);
        visit(subTree);
    }
}

// 求结点总数
template <class T>
int BinaryTree<T>::Size(BinTreeNode<T>* subTree) const
{
    if(subTree == NULL) return 0;
    return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}







