/*
Problem: Total number of members are given you have find how my teams can be formed if minimum size of a team is given. 
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=1;
        dp[i][i]=1;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    int teams=0;
    for(int i=r;i<n+1;i++)
    {
        teams+=dp[n][i];
    }
    cout<<"teams: "<<teams;
    return 0;
}
