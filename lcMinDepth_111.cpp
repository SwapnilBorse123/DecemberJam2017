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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);
        int nodeCount = 0;
        int level = 1;
        while(1){
            nodeCount = myQueue.size();
            
            if(nodeCount == 0){
                break;
            }
            
            while(nodeCount > 0){
                TreeNode* currNode = myQueue.front();
                myQueue.pop();
                if(currNode != NULL){
                    if(currNode->left == NULL && currNode->right == NULL){
                        return level;
                    }
                    myQueue.push(currNode->left);
                    myQueue.push(currNode->right);   
                }
                nodeCount--;
            }
            if(nodeCount == 0){
                level++;
            }
        }
        return level;
    }
};