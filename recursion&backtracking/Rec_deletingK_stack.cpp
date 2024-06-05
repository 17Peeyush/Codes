//Deleting kth element from stack using recursion
#include <iostream>
using namespace std;


int deleteK(int arr[],int k,int top)
{
    if(k==1)
        return top;
        
    int n= arr[top];
    top=deleteK(arr,--k,top-1);
    arr[top]=n;
    return top+1;
    
}
int main() {
	int arr[]={1,3,4,2,0,9,7,5};
	int top=7;
	top=deleteK(arr,3,top);
	top--;
	for(int i=0;i<=top;i++)
	    cout<<arr[i]<<" ";
	return 0;
}
