#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main()
{
    SparseMatrix<int> s1;
    cin >> s1;
    //cout << s1;
    SparseMatrix<int> s2 = s1 ;

    //SparseMatrix<int> s3 = s1.add(s2);

    cout << s2;
    return 0;
}
