/*
Problem: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
Time Complexity: O(nlogn)
Auxillary Space: O(m) , where m is the maximum value of deadline
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
bool comp(struct Job a, struct Job b)
{
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[],int n)
{
    sort(arr,arr+n,comp);
    int maxdeadline=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i].dead>maxdeadline)
        {
            maxdeadline=arr[i].dead;
        }
    }
    vector<int>schedule(maxdeadline,-1);
    int dline=-1,maxProfit=0,noOfJobs=0;
    for(int i=0;i<n;i++)
    {
        dline=arr[i].dead-1;
        while(dline>=0 && schedule[dline]!=-1)
        {
            dline--;
        }
        if(dline!=-1)
        {
            schedule[dline]=arr[i].id;
            noOfJobs++;
            maxProfit+=arr[i].profit;
        }
    }
    return {noOfJobs,maxProfit};
}

int main()
{
   int n;
   cin>>n;
   Job arr[n];
   int id_,dead_,profit_;
   for(int i=0;i<n;i++)
   {
       cin>>id_>>dead_>>profit_;
       arr[i].id=id_;
       arr[i].dead=dead_;
       arr[i].profit=profit_;
   }
    vector<int> out=JobScheduling(arr,n);
    cout<<"No of jobs:"<<out[0]<<" Max profit: "<<out[1];
    return 0;
}
