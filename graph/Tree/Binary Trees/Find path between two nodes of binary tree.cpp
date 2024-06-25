/*
Date: 14-03-2022
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getpath(TreeNode* root,int key,vector<int>&temp,bool&found){
        if(root==nullptr)
            return;
        else if(root->val==key)
        {
            temp.push_back(root->val);
            found=true;
            return;
        }
        temp.push_back(root->val);
        getpath(root->left,key,temp,found);
        if(found)
            return;
        getpath(root->right,key,temp,found);
        if(found)
            return;
        temp.pop_back();
        return;
    }
    
    int getDistance(TreeNode* root, int startValue, int destValue) {
        vector<int>path1;
        vector<int>path2;
        bool found=false;
        getpath(root,startValue,path1,found);
        found=false;
        getpath(root,destValue,path2,found);
        int l=min(path1.size(),path2.size());
        if(l==0)
        {
            cout<<"Only one node found in the tree."<<endl;
            return -1;
        }
        int i=0;
        for(;i<l;i++)
        {
            if(path1[i]!=path2[i])
               { break;}
        }
        int pathlen=path1.size()-i+path2.size()-i;
        cout<< "path length :"<<pathlen;
        return pathlen;
    }
};