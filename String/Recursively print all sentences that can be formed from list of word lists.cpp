/*
    Problem: https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
    Time Complexity : O(m*n)
    Auxillary Space : O(m+n)
    Date: 27-10-2021
    
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class Solution{
    public:
    vector<vector<string>> words;
    int n;
    Solution(vector<vector<string>>w,int num)
    {
        words=w;
        n=num;
    }
    void horizontal(int r,int c,string input)
    {
         if(c>=words[r].size())
        {
            return;
        }
        print(r+1,input+" "+words[r][c]);
        horizontal(r,c+1,input);
    }
    void print(int r,string input)
    {
        if(r==n)
        {
            cout<<input<<endl;
            return;
        }
        horizontal(r,0,input);
    }
};

int main()
{
    vector<vector<string>> w={{"you", "we"},{"have", "are"},{"sleep", "eat", "drink"}};
    Solution ob(w,w.size());
    ob.print(0,"");
    return 0;
}
