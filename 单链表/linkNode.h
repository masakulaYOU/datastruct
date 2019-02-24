// 结点结构体
template <typename T>
struct LinkNode
{
    T data;     // 数据域
    LinkNode<T>* link;  //链指针域
    LinkNode(LinkNode<T>* ptr = NULL) {link = ptr;} //仅初始化指针域的构造函数
    LinkNode(const T& item, LinkNode<T> *ptr = NULL)
    {
        data = item;
        link = ptr;
    }
    // 初始化数据域和指针域的构造函数
};
