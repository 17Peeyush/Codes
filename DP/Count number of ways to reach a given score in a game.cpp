/*
Count number of ways to reach a given score in a game
Problem: https://www.geeksforgeeks.org/count-number-ways-reach-given-score-game/
Date: 25-03-2022
Time Complexity: exponential
Auxillary Space: O(n)
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ways(int arr[],int n,int score){
    if(score==0){
        return 1;
    }
    else if(n==0 && !score){
      return 0;  
    } 
    else if(n<1){ 
        return 0;
    }
    if(score>=arr[n-1]){
        return ways(arr,n-1,score)+ways(arr,n,score-arr[n-1]);
    }
    return ways(arr,n-1,score);
}
int main()
{
    int arr[]={3,5,10};
    int score=20;
    cout<<"ways:"<<ways(arr,3,score)<<endl;
    return 0;
}
