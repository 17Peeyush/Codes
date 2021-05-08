/*Prims algorithm*/
#include <bits/stdc++.h>
#include <iostream>
#define vvpii vector<vector<pair<int,int>>>
#define vpii vector<pair<int,int>>
#define vi vector<int>
#define INF 100000
using namespace std;
// adding adjacency List 
vpii adjacencyList(int i)
{
    int e,d,w;
    vpii ad;
    cout<<"Enter the number of nodes connected to "<<i<<" : ";
    cin>>e;
    cout<<"Enter the weight of path and node: ";
    for(int i=0;i<e;i++)
    {
        cin>>w>>d;
        ad.push_back({w,d});
    }
    return ad;
}
// Finding minimum weight of non processed nodes
int Findmin(vi &w,vector<bool>&f,int v)
{
    int i=0;
    while(f[i]&&i<v)
        i++;
    int index=i,min=w[i];
    for(;i<v;i++)
    {
        if(min>w[i]&&!f[i])
        {
            min=w[i];
            index=i;
        }
    }
    return index;
}
//Printing the edges in MST
void PrintMst(vi p,vi w,int v)
{
    int spanning_tree_weight=0;
    for(int i=1;i<v;i++)
    {
        cout<<p[i]<<"--"<<i<<"\t"<<w[i]<<endl;
        spanning_tree_weight+=w[i];
    }
    cout<<"Weight of the minimum spanning tree: "<<spanning_tree_weight;
}
//Prims MST implemented
void Prims(vvpii&g,int v)
{
    vi parent(v,-1);
    vector<bool> final(v,false);
    vi weight(v,INF);
    int node_processed=v;
    weight[0]=0;
    while(node_processed--)
    {
        int min_node=Findmin(weight,final,v);
        final[min_node]=true;
        for(auto x: g[min_node])
        {
            int w=x.first,node=x.second;
            if(!final[node]&&w<weight[node])
            {
                weight[node]=w;
                parent[node]=min_node;
            }
        }
    }
    PrintMst(parent,weight,v);
}
int main()
{
    int v;
    cout<<"Enter the number of vertices/nodes in the graph: ";
    cin>>v;
    vvpii g;
    for(int i=0;i<v;i++)
    {
        g.push_back(adjacencyList(i));
    }
    Prims(g,v);

    return 0;
}
