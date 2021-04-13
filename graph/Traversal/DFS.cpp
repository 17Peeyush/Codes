#include <iostream>
#include <bits/stdc++.h>
#include <vector>
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

void DFS(vector<vector<int>>&g,int node,vector<int>&visited)
{
    visited[node]=1;
    for(int i=0;i<g[node].size();i++)
    {
        if(visited[g[node][i]]!=1)
        {
            cout<<"->"<<g[node][i]<<"\t";
            DFS(g,g[node][i],visited);
        }
    }
}
int main()
{
    vector<vector<int>> g;
    int v;
    vector<int> t;
    cout<<"Enter number of vertices or nodes:"<<endl;
    cin>>v;
    for(int i=0;i<v;i++)
    {
        t=insert_adjacency(i);
        g.push_back(t);
    }
    vector<int> visited(v,0);
    cout<<"DFS:\n"<<0;
    DFS(g,0,visited);
}