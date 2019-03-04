#include <iostream>
#include "BinarySortTree.h"
using namespace std;

int main()
{
    int k;
    int d[12] = {04,18,13,79,33,45,06,23,35,12,34,76};
    BinarySortTree<int> b;
    for(k = 0; k < 12; k++)
    {
        b.insertNode(d[k]);
    }

    cout << "inOrder1:" << endl;
    b.inOrder();

    for(k = 0; k < 6; k++)
        b.deleteNode(d[k]);
    cout << "inOrder2 after delete:" << endl;
    b.inOrder();

    cout << "search:" << endl;
    for(k = 0 ; k < 12; k++)
        cout << b.searchNode(d[k]) << endl;
    return 0;
}
