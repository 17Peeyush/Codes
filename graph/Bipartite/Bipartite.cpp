#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<vector<int>>&g,vector<bool>&visited,vector<int>&colour,int node,int nodecolour)
{
    visited[node]=true;
    colour[node]=nodecolour;
    for(auto n: g[node])
    {
        if(visited[n])
        {
            if(colour[n]==nodecolour)
                return false;
        }
        else
        {
            bipartite(g,visited,colour,n,(1^nodecolour));
        }
    }
    return true;
}

vector<int> adjacencyList(int n)
{
    vector<int> ad;
    int e,t;
    cout<<"Enter number of nodes connected to node "<<n<<" :";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>t;
        ad.push_back(t);
    }
    return ad;
}

int main()
{
  int n;
  cout<<"Enter the number of nodes in the graph: ";
  cin>>n;
  vector<vector<int>> g;
  vector<bool>visited(n,false);
  vector<int>colour(n,-1);
  for(int i=0;i<n;i++)
  {
      g.push_back(adjacencyList(i));
  }
  if(bipartite(g,visited,colour,0,0))
    cout<<"Graph is bipartite.";
  else cout<<"Graph is not bipartite.";
}
