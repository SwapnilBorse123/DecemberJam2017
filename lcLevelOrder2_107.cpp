/*
author: Swapnil Borse
date: 5th Oct'18
*/

#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> finalRes;
        if(root == NULL){
            return finalRes;
        }
        std::queue<TreeNode*> myQ;
        std::stack<vector<int>> myS;
        
        myQ.push(root);
        int nodeCount, level;
        nodeCount = 0; level = 1;
        
        while(1){
             
            nodeCount = myQ.size();
            if(nodeCount == 0) break;
            
            vector<int> currLevel;
            while(nodeCount > 0){
                TreeNode* currNode = myQ.front();
                myQ.pop();  
                if(currNode != NULL){
                    myQ.push(currNode->left);
                    myQ.push(currNode->right);
                    currLevel.push_back(currNode->val);
                }
                nodeCount--;
            }
            if(currLevel.size() > 0){
                //cout << "pushing in stack\n";
                myS.push(currLevel);   
            }
            currLevel.clear();
        }
        while(!myS.empty()){
            vector<int> currLevel = myS.top();
            finalRes.push_back(currLevel);
            myS.pop();
        }
        return finalRes;
    }
};