#include <iostream>
#include "LinearHash.h"

using namespace std;

int hashf(int k);

int main()
{
    int a[13] = {9, 13, 26, 19, 1, 13, 2, 11, 27, 16, 5, 21};
    int k;
    LinearHash<int> h(12);
    cout << "origin data: " << endl;
    for(k = 0; k < 12; k++)
        cout << a[k] << "\t";
    cout << endl;
    for(k = 0; k < 12; k++)
        h.insertHash(hashf, a[k]);
    cout << "output the keys: " << endl;
    h.output();
    cout << "output the index of the keys in hash: " << endl;
    for(k = 0; k < 12; k ++)
        cout << h.searchHash(hashf, a[k]) << " " ;
    cout << endl;
    return 0;
}

int hashf(int k)
{
    return (k/3 + 1);
}
