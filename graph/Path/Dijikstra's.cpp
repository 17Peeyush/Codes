#include <iostream>
#include <queue> 
#include <climits>
using namespace std;
vector<pair<int,int>> adjacencyList(int i)
{
    int n,v,w;
    vector<pair<int,int>> adj;
    cout<<"Enter number of nodes connected to "<<i<<": ";
    cin>>n;
    cout<<"Enter nodes and their weight"<<endl;
    for(int j=0;j<n;j++)
    {
        cin>>v>>w;
        adj.push_back(make_pair(v,w));
    }
    return adj;
}

vector<int> dijikstra( vector<vector<pair<int,int>>> &g,int v,int n)
{
    priority_queue<pair<int,int>> pq;//<weight,node>
    vector<bool> visited(n,false);
    vector<int> path(n,INT_MAX);
    path[v]=0;
    pq.push({0,v});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        visited[p.second]=true;
        for(auto x: g[p.second])
        {
            if(visited[x.first]) continue;
            else if(path[x.first]>(path[p.second]+x.second))
            {
                path[x.first]=path[p.second]+x.second;
                pq.push({-path[x.first],x.first});
            }
        }
    }
    return path;
}

int main()
{
    int n,v;
    vector<vector<pair<int,int>>> g ;// <node,weight>
    cout<<"Enter the number of nodes in the graph: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        g.push_back(adjacencyList(i));
    }
    cout<<"Enter the node from which you want to calculate distance: ";
    cin>>v;
    vector<int>path=dijikstra(g,v,n);
    for(int i=0;i<path.size();i++)
    {
        cout<<i<<"->"<<path[i]<<endl;
    }
    return 0;
}
