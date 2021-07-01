//KMP(Knuth-Morris-Pratt)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>createlps(string pat)
{
    int m=pat.length();
    vector<int>lps(m);
    int i=1,len=0;
    lps[0]=0;
    while(i<m)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(string text,string pat)
{
    int n=text.length(),m=pat.length();
    vector<int>lps=createlps(pat);
    vector<int>out;
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==m)
        {
            out.push_back(i-j);
            j=lps[j-1];
        }
    }
    return out;
}

int main ()
{
  string text="banana",pat="ana";
  vector<int>out=kmp(text,pat);
  for(auto x:out)
    cout<<x<<"\t";

  return 0;
}
