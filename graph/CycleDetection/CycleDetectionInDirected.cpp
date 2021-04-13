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
bool inRecursiveStack(vector<int> rec_stack,int node)
{
    for(auto el: rec_stack)
    {
        if(el==node)
        return true;
    }
    return false;
}
void cycleDetect(vector<vector<int>>&g,int node,vector<bool>&visited,vector<int>&rec_stack,int&f)
{
    if(visited[node])
    {
        if(inRecursiveStack(rec_stack,node))
        { f=1;
            return;
        }
        return;
    }
    visited[node]=true;
    rec_stack.insert(rec_stack.begin(),node);
    for(auto v: g[node])
        cycleDetect(g,v,visited,rec_stack,f);
    rec_stack.erase(rec_stack.begin());
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
    cycleDetect(g,0,visited,rec_stack,flag);
    if(flag==-1)
        cout<<"Cycle not present.";
    else cout<<"Cycle present.";
}
