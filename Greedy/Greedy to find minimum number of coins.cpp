/*
Problem: https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
Time Complexity: O(n)
Auxillary Space: O(n) */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    vector<int>notes={1,2,5,10,20,50,100,500,1000};
    int currency;
    cin>>currency;
    int numNotes=0,n=notes.size()-1;
    while(currency)
    {
        if(currency>=notes[n])
        {
            currency-=notes[n];
            numNotes++;
        }
        else
        {
            n--;
        }
    }
    cout<<"Number of notes: "<<numNotes;

    return 0;
}
