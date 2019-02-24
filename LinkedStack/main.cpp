#include <iostream>
#include "linkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> s1;
    const int p1 = 50;
    const int p2 = 150;
    const int p3 = 200;
    s1.push(p1);
    s1.push(p2);
    s1.push(p3);
    int top;
    int op;
    s1.getTop(top);
    cout << top << endl;
    cout << s1 << endl;
    s1.pop(op);
    cout << op << endl;
    cout<< s1 << endl;

    return 0;
}
