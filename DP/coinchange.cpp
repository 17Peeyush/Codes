
#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int coin(vector<int>arr,int i,int change)
{
    if(arr[i]==change) return 1;
    else if(i<0&&change!=0) return -1;
    else if(arr[i]>change) return coin(arr,i-1,change);
    else
    {
        int a=coin(arr,i-1,change-arr[i]);//taking
        int b=coin(arr,i-1,change);//not taking
        if(a!=-1&&b!=-1) return min(1+a,b);
        else if(a==-1&&b!=-1) return b;
        else if(a!=-1&&b==-1) return a+1;
        else return -1;
    }
    return 0;
}
int main()
{
    vector<int> arr={25,5,10};
    cout<<"coin num: "<<coin(arr,2,45);

    return 0;
}
