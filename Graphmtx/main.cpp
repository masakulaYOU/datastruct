#include <iostream>
#include "Graphmtx.h"
using namespace std;

int main()
{
    Graphmtx<int, int> g(20);
    cin >> g;
    cout << g;

    int v;
    int e1, e2;
    cout << "Input the index of the vertex you want to delete: ";
    cin >> v;
    g.removeVertex(v);
    cout << g;
    cout << "Input the indices of the vertices of the edge you want to delete: " << endl;
    cin >> e1 >> e2;
    g.removeEdge(e1, e2);
    cout << g;

    /*
    int i1, i2;
    i1 = g.getFirstNeighbor(0);
    cout << i1 <<endl;
    i2 = g.getNextNeighbor(1,1);
    cout <<i2 << endl;
    */
    return 0;
}
