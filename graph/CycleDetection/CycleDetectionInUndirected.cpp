#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList(int i)
{
    int n,t;
    cout<<"Enter the number of nodes connected to node "<<i<<" :";
    cin>>n;
    vector<int> ad;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        ad.push_back(t);
    }
    return ad;
    
}
void cycleDetect(vector<vector<int>>&g,int node,vector<bool>&visited,int&f,int parent)
 {
    visited[node]=true;
    for(auto v: g[node])
    {   if(visited[v])
        {
            if(v!=parent)
            {f=1;return;}
        }
       else cycleDetect(g,v,visited,f,node);
    }
}
int main()
{
    int n,flag=-1;
    cout<<"Enter the number of nodes in graph: ";
    cin>>n;
    vector<vector<int>> g;
    vector<bool> visited(n,false);
    vector<int> rec_stack;
    for(int i=0;i<n;i++)
    {
        g.push_back(adjacencyList(i));
    }
    cycleDetect(g,0,visited,rec_stack,flag,-1);
    if(flag==-1)
        cout<<"Cycle not present.";
    else cout<<"Cycle present.";
}
