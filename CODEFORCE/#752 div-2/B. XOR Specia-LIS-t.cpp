/*
Codeforces Round #752 (Div. 2)
B. XOR Specia-LIS-t
Link: https://codeforces.com/problemset/problem/1604/B
Time Complexity: O(n)
Auxillary Space: O(1)
Approach:
Let 'n' be the number of elements in the array.
If 'n' is even then we can split the array into n parts and LIS for each part will be 1, XOR of 1 even number of times result in 0. So answer is yes.
If 'n' is odd we need to find one such pair so that the length of LIS is 1 then answer is YES otherwise NO.
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(n%2==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            bool flag=false;
            for(int i=1;i<n;i++)
            {
                if(arr[i-1]>=arr[i])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
