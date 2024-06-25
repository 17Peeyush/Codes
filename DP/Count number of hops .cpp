/*
Problem: https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1/
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    vector<long long>dp;
    int MOD=1000000007;
    int printCountRec(int i,int n)
    {
    	// Base cases
    	if (i>n)	 return 0;
    	else if (i==n) return 1;
        if(dp[i]!=-1)
            return dp[i];
    	// Recur for all previous 3 and add the results
    	return dp[i]=(printCountRec(i+1,n)%MOD + printCountRec(i+2,n)%MOD + printCountRec(i+3,n)%MOD)%MOD;
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(n==3) return 4;
	    dp=vector<long long >(n+1);
	    dp[0]=0;
	    dp[1]=1;
	    dp[2]=2;
	    dp[3]=4;
	    for(int i=4;i<=n;i++){
	        dp[i]=(dp[i-1]%MOD+dp[i-2]%MOD+dp[i-3]%MOD)%MOD;
	    }
	    return dp[n];
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends