
template <class T>
struct BinTreeNode
{
    T data;     // 数据域
    BinTreeNode<T> *leftChild, *rightChild; // 左右结点链域
    BinTreeNode() : leftChild(NULL), rightChild(NULL){};
    BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL):
        data(x), leftChild(l), rightChild(r){};
};
