#include <bits/stdc++.h>

#include <iostream>

using namespace std;
  void reverse(int l,int h,vector<int>&one)
    {
        while(l<=h)
        {
            swap(one[l],one[h]);
            l++;h--;
        }
    }

int main()
{
  vector<int> one={1,2,3,4,5,6,7,8,9};
  int n=9,k=4;
        reverse(0,n-k-1,one);
        reverse(n-k,n-1,one);
        reverse(0,n-1,one);
        for(auto x: one)
        cout<<x<<" ";
    return 0;
}
