#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct Nnode{
    int data;
    vector<Nnode*> children;
};
Nnode* insert(int k,int i)
{
  int val;
  cout<<"Input "<<i<<" node val and -1 if want it to be null :";
  cin>>val;
  if(val==-1)
    return nullptr;
  Nnode* root= new Nnode();
  root->data=val; 
  for(int j=0;j<k;j++)
  { 
     root->children.push_back(insert(k,i+1));
  }
  return root;
}
int main()
{
  
  int k;
  cout<<"Enter the number of children: ";
  cin>>k;// number of children
  Nnode* root=insert(k,0);
    return 0;
}
