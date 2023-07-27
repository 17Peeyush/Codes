/*
Problem: https://practice.geeksforgeeks.org/problems/sort-a-stack/1
Date: 20-03-2022
Approach: We will create two recursive function assuming first will sort the stack provided and second recursive function will take an element and insert at appropriate 
level in the stack. 
Time Complexity: O(n*n)
Auxillary Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insert(stack<int>&st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    if(st.top()<=val){
        st.push(val);
        return;
    }
    int cval=st.top();
    st.pop();
    insert(st,val);
    st.push(cval);
    
}
void sortdescending(stack<int>&st){
    if(st.empty()){
        return;
    }
    else if(st.size()==1){
        return;
    }
    int cval=st.top();
    st.pop();
    sortdescending(st);
    insert(st,cval);
}
void SortedStack :: sort()
{
   //Your code here
   sortdescending(s);
}