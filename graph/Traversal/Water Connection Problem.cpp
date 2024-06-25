/*
Problem: https://www.geeksforgeeks.org/water-connection-problem/
Approach:
Time Complexity: O(n+p), where n is number of houses and p is number of pipes
Auxiliary Space: O(n+p)
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void dfs(int node,vector<bool>& visited,vector<vector<pair<int,int>>>& g,vector<int>& in,vector<int>& out,int& tap,int& mindia)
{
    visited[node]=true;
    if(in[node]==1&&out[node]==0)
    {
        tap=node; // house which has only one indegree i.e house where tap will be installed
    }
    for(auto x: g[node])
    {
        if(!visited[x.first])
        {
            mindia=min(mindia,x.second); // storing minimum diameter in a component
            dfs(x.first,visited,g,in,out,tap,mindia);
        }
    }
}
vector<vector<int>> solve(int n,int p,vector<int>a,vector<int>b,vector<int>d)
{
    //Initializing graph
    vector<vector<pair<int,int>>>g(n+1);
    vector<int> in(n+1,0); // To store indegree of house/node
    vector<int> out(n+1,0); // To store outdegree of house/node
    // Creating graph and calculating in and out degree
    for(int i=0;i<p;i++)
    {
        g[a[i]].push_back({b[i],d[i]});
        out[a[i]]++;
        in[b[i]]++;
    }
    vector<bool>visited(n+1,false); // To keep track of which nodes have been visited
    vector<vector<int>>output;
    int tank,tap,dia;
    for(int i=1;i<=n;i++)
    {
        if(out[i]==1&&in[i]==0&&!visited[i]) //Starting from a house which have one outdegree i.e house where tank will be installed
        {
            tank=i,tap=-1,dia=INT_MAX;
            dfs(i,visited,g,in,out,tap,dia);// calling dfs as it will visit all the nodes in this component
            output.push_back({tank,tap,dia});
        }
    }
    sort(output.begin(),output.end());
    return output;
}
int main()
{
    int n,p;// n->number of houses; p-> number of pipes
    cin>>n>>p;
    vector<int> a(p);// source house
    vector<int> b(p);// destination house
    vector<int> d(p);// diameter of pipe
    for(int i=0;i<p;i++)
    {
        cin>>a[i]>>b[i]>>d[i];
    }
    vector<vector<int>>out=solve(n,p,a,b,d);
    cout<<out.size()<<endl;
    for(auto x:out)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
