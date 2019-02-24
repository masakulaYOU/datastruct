#include <iostream>
#include <cstdlib>

template<class T>
struct LinkNode
{
    T data; // ˝æ›”Ú
    LinkNode<T>* link; //÷∏’Î”Ú
    LinkNode(LinkNode<T>* ptr = NULL) {link = ptr;}
    LinkNode(const T& item, LinkNode<T>* ptr = NULL)
    {
        data = item;
        link = ptr;
    }
};

