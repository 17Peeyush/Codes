//Sorting an array using recursion
#include <iostream>
using namespace std;

void insert(int arr[],int size,int el)
{
    if(size==1)
        arr[size-1]=el;
    
    else if(arr[size-2]<el)
        arr[size-1]=el;
    
    else
    {
        int n=arr[size-2];
        insert(arr,size-1,el);
        arr[size-1]=n;
    }
}

void sort(int arr[],int size)
{
    if(size==1)
        return;
    int n= arr[size-1];
    // for(int i=0;i<size;i++)
    //     cout<<arr[i];
    // cout<<"\n*"<<endl;
    sort(arr,size-1);
    insert(arr,size,n);
    
}
int main() {
	int arr[]={5,3,2,1,4,0,6,-2};
	int size=8;
	sort(arr,size);
// 	insert(arr,size,arr[size-1]);
	for(int i=0;i<size;i++)
	    cout<<arr[i]<<" ";
	return 0;
}
