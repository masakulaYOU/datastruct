
template <class T>
struct BinTreeNode
{
    T data;     // ������
    BinTreeNode<T> *leftChild, *rightChild; // ���ҽ������
    BinTreeNode() : leftChild(NULL), rightChild(NULL){};
    BinTreeNode(T x, BinTreeNode<T>* l = NULL, BinTreeNode<T>* r = NULL):
        data(x), leftChild(l), rightChild(r){};
};
