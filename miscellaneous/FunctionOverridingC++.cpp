/* FUNCTION OVERRIDING:
    case 1: calling function binding at the compile time
    case 2 and 3: calling function binding at the run time
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class A { //Parent class
    public:
    virtual void f1(int x){
        cout<<"f1() of A"<<endl;
    }
};
class B: public A{ // class B (Child class) inheriting class A
    public:
    void f1(int y){
        cout<<"f1() of B"<<endl;
    }
};


int main()
{
    A ob1;
    B ob2;
    cout<<"case 1:"<<endl;
    ob1.f1(5);
    ob2.f1(4);
    cout<<"\ncase2:"<<endl;
    A *p=new B;
    p->f1(7);
    cout<<"\ncase3:"<<endl;
    p=new A;
    p->f1(9);
    return 0;
}


