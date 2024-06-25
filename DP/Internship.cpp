/*
//Amazon
There are N interns numbered from 1 to N. Each intern is assigned a unique ID for each day. 
The internship is for 50 days numbered from 0 to 49.
The ith intern has an ID of (5000*i) on day 1 and for the rest of the days, Day(i) = Day(i-1)+5000+i

Input1: N, number of interns
Input2: Id used 
Output: Return the label of the intern to whom the given password belongs to.

Time Complexity: O(n*k), where n is the number of interns and k is days of internship
Auxiliary Space: O(n*k)
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int check(vector<int>&arr,int k)
{
    int i=1;
    while(i<50&&arr[i-1]<k)
    {
        arr.push_back(arr[i-1]+i+5000);
        i++;
    }
    if(i<50&&arr[i-1]==k)
    {
        return i-1;
    }
    return -1;
}

int main()
{
    int n,id;
    cin>>n>>id;
    int day=-1,intern=-1;
    for(int i=1;i<n;i++)
    {
        vector<int>temp={i*5000};
        if((day=check(temp,id))>-1)
        {
            intern=i;
            break;
        }
    }
    cout<<"Intern :"<<intern<<endl;
    cout<<"Day: "<<day<<endl;

    return 0;
}
