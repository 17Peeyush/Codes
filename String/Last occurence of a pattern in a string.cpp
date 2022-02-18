#include <bits/stdc++.h>
#include <iostream>

using namespace std;
vector<int> computeLPS(string pat)
{
    int m=pat.length();
    vector<int>lps(m);
    int len=0,i=1;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            lps[i]=len+1;
            i++;
            len++;
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
vector<int> KMP(string txt,string pat)
{
    int n=txt.length(),m=pat.length();
    vector<int>lps=computeLPS(pat);
    int i=0,j=0;
    vector<int> ans;
    while(i<n)
    {
        if(txt[i]==pat[j])
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
        if(j==m)// string completely traversed
        {
            ans.push_back(i-j);
            j=lps[j-1];
        }
    }
    return ans;
}
int main()
{
    string text,pat;
    text="abbcdabcabcd";
    pat="abcd";
    vector<int> last=KMP(text,pat);
    if(last.size()==0)
    {
        cout<<"Pattern not in string text.";
    }
    else
    {
        cout<<"Last occurence: "<<last[last.size()-1];
    }
    return 0;
}
