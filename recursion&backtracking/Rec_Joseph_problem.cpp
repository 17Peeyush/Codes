#include <iostream>
using namespace std;

int main() {
int n=7,k=3;
//cin>>n>>k;
int index=0,ki=1,neg=0;
int arr[]={1,2,3,4,5,6,7};
while(neg!=n-1)
{
    if(ki==k)
    {
        if(arr[index]==-1)
        {
            while(arr[index]==-1)
            {
                if(index==n-1) index=0;
                index++;
            }
        }
        arr[index]=-1;
        neg++;ki=0;
    }
    if(arr[index]==-1)
        {
            while(arr[index]==-1)
            {
                if(index==n-1) index=0;
                else index++;
            }
        }
    else
    {
        if(index==n-1) index=0;
        else index++;
        if(arr[index]==-1)
        {
             while(arr[index]==-1)
            {
                if(index==n-1) index=0;
                else index++;
            }
        }
    }
    ki++;
}
int i;
for(i=0;i<n;i++)
    {
        if(arr[i]!=-1)
        break;
    }
    cout<<"Survivor "<<arr[i];
	return 0;
}
