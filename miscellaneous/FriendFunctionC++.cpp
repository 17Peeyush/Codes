/*
FRIEND FUNCTION CONCEPTS
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class B;
class A{
    private:
    int a,b;
    public:
    void setnum(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    friend void sum(A);
    friend void tsum(A,B);
};
class B{
    private:
    int a,b;
    public:
    void setnum(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
    friend void tsum(A,B);
};
void sum(A ob)
{
    cout<<"sum: "<<ob.a+ob.b<<endl;
}
void tsum(A ob1,B ob2)
{
    cout<<"total sum a: "<<ob1.a+ob2.a<<endl;
    cout<<"total sum b: "<<ob1.b+ob2.b<<endl;
}
int main()
{
    A ob;
    ob.setnum(9,8);
    sum(ob);
    B obj;
    obj.setnum(1,3);
    tsum(ob,obj);
    return 0;
}
