#include <bits/stdc++.h>
#include <iostream>

using namespace std;
long long int inversion=0;
void merge(vector<long long int>&arr,int l,int mid,int h)
{
    int nsize=h-l+1;
    vector<long long int> narr(nsize);
    int id=0;
    int i=l,j=mid+1;
    while(i<=mid&&j<=h)
    {
        if(arr[i]>arr[j])
        {
            inversion+=(mid-i+1);
            narr[id++]=arr[j];
            j++;
        }
        else
        {
            narr[id++]=arr[i];
            i++;
        }
    }
    for(;i<=mid;i++)
    {
        narr[id++]=arr[i];
    }
     for(;j<=h;j++)
    {
        narr[id++]=arr[j];
    }
    id=0;
    for(int k=l;k<=h;k++,id++)
    {
        arr[k]=narr[id];
    }
}
void partition(vector<long long int>&arr,int l,int h)
{ 
    if(l<h)
    {
        int mid=l+(h-l)/2;
        partition(arr,l,mid);
        partition(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
void MergeSort(vector<long long int>&arr)
{
    partition(arr,0,arr.size()-1);
}
int main()
{
    vector<long long int> arr={1,20,6,7,5,8,11,3};
    MergeSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<"\nInversion="<<inversion;
    return 0;
}
