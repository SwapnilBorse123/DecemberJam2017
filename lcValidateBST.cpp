/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

class Solution {
    public:
    bool isBST(TreeNode* root, int min, int max){
        if(root == NULL){
            return true;
        }
        
        if(root->val < min || root->val > max){
            return false;
        }
        
        return((isBST(root->left, min, root->val - 1)) && (isBST(root->right, root->val + 1, max)));
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }
};