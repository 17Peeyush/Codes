/*
Problem: https://www.hackerearth.com/problem/algorithm/question-7-4/
Date: 09-04-2022
Time Complexity: O(m*n)
Auxiliary Space: O(m*n)
*/
#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
unordered_map<int,vector<vector<int>>>mp ;
bool valid(int x,int y,int &n,int &m){
    if(x>=0&&x<n&&y>=0&&y<m) return true;
    return false;
}
bool left(int num){
    return (num==1||num==3||num==6||num==7);
}
bool right(int num){
    return (num==1||num==3||num==4||num==5);
}
bool up(int num){
    return (num==1||num==2||num==4||num==7);
}
bool down(int num){
    return (num==1||num==2||num==5||num==6);
}
int bfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int n,int m,int r,int c,int l){
    queue<pair<int,int>>q;
    int pipes=0;
    if(grid[r][c]==0) return 0;
    q.push({r,c});
    while(!q.empty()&&l){
        int size=q.size();
        while(size--){
            auto z=q.front();
            q.pop();
            int x=z.first,y=z.second;
            // cout<<x<<" "<<y<<"  l"<<l<<endl;
            if(visited[x][y])
                continue;
            visited[x][y]=true;
            pipes++;
            //left
            if(valid(x,y-1,n,m)&&grid[x][y-1]&&!visited[x][y-1]&&left(grid[x][y])&&right(grid[x][y-1]))
                q.push({x,y-1});
            //right  
            if(valid(x,y+1,n,m)&&grid[x][y+1]&&!visited[x][y+1]&&right(grid[x][y])&&left(grid[x][y+1]))
                q.push({x,y+1});
            //up
            if(valid(x-1,y,n,m)&&grid[x-1][y]&&!visited[x-1][y]&&up(grid[x][y])&&down(grid[x-1][y]))
                q.push({x-1,y});
            //down
            if(valid(x+1,y,n,m)&&grid[x+1][y]&&!visited[x+1][y]&&down(grid[x][y])&&up(grid[x+1][y]))
                q.push({x+1,y});
            }
             l--;
        }
        // cout<<"pipes: "<<pipes<<"  l"<<l<<endl;
 return pipes;   
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,r,c,l;
        cin>>n>>m>>r>>c>>l;
        vector<vector<int>> grid(n,vector<int>(m));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int pipes=bfs(grid,visited,n,m,r,c,l);
        cout<<pipes<<endl;
    }
 
    return 0;
}