#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int calculate(string s)
{
    int n=s.length();
    string p1="",p2="",p3="";
    bool plus=false,equal=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ') continue;
        else if(s[i]=='+')
        {
            plus=true; continue;
        }
        else if(s[i]=='=')
        {
            equal=true; continue;
        }
        else if(plus==false&&equal==false)
        {
            p1+=s[i];
        }
        else if(plus==true&&equal==false)
        {
            p2+=s[i];
        }
        else
        {
            p3+=s[i];
        }
    }
    if(p1=="X") // x+b=c
    { 
        int b=stoi(p2);
        int c=stoi(p3);
        return (c-b);
    }    
    else if(p2=="X") //a+x=c
    {
        int a=stoi(p1);
        int c=stoi(p3);
        return (c-a);
    }
    else // a+b=x
    {
        int a=stoi(p1);
        int b=stoi(p2);
        return (a+b);
    }
    return 0;
}
int main()
{
    string s;
    getline(cin,s);
    cout<<"X="<<calculate(s)<<endl;
    return 0;
}
