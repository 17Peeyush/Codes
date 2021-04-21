#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void bellmanFord(vector<tuple<int,int,int>>&edgeList,int n, vector<int>&path)
{
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        for(auto x: edgeList)
        {
            u=get<0>(x);
            v=get<1>(x);
            w=get<2>(x);
            if((path[u]+w)<path[v])
                path[v]=path[u]+w;
        }
    }
}
void showPath(vector<int>&path,int n)
{
    for(int i=0;i<n;i++)
        {
            cout<<"node :"<<i<<"\tdistance :"<<path[i]<<endl;
        }
}
int main()
{
    int n,e,user;
    vector<tuple<int,int,int>> edgeList;
    cout<<"Enter the number of nodes and edges in the graph.: ";
    cin>>n>>e;
    vector<int> path(n,INT_MAX);
    cout<<"Enter the edges and their weight :(a,b,w) a-->b:\n";
    for(int i=0;i<e;i++)
    {
        int i1,i2,i3;
        cin>>i1>>i2>>i3;
        edgeList.push_back(make_tuple(i1,i2,i3));
    }
    cout<<"Enter the node from which you want to calculate shortest path.";
    cin>>user;
    path[user]=0;
    bellmanFord(edgeList,n,path);
    showPath(path,n);
    return 0;
}
