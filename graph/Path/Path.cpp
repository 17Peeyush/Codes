#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> insert_adjacency(int i)
{
    int e,t;
    cout<<"Enter number of nodes connected to "<<i<<" :";
    cin>>e;
    vector<int> ad;
    for(int j=0;j<e;j++)
    {
        cin>>t;
        ad.push_back(t);
    }
    return ad;
}

void path(vector<vector<int>>&g,int n1,int n2,vector<bool>&visited,int &flag)
{
    visited[n1]=true;
    for(auto v : g[n1])
    {
        
        if(v==n2)
        {   flag=1;
            return;}
        else if(visited[v]) {}
        else { path(g,v,n2,visited,flag);}
    }
}

int main()
{
    vector<vector<int>> g;
    int v,flag=0;
    cout<<"Enter number of vertices or nodes:"<<endl;
    cin>>v;
    for(int i=0;i<v;i++)
    {
        g.push_back(insert_adjacency(i));
    }
    vector<bool> visited(v,false);
    int n1,n2;
    cout<<"Enter the nodes between which you want to find whether the path exists.";
    cin>>n1>>n2;
    path(g,n1,n2,visited,flag);
    if(flag)
    {
        cout<<"Yes Path Exists.";
    }
    else {cout<<"No Such Path Exists.";}
}