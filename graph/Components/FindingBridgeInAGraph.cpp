#include<bits/stdc++.h>
#include <iostream>

using namespace std;
vector<int>in;
vector<int>low;
int timer=0;
void Bridges(vector<vector<int>>&g,int node,int parent,vector<bool>&visited)
{
    visited[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(auto x:g[node])
    {
        if(x==parent) continue;
        if(!visited[x])
        {
            Bridges(g,x,node,visited);
            if(low[x]>in[node])
                cout<<node<<"->"<<x<<"is a bridge."<<endl;
            low[node]=min(low[x],low[node]);
        }
        else
        {
            low[node]=min(low[node],in[x]);
        }
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>g(n);
    int s,d;
    for(int i=0;i<m;i++)
    {
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    vector<bool>visited(n,false);
    in=vector<int>(n);
    low=vector<int>(n);
    Bridges(g,0,-1,visited);

    return 0;
}
