//SEARCHING CONNECTED COMPONENTS
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<bool>visited;
void dfs(int i,vector<vector<int>>&g,vector<int>&comp,vector<bool>&visited)
{  
    visited[i]=true;
    comp.push_back(i);
    for(auto x:g[i])
    {
        if(!visited[x])
        {
            dfs(x,g,comp,visited);
        }
    }
}
vector<vector<int>> findComponents(vector<vector<int>>&g,int n)
{
    vector<bool>visited=vector<bool>(n+1,false);
    vector<vector<int>> totalComponents;
    for(int i=1;i<n+1;i++)
    {
        vector<int>comp;
        if(!visited[i])
        {   
            dfs(i,g,comp,visited);
            totalComponents.push_back(comp);
        }
    }
    return totalComponents;
}

void printComponents(vector<vector<int>>&c)
{
    for(int i=0;i<c.size();i++)
    {
        cout<<i+1<<" Component:\t->";
        for(int j=0;j<c[i].size();j++)
            cout<<c[i][j]<<"";
        cout<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    int s,d;
    for(int i=0;i<m;i++)
    {
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }    
    vector<vector<int>> components=findComponents(g,n);
    printComponents(components);
    return 0;
}
