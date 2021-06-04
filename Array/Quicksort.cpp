/*
QuickSort algorithm
Time Complexity:
Best-case performance: O(n log n) 
Worst-case space complexity: O(n) 
Worst-case performance: O(n2)
Average performance: O(n log n)

Space Complexity:
The space complexity is calculated based on the space used in the recursion stack.
The worst case space used will be O(n).
The average case space used will be of the order O(log n)
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
void quicksort(vector<int>&v,int l,int h)
{
    if(l<h)
    {
        int pos=partition(v,l,h);
        quicksort(v,l,pos);
        quicksort(v,pos+1,h);
    }
}
int main()
{
   vector<int> v={10,16,3,14,11,9,8,7,13};
   int n=v.size();
   quicksort(v,0,n);
   cout<<"Sorted vector:"<<endl;
   for(auto x: v)
   {
       cout<<x<<" ";
   }
    return 0;
}
