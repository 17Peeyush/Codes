/******************************************************************************
HEAPIFY: building max heap from an array
Time complexity: it seems O(nlogn) but it is approximately O(n).
Space Complexity: O(1)
Learned from: gfg
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[],int i,int n)
{
    int largest=i;
    int lc=2*i+1;
    int rc=2*i+2;
    if(lc<n&&arr[lc]>arr[largest])
        largest=lc;
    if(rc<n&&arr[rc]>arr[largest])
        largest=rc;
    if(largest!=i)
    {
        int t=arr[largest];
        arr[largest]=arr[i];
        arr[i]=t;
        
        heapify(arr,largest,n);
    }
}
void build_heap(int arr[],int n)
{
    int start_index=(n/2)-1;
    for(;start_index>=0;start_index--)
    {
     heapify(arr,start_index,n);   
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
int main()
{
    int n=11;
    int arr[n]={1,3,5,4,6,13,10,9,8,15,17};
    print(arr,n);
    build_heap(arr,11);
    cout<<"heap:"<<endl;
    print(arr,n);
    return 0;
}
