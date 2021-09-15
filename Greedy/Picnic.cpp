/*
Picnic

A school is organizing a picnic for all its students. 
There is a total of N students labeled from 1 to N in the school. 
Each student i has a compatibility factor of Xi.
It is time for the picnic and all students to stand in a line. 
The student line is to be split into groups. 
A set of consecutive students standing in a line can form a group. 
For the picnic to be safe, each group must have at least 2 students with the same compatibility factor.
Finding the maximum number of groups that can be created.

Input Specification:

input1: N, denoting the number of students.
input2: An array of N elements where the ith element denotes the compatibility factor of ith student.

Output Specification:

Your function should return the maximum number of groups that can be created.


Time Complexity: O(n)
Auxillary Space: O(n)

*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>group(n);
    for(int i=0;i<n;i++)
    {
        cin>>group[i];
    }
    int tg=0,gs=0;//total group, group size
    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        if(!st.insert(group[i]).second)
        {
            tg++;
            st.clear();
        }
    }
    cout<<"Total group:"<<tg;

    return 0;
}
