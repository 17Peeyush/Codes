#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int num,int n)
{
    return (1<=num&&num<=n);
}
int stepsByKnight(vector<int>&knightpos,vector<int>&targetpos,int n)
{
    vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
    int ex=targetpos[0],ey=targetpos[1];
    queue<tuple<int,int,int>>q;
    q.push({knightpos[0],knightpos[1],0});
    int minstep=0;
    while(!q.empty())
    {
        tuple<int,int,int> x=q.front();q.pop();
        int cx=get<0>(x),cy=get<1>(x),p=get<2>(x);
        if(cx==ex&&cy==ey)
        {
            minstep=p;
            break;
        }
        if(visited[cx][cy]) continue;
        visited[cx][cy]=true;
        if(check(cy+2,n))
        {
            if(check(cx-1,n)) q.push({cx-1,cy+2,p+1});
            if(check(cx+1,n)) q.push({cx+1,cy+2,p+1});
        }
        if(check(cx-2,n))
        {
            if(check(cy+1,n)) q.push({cx-2,cy+1,p+1});
            if(check(cy-1,n)) q.push({cx-2,cy-1,p+1});
        }
        if(check(cx+2,n))
        {
            if(check(cy+1,n)) q.push({cx+2,cy+1,p+1});
            if(check(cy-1,n)) q.push({cx+2,cy-1,p+1});
        }
        if(check(cy-2,n))
        {
            if(check(cx-1,n)) q.push({cx-1,cy-2,p+1});
            if(check(cx+1,n)) q.push({cx+1,cy-2,p+1});
        }
    }
    return minstep;
}
int main()
{
    int n,x,y;
    cin>>n;
    vector<int>knightpos;
    cin>>x>>y;
    knightpos.push_back(x);
    knightpos.push_back(y);
    vector<int>targetpos;
    cin>>x>>y;
    targetpos.push_back(x);
    targetpos.push_back(y);
    cout<<stepsByKnight(knightpos,targetpos,n);

    return 0;
}
