/*
    Problem: https://www.geeksforgeeks.org/replace-every-element-with-the-least-greater-element-on-its-right/
    Time Complexity: O(n*n), in case of skewed bst(arr is sorted)
    Auxiliary Space: O(n)
    Date: 28-10-2021
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};
TreeNode* insertBST(TreeNode*root,int data,TreeNode* &successor)
{
    if(!root) 
    {
        return root=new TreeNode(data);
    }
    else if(data < (root->val))
    {
        successor=root;
        root->left=insertBST(root->left,data,successor);
    }
    else
    {
        root->right=insertBST(root->right,data,successor);
    }
    return root;
}
vector<int> replaceLGE(vector<int>arr)
{
    int n=arr.size();
    TreeNode* root=nullptr;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        TreeNode* successor=nullptr;
        root=insertBST(root,arr[i],successor);
        if(successor==nullptr)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=successor->val;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr={ 8,  58, 71, 18, 31, 32, 63, 92,43, 3,  91, 93, 25, 80, 28};
    arr=replaceLGE(arr);
    for(auto x: arr)
        cout<<x<<" ";
    return 0;
}
