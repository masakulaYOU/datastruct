#include <iostream>
#include "RndHash.h"
using namespace std;

int hashf(int k);

int main()
{
    int a[12] = {9,31,26,19,1,13,2,11,27,16,5,21};
    int i;
    RndHash<int> h(16);
    cout << "Original hash:" << endl;
    for(i = 0; i < 12; i++)
        cout << a[i] << " ";
    cout << endl;
    for(i = 0; i < 12; i++)
        h.insertHash(hashf, a[i]);
    cout << "output the keys:" << endl;
    h.output();
    cout << "output the location of every key:" << endl;
    for(i = 0; i < 12; i++)
        cout << h.searchHash(hashf, a[i]) << " ";
    cout << endl;
    return 0;
}

int hashf(int k){ return (k/3 + 1); }
