// ���ṹ��
template <typename T>
struct LinkNode
{
    T data;     // ������
    LinkNode<T>* link;  //��ָ����
    LinkNode(LinkNode<T>* ptr = NULL) {link = ptr;} //����ʼ��ָ����Ĺ��캯��
    LinkNode(const T& item, LinkNode<T> *ptr = NULL)
    {
        data = item;
        link = ptr;
    }
    // ��ʼ���������ָ����Ĺ��캯��
};
