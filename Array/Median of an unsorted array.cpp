/*
Median of an unsorted array
Time Complexity: O(n)
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int partition(vector<int>&v,int l,int h)
{
    int pivot=v[l];
    int i=l,j=h;
    while(i<j)
    {
        do{
            i++;
        }while(v[i]<=pivot);
        do
        {
            j--;
        }while(v[j]>pivot);
        if(i<j)
        {
            swap(v[i],v[j]);
        }
    }
    swap(v[l],v[j]);
    return j;
}
int Kthelement(vector<int>&v,int l,int h,int k)
{
    if(l<h)
    {
        int pos=partition(v,l,h);
        if(pos==k) return v[pos];
        else if(pos>k) return Kthelement(v,l,pos,k);
        else return Kthelement(v,pos+1,h,k);
    }
    return -1;
}
int main()
{
   vector<int> v={10,16,3,14,11,9,8,7,13,19};
   int n=v.size();
   float median;
   if(n%2==0)
   {
       int n1=Kthelement(v,0,n,n/2);
       int n2=Kthelement(v,0,n,n/2+1);
       cout<<n1<<"\t"<<n2<<endl;
       median=(n1+n2)/2;
   }
   else
   {
       median=Kthelement(v,0,n,n/2);
   }
   cout<<"Median: "<<median;
    return 0;
}
