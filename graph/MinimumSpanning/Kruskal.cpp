#include <iostream>
#include <bits/stdc++.h>
#include <vector>
//typedef vector<pair<int,pair<int,int>>> viii;
using namespace std;
int find(int u,vector<int>parent)
{
    if(parent[u]<0) return u;
    return find(parent[u],parent);
}
void unionByWeight(int u,int v,vector<int>&parent)
{
    int pu=find(u,parent),pv=find(v,parent);
    if(pu!=pv)
    {
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
             parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }
}
vector<pair<int,pair<int,int>>> Krushkals( vector<pair<int,pair<int,int>>>&g,int v)
{
     vector<pair<int,pair<int,int>>> res;
     int s,d,w;
     vector<int>parent(v,-1);
     sort(g.begin(),g.end());
     for(auto x: g)
     {
         s=x.second.first;
         d=x.second.second;
         w=x.first;
         if(find(s,parent)!=find(d,parent))
         {
             res.push_back(x);
             unionByWeight(s,d,parent);
         }
     }
     return res;
}
int main()
{
    int v,e,s,d,w;
    vector<pair<int,pair<int,int>>> g;
    cout<<"Enter the number of nodes and edges: ";
    cin>>v>>e;
    cout<<"Enter the edge list with weight:"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
     vector<pair<int,pair<int,int>>> mspt=Krushkals(g,v);
     cout<<"Minimum spanning tree: ";
     int weight=0;
     for(auto x: mspt)
     {
         cout<<x.second.first;
         cout<<"->"<<x.second.second<<endl;
         weight+=x.first;
     }
     cout<<"\nWeight of Minimum Spanning Tree: "<<weight;
    return 0;
}