#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string ans="";
unordered_map<int,char> np;
void dfs(int start,int end,vector<vector<int>>&g,vector<bool>visited,string input)
{
    if(start==end)
    {
        input+=np[end];
        if(ans=="")
        {
            ans=input;
        }
        else
        {
            if(input.length()<ans.length())
            {
                ans=input;
            }
        }
    }
    else
    {
        visited[start]=true;
        input+=np[start];
        for(auto node: g[start])
        {
            if(!visited[node])
            {
                dfs(node,end,g,visited,input);
            }
        }
        visited[start]=false;
    }
}
int main()
{
    int n,c;
    cin>>n>>c;
    unordered_map<char,int> mp;
    char ch;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        mp[ch]=i;
        np[i]=ch;
    }
    vector<vector<int>>g(n);
    for(int i=0;i<c;i++)
    {
         char c1,c2;
         cin>>c1>>c2;
         g[mp[c1]].push_back(mp[c2]);
         g[mp[c2]].push_back(mp[c1]);
    }
    string t="";
    vector<bool>visited(n,false);
    dfs(0,n-1,g,visited,t);
    // cout<<ans;
    // ans=ans.size()==0?"-1":ans;
    cout<<ans;
    return 0;
}
