#include<iostream>
#include<cstdlib>
#include "linkList.h"

using namespace std;

int main()
{
    /*

    */
    const int b = 4;
    LinkList<int> l1(b);
    l1.input();
    int get;
    int sets = 999;
    int inse = 456;
    int remo;
    l1.getData(2, get);
    cout << "get:" << get << endl;
    l1.setData(3, sets);
    cout << "setData�޸����ݺ�"<< endl;
    l1.output();

    l1.Insert(1, inse);
    cout << "�������ݺ�"<< endl;
    l1.output();

    l1.Remove(3, remo);
    cout << "ɾ�������" << remo << endl;
    cout << "ɾ�����ݺ�" << endl;
    l1.output();

    LinkList<int> l2(l1);
    cout << "���ƹ��캯����"<<endl;
    l2.output();
    LinkList<int> l3 = l2;
    cout << "=����" << endl;
    l3.output();
    return 0;
}
