/*Greedy : Fractional Knapsack*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> f,pair<int,int>s) // helps to sort in decending order.
{
    return f.first>s.first;
}

int main()
{
    int n,knapsack;// number of items.,weight of knapsack
    cout<<"Enter the number of items and weight of knapsack: ";
    cin>>n>>knapsack;
    int value,weight;// value and weight associated with items.
    vector<pair<int,int>> items;// pair<value,weight>
    vector<pair<float,int>> vbw; //pair<value by weight, index> 
    cout<<"Enter the value and weight of items: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>value>>weight;
        items.push_back({value,weight});
        vbw.push_back({(value/weight),i});
    }
    sort(vbw.begin(),vbw.end(),compare);// Sorting items according to max value by weight.
    float max_profit=0;
    for(int i=0;i<n;i++)
    {
        int index=vbw[i].second; //Accessing index value of the items having value by weight in decreasing order
        if(items[index].second<=knapsack)// if remaining available weight of knapsack greater than the weight of item
        {
            max_profit+=items[index].first;// we can take whole item hence whole profit is added
            knapsack-=items[index].second; //Now reducing knapsack weight
            if(!knapsack)
                break;
        }
        else
        {
            //weight of item is greater than remaining available weight of knapsack
            max_profit+=(vbw[i].first)*knapsack; // adding the fractional part of the profit
            break;
        }
    }
    cout<<"Max Profit: "<<max_profit;
    return 0;
}
