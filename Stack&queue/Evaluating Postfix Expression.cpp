#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> s;
    char x;
    string st;
    int a,b,c,f=0;
    for(int i=0;i<n;i++)
    {   cin>>st;
        f=0;
        if(st.length()>1)
            s.push(stoi(st));
        else
        {
            x=st[0];
            f=1;
        }
        int ch=x-48;
        if(f==1&&(ch<0||ch>9))
        // if(x=='+'||x=='-'||x=='*'||x=='/')
        {
            a=s.top(); s.pop();
            b=s.top(); s.pop();
            if(x=='+')
            {
                c=b+a;
            }
            else if(x=='-')
            {
                c=b-a;
            }
            else if(x=='*')
            {
                c=b*a;
            }
            else
            {
                c=b/a;
            }
            s.push(c);
            //cout<<s.top()<<endl;
        }
        else
        { 
            if(f==1)
                s.push(x-48);
            
        }
    }
    cout<<s.top();
    return 0;
}
