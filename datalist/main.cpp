#include <iostream>
#include "datalist.h"
using namespace std;


int main()
{
    int k;
    double a[5] = {1.5,5.5,2.5,4.5,3.5};
    double b[7] = {1.0,7.5,2.5,4.0,5.0,4.5,6.5};
    DataList<double> s1(20);
    DataList<double> s2(30);
    for(k = 0; k < 5; k++)
        s1.insertList(a[k]);
    for(k = 0; k < 7; k++)
        s2.insertList(b[k]);
    cout<< "s1: "<< endl;
    s1.output();
    cout<< "s2: "<< endl;
    s2.output();

    DataList<double> s3;
    s3 = s1 + s2;   //ºÏ²¢
    cout << "s3: "<< endl;
    s3.output();

    s3.deleteList(a[0]);
    s3.deleteList(b[0]);
    cout << "after delete, s3: "<< endl;
    s3.output();
    return 0;
}
