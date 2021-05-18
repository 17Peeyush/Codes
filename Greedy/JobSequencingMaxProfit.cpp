/*Greedy : Job Sequencing Max Profit*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> f,pair<int,int>s) // helps to sort in decending order.
{
    return f.first>s.first;
}

int main()
{
    int n;// number of jobs.
    cout<<"Enter the number of jobs: ";
    cin>>n;
    int profit,deadline;// profit and deadline associated with it.
    vector<pair<int,int>> jobs;// pair<profit,deadline>
    for(int i=0;i<n;i++)
    {
        cin>>profit>>deadline;
        jobs.push_back({profit,deadline});
    }
    sort(jobs.begin(),jobs.end(),compare);// Sorting jobs according to max profit.
    int max_time=jobs[0].second;
    for(auto x: jobs)// Finding maximum deadline.
    {
        if(max_time<x.second)
        {
            max_time=x.second;
        }
    }
    vector<int> sequence(max_time,-1);// To store the sequence of jobs.
    int max_profit=0;
    for(int i=0;i<n;i++)
    {
        int j=jobs[i].second-1;
        while(j>=0&&sequence[j]!=-1)//Finding free time slot.
            j--;
        if(j>=0&&sequence[j]==-1) // If free time slot available.
        {
            sequence[j]=i; // Assign job there.
            max_profit+=jobs[i].first; // Add its profit in total profit.
        }
    }
    cout<<"Max Profit: "<<max_profit;
    return 0;
}
