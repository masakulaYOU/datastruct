#include <iostream>
#include <cstdlib>
#include "seqList.h"

using namespace std;

int main()
{
    SeqList<int> s1(20);

    s1.input();
//    s2 = s1;
//    s2.Insert(2, 999);
    SeqList<int> s3(s1);
//    s3.output();
    int b;
    int s = 999;
    int c = 6;
    int d = 654;
    s3.Remove(3, b);
    s3.Insert(2, s);
    s3.setData(1, d);
    //cout << "被移除的数是" << b << endl;
    //cout << "数字6在位置" << s3.Search(c) << endl;
    s1.output();
    //s2.output();
    SeqList<int> s2 = s3;
    s2.output();

    return 0;
}
