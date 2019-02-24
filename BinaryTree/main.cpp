#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    BinaryTree<int> tree(-1);
    cin >> tree;
    cout << tree.height() <<endl;
    cout << tree.size() << endl;
    cout << tree;
    return 0;
}
