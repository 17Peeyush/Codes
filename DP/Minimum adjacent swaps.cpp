/*
Minimum number of adjacent swaps to make a string palindrome
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
bool ispalindrome(string s)
{
    int i=0,j=s.length()-1;
    while(i<=j)
    {
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}
int minswap(string s,int i,int swaps)
{
    if(i==s.length())
    {
        return INT_MAX;
    }
    else if(ispalindrome(s))
    {
        return swaps;
    }
    else if(i+1<s.length())
    {
        swap(s[i],s[i+1]);
        int sw1=minswap(s,i+1,swaps+1);
        swap(s[i],s[i+1]);
        int sw2=minswap(s,i+1,swaps);
        return min(sw1,sw2);
    }
    return minswap(s,i+1,swaps);
}

int main()
{
   string s;
   cin>>s;
   int ans=minswap(s,0,0);
   if(ans==INT_MAX)
    ans=-1;
  cout<<ans;
    return 0;
}
