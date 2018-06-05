/*
author: B. Swapnil
date: 06/03/2018
*/


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

using namespace std;

class Solution {
public:
    bool result = false;
    bool findTarget(TreeNode* root, int k) {
        preOrder(root, root, k);
        return result;
    }

    void preOrder(TreeNode* currRoot, TreeNode* mainRoot, int k){ // mainRoot is the root of the given bst
    	if(currRoot != NULL){ // currRoot here is the current node in PreOrder
            if(isPresentInTree(mainRoot, currRoot, k-(currRoot->val))){
                //cout << "k-(currRoot->val)" << " :" << k-(currRoot->val) <<"\n";
                //cout << "MR: " << mainRoot->val << " CR: " << currRoot->val;
                result = true;
                return;
            }
    		preOrder(currRoot->left, mainRoot, k);
    		preOrder(currRoot->right, mainRoot, k);
    	}
    }

    bool isPresentInTree(TreeNode* root, TreeNode* poRoot, int num){ // poRoot is the node where PreOrder currently is
        if(root == NULL) return false;
        if(root->val == num && poRoot != root) return true;
        else if(root->val > num){
            return isPresentInTree(root->left, poRoot, num);
        }else {
            return isPresentInTree(root->right, poRoot, num);
        }
        
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->findTarget();
	return 0;
}