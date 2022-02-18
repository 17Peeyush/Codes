/* OPERATOR OVERLOADING
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Complex{
    private:
    int r,im;
    public:
    void setnum(int r,int im)
    {
        this->r=r;
        this->im=im;
    }
    void shownum()
    {
        cout<<"real= "<<r<<"\timaginary= "<<im<<endl;
    }
    Complex add(Complex b)
    {
        Complex temp;
        temp.r=r+b.r;
        temp.im=im+b.im;
        return temp;
    }
    Complex operator+(Complex b)
    {
        Complex temp;
        temp.r=r+b.r;
        temp.im=im+b.im;
        return temp;
    }
    void operator++()
    {
        r++;
        im++;
    }
};
int main()
{
    Complex A,B,C,D,E,F;
    A.setnum(3,4);
    A.shownum();
    B.setnum(5,3);
    B.shownum();
    C=A.add(B);
    C.shownum();
    D=A.operator+(B);
    D.shownum();
    E=A+B; // binary operator overloaded
    E.shownum();
    A.operator++();
    A.shownum();
    ++A; // unary operator overloaded
    A.shownum();
    return 0;
}


