/*
INHERITANCE
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class A{
    private:
    int a;
    public:
    A(int x)
    {
        cout<<"A constructor"<<endl;
        this->a=x;
        cout<<"A's a="<<a<<endl;
    }
    ~A()
    {
        cout<<"A destructor"<<endl;
    }
};
class B: public A{
    private:
    int b;
    public:
    B(int x,int y): A(x)
    {
        cout<<"B constructor"<<endl;
        this->b=y;
        cout<<"B's b="<<b<<endl;
    }
    ~B()
    {
        cout<<"B destructor"<<endl;
    }
};

int main()
{
    B obj(1,2);
    return 0;
}

/*
Output:
A constructor
A's a=1
B constructor
B's b=2
B destructor
A destructor


*/
