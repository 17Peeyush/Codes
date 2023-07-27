/*
Problem: https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1/
Date: 21-03-2022
Time Complexity: O(m*n)
Auxillary Space: O(m*n)
*/
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int MOD=1000000007;
  long long int dp[101][101];
  long long int numPaths(int i,int j,int m,int n){
      if(i==m-1&&j==n-1){
          return 1;
      }
      else if(i>=m||j>=n){
          return 0;
      }
      else if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      return dp[i][j]=numPaths(i+1,j,m,n)%MOD+numPaths(i,j+1,m,n)%MOD;
      
  }
    long long int numberOfPaths(int m, int n){
        // code here
        memset(dp,-1,sizeof(dp));
        return numPaths(0,0,m,n)%MOD;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
