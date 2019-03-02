#include <iostream>
#include "LinkedHash.h"
using namespace std;

int hashf(int k);

int main()
{
    int a[12] = {9,31,26,19,1,13,2,11,27,16,5,21};
    int i;
    LinkedHash<int> h(12);
    for(i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;

    for(i = 0; i < 12; i++)
        h.insertHash(hashf, a[i]);
    cout << "output the keys:" << endl;
    h.output();

    cout << "output the location of every key:" << endl;
    for(i = 0;i < 12; i++)
        cout << h.searchHash(hashf, a[i]) << " ";
    cout << endl;

    h.delHash(hashf, 2);
    cout << "after deleting 2 from the keys:" << endl;
    h.output();

    h.delHash(hashf, 19);
    cout << "after deleting 19 from the keys:" << endl;
    h.output();
    return 0;
}

int hashf(int k) { return (k / 3) + 1; }
