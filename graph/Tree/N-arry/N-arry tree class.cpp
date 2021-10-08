#include <bits/stdc++.h>
#include <iostream>
#define k 3 //Number of children
using namespace std;
class Nnode
{
    public:
    int val;
    vector<Nnode*>children;
    
    Nnode()
    {
        val=0;
        children=vector<Nnode*>(k,nullptr);
    }
    
    Nnode* Buildtree()
    {
        Nnode *root=new Nnode();
        queue<Nnode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Nnode* curr=q.front();
                q.pop();
                string val;
                cin>>val;
                if(val=="N") curr=nullptr;
                else
                {
                    curr->val=stoi(val);
                    for(int i=0;i<k;i++)
                    {
                        curr->children[i]=new Nnode();
                        q.push(curr->children[i]);
                    }
                }
            }
        }
        return root;
    }
    void LevelOrder(Nnode* root)
    {
        queue<Nnode*>q;
        q.push(root);
        int i=0;
        while(!q.empty())
        {
            int size=q.size();
            cout<<"level "<<i<<" :";
            while(size--)
            {
                Nnode* curr=q.front();
                q.pop();
                if(curr!=nullptr)
                {
                    cout<<curr->val<<" ";
                    for(auto x:curr->children)
                        q.push(x);
                }
            }
            i++;
            cout<<endl;
        }
    }
};
int main()
{
    Nnode obj;
    Nnode* root=obj.Buildtree();
    obj.LevelOrder(root);
    
}
