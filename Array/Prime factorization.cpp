/*
    Problem: Prime factorization of a number
    Time Complexity: O(nlog(logn))+ O(logn)
    Auxillary Space: O(n)
    Date: 07-11-2021
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
vector<int>sieve;
void build_Sieve(int n)
{
    sieve=vector<int>(n+1,-1);
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==-1)// prime
        {
            for(int j=i;j<=n;j=j+i)
            {
                if(sieve[j]==-1)
                    sieve[j]=i;
            }
        }
    }
}
void PrimeFactorize(int n)
{
    int i=n;
    while(i!=1)
    {
        cout<<sieve[i]<<" ";
        i=i/sieve[i];
    }
}
int main()
{
    build_Sieve(100000);
    int num;
    cin>>num;
    PrimeFactorize(num);
    return 0;
}
