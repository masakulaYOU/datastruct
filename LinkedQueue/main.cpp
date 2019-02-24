#include <iostream>
#include "linkedQueue.h"
using namespace std;

int main()
{
    LinkedQueue<int> s;
    const int a = 100;
    const int b = 150;
    const int c = 200;
    s.enQueue(a);
    s.enQueue(b);
    s.enQueue(c);
    cout<< s <<endl;
    int g;
    s.deQueue(g);
    cout << g << endl;

    int f;
    s.getFront(f);
    cout << f <<endl;

    cout<<s<<endl;

    return 0;
}
