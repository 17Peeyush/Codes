/*
Problem: https://www.codechef.com/SRIB03/problems/GUDMGR
Time Complexity: O(n!*n)
Auxillary Space: O(n), size of recursive stack
*/


#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int rearrange;
void permute(int pos,vector<bool>&take,int n){
    if(pos==n){
        rearrange++;
        return;
    }
    for(int i=0;i<n;i++){
        if(i!=pos && !take[i]){
            take[i]=true;
            permute(pos+1,take,n);
            take[i]=false;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        rearrange=0;
        vector<bool>take(n,false);
        permute(0,take,n);
        cout<<"#"<<i<<" "<<rearrange<<endl;
    }
    return 0;
}
