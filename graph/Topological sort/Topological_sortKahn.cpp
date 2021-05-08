/*
    Topological Sort(Kahn's algorithm)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void KahnTopo(vector<vector<int>>&g,int v)
{
    vector<int>indegree(v,0);
    // Indegree vector created
    for(int i=0;i<v;i++)
    {
        for(auto x: g[i])
        {
            indegree[x]++;
        }
    }
    queue<int> q;
    // Node with zero indegree are stored in queue
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int> topoRes;// store topological sorting
    while(!q.empty())
    {
        int n=q.front();q.pop();
        for(auto x: g[n])
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
        topoRes.push_back(n);
    }
    if(topoRes.size()==v)
    {
        cout<<"topological sort: ";
        for(auto x: topoRes)
            cout<<x<<"\t";
    }
    else
    {
        cout<<"topological sort not possible.";
    }
}

vector<int> adjacencyList(int i)
{
    int n,t;vector<int>ad;
    cout<<"Enter the number of nodes connected from node "<<i<<": ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        ad.push_back(t);
    }
    return ad;
}
int main()
{
    int v,e;
    cout<<"Enter the number of nodes/vertices and number of edges in the graph: ";
    cin>>v>>e;
    vector<vector<int>> g;
    for(int i=0;i<v;i++)
    {
        g.push_back(adjacencyList(i));
    }
    KahnTopo(g,v);
    return 0;
}
