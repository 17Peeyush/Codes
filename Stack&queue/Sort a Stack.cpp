#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insert(int t,stack<int>&st)
{
    if(st.size()==0)
    {
        st.push(t);
        return;
    }
    if(st.top()<=t)
    {
        st.push(t);
        return;
    }
    int temp=st.top();
    st.pop();
    insert(t,st);
    st.push(temp);
}
void SortedStack(stack<int>&s)
{
   //Your code here
   if(s.size()==1)
   {
       return;
   }
   int temp=s.top();
   s.pop();
   SortedStack(s);
   insert(temp,s);
}
int main()
{
   stack<int>s;
   s.push(3);
   s.push(2);
   s.push(1);
   s.push(4);
    SortedStack(s);
    cout<<"Sorted"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
