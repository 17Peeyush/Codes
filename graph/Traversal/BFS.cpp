
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void BFS(vector<vector<int>>&g,int n)
{
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto node: g[f])
        {
            if(visited[node]==false)
            {
                cout<<"->"<<node;
                q.push(node);
                visited[node]=true;
            }
        }
    }
}

vector<int> adjacency_list(int n)
{
    vector<int> ad;
    int e,t;
    cout<<"Enter the number of nodes connected to "<<n<<" :";
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
    vector<vector<int>> g;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        g.push_back(adjacency_list(i));
    }
    cout<<"BFS :\t"<<"0";
    BFS(g,n);
}
