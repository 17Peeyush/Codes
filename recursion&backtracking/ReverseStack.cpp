#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Stack{
    public:
    stack<int> st;
    Stack()
    {
        cout<<"Stack initialized!!"<<endl;
    }
    void pushEl(int el)
    {
        st.push(el);
    }
    void insertELementAtBottom(int t)
    {
        if(st.size()==0)
        {
            st.push(t);
            return;
        }
        int currel=st.top();
        st.pop();
        insertELementAtBottom(t);
        st.push(currel);
    }
    void reverseStack()
    {

        if(st.size()==1||st.size()==0)
        {
            return;
        }
        int temp=st.top();
        st.pop();
        reverseStack();
        insertELementAtBottom(temp);
    }
    void print()
    {
        if(st.size()==0)
        {
            return;
        }
        int temp=st.top();
        st.pop();
        cout<<temp<<" ";
        print();
        st.push(temp);
    }
};
int main()
{
    Stack s;
    s.pushEl(1);
    s.pushEl(2);
    s.pushEl(3);
    s.pushEl(4);
    s.print();
    cout<<"\nReversed Stack: ";
    s.reverseStack();
    s.print();
}
