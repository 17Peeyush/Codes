/*
Greedy: Activity Selection
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//Function to return max number of activities that can be performed
int MaxActivity(vector<pair<int,int>> act,int n)
{
    int max_activity=0;
    int current_time=-1;
    for(auto x: act)
    {
        if(x.second>=current_time)
        {
            max_activity++;
            current_time=x.first;
        }
    }
    return max_activity;
}
//Function to return min number of processors that are required to run all activities
int MinProcessor(vector<pair<int,int>> act,int n)
{
    int min_processor=0;
   
    while(!act.empty())
    {
        int current_time=-1;
        for(int i=0;i<n;)
        {
            if(act[i].second>=current_time)
            {
                current_time=act[i].first;
                act.erase((act.begin()+i));
            }
            else i++;
        }
        min_processor++;
    }
    return min_processor;
}

int main()
{
    int n;// number of activities
    cout<<"Enter the number of activities: ";
    cin>>n;
    int s,e; //Start and end time of an Activity
    vector<pair<int,int>> activity;
    cout<<"Enter the start and end time of an activity."<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        activity.push_back({e,s});
    }
    sort(activity.begin(),activity.end());// Sorting activity in increasing order of their end time
    cout<<"Max number of activities that can be performed: "<<MaxActivity(activity,n)<<endl;
    cout<<"Min processor required to run all activities: "<<MinProcessor(activity,n)<<endl;
    return 0;
}
