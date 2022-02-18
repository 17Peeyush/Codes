(/*
Zombies and Chocolate
It's Bob birthday, he had bought N bags of chocolates with each bag having A1 (1<=i<=N) chocolates and placed each bag one after another.
Bob had to return home where his friends are waiting but on his way, he encountered a queue of M zombies 
towards him. Zombie wants all his bags and will leave him only after the zombies finish eating all his chocolates.
Bob will distribute the bags in the order it appears. Bob will always give a bag to the first zombie in the queue
and after giving a bag he can decide whether the zombie can leave or stay in the queue. Once the zombie left the 
queue, Bob cannot give that zombie more bags. Once the distrubution of bags is over, all the zombies will start
eating chocolates simultaneously, each zombie can take the whole number of bags and eat all the chocolates of the bag,
it takes 1 second to eat one chocolate. Bob cannot hide any bags, he had to distribute all the bags in order to go
home. Bob wants your help in distributing all the bags so that can he can reach home in minimum possible time.
Example 1:
N=5
A=[2,2,1,1,3]
M=3
Output: 3

Example 2:
N=4
A=[2,8,7,10]
M=3
Output: 10
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<bool,int> isValid(vector<int>bag,int mid ,int m)
{
    int n =bag.size();
    int sum=0, mx=0;
    int k=1;
    for(int i=0;i<n;i++)
    {
        sum+=bag[i];
        if(sum>mid)
        {
            sum=bag[i];
            k++;
        }
        mx=max(sum,mx);
        if(k>m) return {false,-1};
    }
    return {true,mx};
}
int main()
{
    int n,m,start=INT_MIN,end=0;
    cin>>n;
    vector<int> bag(n);
    for(int i=0;i<n;i++)
    {
        cin>>bag[i];
        start=max(bag[i],start);
        end+=bag[i];
    }
    cin>>m;
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        auto t=isValid(bag,mid,m);
        if(t.first)
        {
            res=t.second;
            end=mid-1;
        }
        else
        {
         start=mid+1;   
        }
    }
    cout<<"mintime: "<<res;
    return 0;
}
