//Sorting a stack using recursion
#include <iostream>
using namespace std;

void insert(int arr[],int top,int el)
{
    if(top==-1)
        arr[0]=el;
    
    else if(arr[top-1]>el)
        arr[top]=el;
    
    else
    {
        int n=arr[top-1];
        insert(arr,top-1,el);
        arr[top]=n;
    }
}

void sort(int arr[],int top)
{
    if(top==0)
        return;
    int n= arr[top];
    sort(arr,top-1);
    insert(arr,top,n);
    
}
int main() {
	int arr[]={1,3,4,2,0,9,7,5};
	int top=7;
	sort(arr,top);
// 	insert(arr,size,arr[size-1]);
	for(int i=0;i<=top;i++)
	    cout<<arr[i]<<" ";
	return 0;
}
