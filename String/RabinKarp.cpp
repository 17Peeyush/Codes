#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> RabinKarp(string text,string pat)
{
    vector<int>out;
    int lp=pat.length(),lt=text.length(),pw=lp-1;
    int hp=0,ht=0,j;
    for(int i=0;i<lp;i++,pw--)
    {
        hp+=(pat[i]-65)*pow(3,pw);
        ht+=(text[i]-65)*pow(3,pw);
    }
    for(int i=0;i<=lt-lp;i++)
    {
        if(hp==ht)
        {
            for(j=0;j<lp;j++)
            {
                if(text[i+j]!=pat[j])
                    break;
            }
            if(j==lp)
            {
                out.push_back(i);
            }
        }
        if(i<lt-lp)
        {
            ht=ht-((text[i]-65)*pow(3,lp-1));
            ht=ht*3+(text[i+lp]-65);
        }
    }
    return out;
}
int main()
{
    vector<int>out=RabinKarp("AAABAAADAAAB","AAAB");
    cout<<out.size();
    // for(auto x:out)
    // cout<<x<<" ";
    return 0;
}
