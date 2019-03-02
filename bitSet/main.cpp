#include <iostream>
#include "bitSet.h"

using namespace std;

int main()
{
    const int len = 20;
    bitSet<int> s1(len), s2(len), s3(len), s4(len), s5(len);
    for(int k = 0; k < 9; k++)
    {
        s1.addMember(k);
        s2.addMember(k + 7);
    }
    s3 = s1 + s2;
    s4 = s1 * s2;
    s5 = s1 - s2;
    cout << s1;
    return 0;
}
