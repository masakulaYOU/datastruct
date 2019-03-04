#include <iostream>
template <class T>
struct BSnode;

template <class T>
static void inOrders(BSnode<T>* p);
// 二叉排序树结点类型
template <class T>
struct BSnode
{
    T data;             // 数据域
    BSnode<T>* lchild;  // 左指针域
    BSnode<T>* rchild;  // 右指针域
};

// 二叉排序树类
template <class T>
class BinarySortTree
{
private:
    BSnode<T>* root;    // 根节点指针
public:
    BinarySortTree() : root(NULL) {}
    void insertNode(T); // 插入
    int deleteNode(T);  // 删除
    BSnode<T>* searchNode(T);   // 查找
    void inOrder();  // 中序遍历
};



// 中序遍历
template <class T>
void BinarySortTree<T>::inOrder()
{
    BSnode<T>* p;
    p = root;
    inOrders(p);
}

template <class T>
static void inOrders(BSnode<T>* p)
{
    if (p != NULL)
    {
        inOrders(p->lchild);
        std::cout << p->data << std::endl;
        inOrders(p->rchild);
    }
}

// 插入
template <class T>
void BinarySortTree<T>::insertNode(T x)
{
    BSnode<T> *p, *q;
    p = new BSnode<T>;  // 申请新节点
    p->data = x;
    p->lchild = NULL;   p->rchild = NULL;

    q = root;   // 从根节点开始查找
    if(q == NULL) root = p; // 根节点为空
    else
    {
        while(q->lchild != p && q->rchild != p) // 未找到叶子节点
        {
            if (x < q->data)    // 插入到左子树
            {
                if (q->lchild != NULL) q = q->lchild;
                else q->lchild = p;
            }
            else
            {
                if (q->rchild != NULL) q = q->rchild;
                else q->rchild = p;
            }
        }
    }
}

// 搜索
template <class T>
BSnode<T>* BinarySortTree<T>::searchNode(T x)
{
    BSnode<T>* p = NULL;
    p = root;
    int flag = 0;
    while(p != NULL && flag == 0)
    {
        if (p->data == x) flag = 1;    // 找到了  做一下标记
        else if (p->data > x) p = p->lchild;    // 查找值比根节点小，去找左子树
        else p = p->rchild;     // 查找值比根节点大，去找右子树
    }

    if (p == NULL)  // 没找到
        std::cout << "can't find the node!" << std::endl;
    return p;
}

template <class T>
int BinarySortTree<T>::deleteNode(T x)
{
    BSnode<T>* p, * q;
    p = root;q = NULL;
    int flag = 0;
    // 先找到这个结点
    while(p != NULL && flag == 0)
    {
        // q为p的父结点
        if (p->data == x) flag = 1;
        else if (p->data > x) {q = p; p = p->lchild;}
        else { q = p; p = p->rchild; }
    }
    // 没找到
    if (p == NULL) { std::cout << "can't find the node!" << std::endl; return 0;}
    // 找到了
    // 没有子节点
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root) root = NULL; // 根节点
        else if (p == q->lchild) q->lchild = NULL; // p是父结点的左节点，父结点左节点为空
        else q->rchild = NULL;  // p是父结点的右节点，父结点右节点为空
        delete p;
    }

    // 只有一个子节点
    else if(p->lchild == NULL || p->rchild == NULL)
    {
        if(p == root)
        {
            if(p->lchild == NULL) root = p->rchild;
            else root = p->lchild;
        }
        else
        {
            if(p == q->lchild && p->lchild != NULL) q->lchild = p->lchild;
            else if(p == q->lchild && p->rchild != NULL) q->lchild = p->rchild;
            else if(p == q->rchild && p->lchild != NULL) q->rchild = p->lchild;
            else if(p == q->rchild && p->rchild != NULL) q->rchild = p->rchild;
            /*
            // p是父结点的左节点
            if (p == q->lchild)
            {
                if(p->lchild == NULL) q->lchild = p->rchild;
                else q->lchild = p->lchild;
            }
            else
            // p是父结点的右节点
            {
                if(p->lchild == NULL) q->rchild = p->rchild;
                else q->rchild = p->lchild;
            }
            */
        }
        delete p;
    }
    else
    // 左右节点都存在
    {
        BSnode<T>* t, * pleft;
        t = p; pleft = t->lchild;
        // 从p的左节点的右节点开始查找
        while(pleft->rchild != NULL)
        {
            t = pleft;      // 存储上层节点
            pleft = pleft->rchild;
        }

        // 找到右节点为空的结点

        p->data = pleft->data;    // 结点值赋值给p结点
        if(t == p)
            p->lchild = pleft->lchild;
        else
            t->rchild = pleft->lchild;
        delete pleft;
    }
    return 1;
}





