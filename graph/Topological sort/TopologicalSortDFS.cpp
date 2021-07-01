#include <bits/stdc++.h>
#include <iostream>

using namespace std;
void dfs(int i,int &cycle,vector<int>&topo,vector<int>&state,vector<vector<int>>&g)
{
    if(cycle) return;
    if(state[i]==1){
        cycle=1;
        return;
    }
    else if(state[i]==2) return;
    state[i]=1;
    for(auto x: g[i])
    {
        dfs(x,cycle,topo,state,g);
    }
    state[i]=2;
    topo.push_back(i);
    return;
}
void topologicalSort(vector<vector<int>>&g,int n)
{
    vector<int>degree(n+1,0);
    for(int i=0;i<g.size();i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            degree[g[i][j]]++;
        }
    }
    vector<int>topo;
    vector<int>state(n+1,0);
    int cycle=0;
    for(int i=1;i<n+1;i++)
    {
        if(cycle) break;
        if(degree[i]==0)
        {
            dfs(i,cycle,topo,state,g);
        }
    }
    if(cycle) cout<<"Cycle present";
    else{
        reverse(topo.begin(),topo.end());
        for(auto x: topo)
        {
         cout<<x<<" ";   
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++)
    {
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
    }
    topologicalSort(g,n);
    return 0;
}
