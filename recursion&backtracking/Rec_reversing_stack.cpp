//Reversing stack using recursion
#include <iostream>
using namespace std;


int insert(int arr[],int top,int el)
{
 if(top!=-1)
 {
     int n=arr[top];
     top=insert(arr,top-1,el);
     arr[top]=n;
     return top+1;
 }
 else
 {
     arr[top+1]=el;
     return top+2;
 }
    
}
void reverse(int arr[],int top)
{
    if(top==0)
        return;
    int n= arr[top];
    reverse(arr,top-1);
    insert(arr,top,n);
    
}
int main() {
	int arr[]={1,3,4,9,7,5};
	int top=5;
	reverse(arr,top);
	for(int i=0;i<=top;i++)
	    cout<<arr[i]<<" ";
	return 0;
}


