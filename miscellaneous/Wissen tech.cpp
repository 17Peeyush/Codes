#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long count_pairs(int N,vector<int>A,int X){
    long long count=0;
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<N;i++){
        if(mp.find(A[i])==mp.end()){
            mp[A[i]]=vector<int>();
        }
        mp[A[i]].push_back(i+1);
    }
    for(auto y: mp){
        int n=y.second.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // cout<<y.second[i]<<"\t"<<y.second[j]<<endl;
                if((y.second[i]%X)*(y.second[j]%X)==0){
                    count++;
                }
            }
        }
    }
    return count;
}

vector<int> query_game(int N,vector<int>A,int Q,vector<vector<int>>P){
    unordered_map<int,int>mp;
    for(int i=0;i<N;i++){
        mp[A[i]]=i+1;
    }
    vector<int>output;
    bool reverse=false;
    for(int i=0;i<Q;i++){
        auto x=P[i];
        if(x[0]==1&&x[1]==0&&x[2]==0){
            if(reverse){
                reverse=false;
            }
            else{
                reverse=true;
            }
        }
        else if(x[0]==2){
            int i=x[1],j=x[2];
            if(reverse){
                int ic=N-i+1;
                int jc=N-j+1;
                mp[A[ic-1]]=j;
                mp[A[jc-1]]=i;
                swap(A[ic-1],A[jc-1]);
            }
            else{
            mp[A[i-1]]=j;
            mp[A[j-1]]=i;
            swap(A[i-1],A[j-1]);
            }
        }
        else{
            if(reverse){
                output.push_back(N-mp[x[1]]+1);
            }
            else{
                output.push_back(mp[x[1]]);
            }
        }
    }
    return output;
}
int main()
{
    vector<int>t={1,2,3,4};
    vector<vector<int>>q={{2,2,4},{3,2,0},{1,0,0},{3,1,0}};
    int N=4,X=4;
    t=query_game(N,t,X,q);
    for(auto x:t)
        cout<<x<<" ";
    // cout<<count_pairs(N,t,X);

    return 0;
}
