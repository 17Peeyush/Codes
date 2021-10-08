/*
Problem Statement: Engineers at Amazon are interested in knowing which software component moves the fastest by counting the number of 
lines of code changed in that component and all subcomponents in the code base over a month.Component nodes have subcomponent nodes that make up the larger component. 
We've stored the components as a tree where each node represents one component that contains the number of lines changed that month.
Software component speed is computed as the average number of lines of code changed for a given component and all its subcomponents.
Engineers compute this software component speed for all such components which have one or more subcomponents.
Find the component with the highest software component speed. Assume there will be at least one subcomponent in the tree and that there will be no ties. 
Input The input to the function/method consists of an argument:
rootComponent, a node representing the root Component node.
Output Return a ComponentNode that has the highest software component speed.

eg:
Input:
         200
       /     \
    120      180
  /  |  \   /   \
110 20  30 150  80

Output: 180

By: Peeyush Pratap Singh
Date: 22-09-2021


*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct Nnode{
    int data;
    vector<Nnode*> children;
    Nnode(int val)
    {
        data=val;
    }
};


// void LevelOrder(Nnode* root)
// {
//         queue<Nnode*>q;
//         q.push(root);
//         int i=0;
//         while(!q.empty())
//         {
//             int size=q.size();
//             cout<<"level "<<i<<" :";
//             while(size--)
//             {
//                 Nnode* curr=q.front();
//                 q.pop();
//                 if(curr!=nullptr)
//                 {
//                     cout<<curr->data<<" cs"<<curr->children.size()<<"\t";
//                     for(auto x:curr->children)
//                         q.push(x);
//                 }
//             }
//             i++;
//             cout<<endl;
//         }
// }

Nnode * avgnode=nullptr;
//Nnode *notcheck; if root need not to be considered
float avg=0;

pair<float,int> traverse(Nnode* root)
{
    if(root->children.size()==0)
    {
        return {root->data,1};
    }
    float ts=root->data;int tn=1;
    for(auto x: root->children)
    {
       
            auto e= traverse(x);
            ts+=e.first;
            tn+=e.second;
    }
    // if(root!=notcheck&&) // if root need not to considered
    // {
    if((ts/(float)tn)>avg)
    {
        avg=ts/(float)tn;
        avgnode=root;
    }
    //} 
    return {ts,tn};
}

int main()
{
  Nnode* root=new Nnode(200);
  Nnode *l1,*l2,*l3,*l4,*l5,*i1,*i2;
  l1=new Nnode(11);
  l2=new Nnode(2);
  l3=new Nnode(3);
  l4=new Nnode(15);
  l5=new Nnode(8);
  i1=new Nnode(12);
  i2=new Nnode(18);
  i1->children.push_back(l1);
  i1->children.push_back(l2);
  i1->children.push_back(l3);
  i2->children.push_back(l4);
  i2->children.push_back(l5);
  root->children.push_back(i1);
  root->children.push_back(i2);
//   notcheck=root;
  traverse(root);
  cout<<"Ans"<<avgnode->data;
// LevelOrder(root);
    return 0;
}
