// You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct.
// Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
// Return true if it is possible to form the array arr from pieces. Otherwise, return false.


#include <iostream>
#include<bits/stdc++.h> 
#include <vector>
using namespace std;
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int>::iterator it;
        int count=0,psize=pieces.size();
        for(int i=0;i<psize;i++)
        {
            if(pieces[i].size()>1)
            {
                int el=pieces[i][0];
                it=find(arr.begin(),arr.end(),el);
                if(it!=arr.end())
                {
                    int current=it-arr.begin();
                    for(int k=1;k<pieces[i].size();k++)
                    {
                        if(pieces[i][k]!=arr[current+k]) return false;
                    }
                }
                else return false;
            }
            else
            {
                it=find(arr.begin(),arr.end(),pieces[i][0]);
                if(it!=arr.end())
                    continue;
                else return false;
            }
            
        }
        return true;
    }
int main() {
    vector<int> arr={1,3,5,7};
    vector<vector<int>> p={{2,4,6,8}};
    cout<<canFormArray(arr,p);
	return 0;
}
