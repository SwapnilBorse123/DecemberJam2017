/*
author: Swapnil Borse
date: 23rd September 2018
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL){
            return NULL;
        }else if(t1 == NULL){
            return t2;
        }else if(t2 == NULL){
            return t1;
        }else{
            return mergeTreesUtil(t1, t2);
        }
    }
    
    TreeNode* mergeTreesUtil(TreeNode* t1, TreeNode* t2) {
        //t1->left = mergeTrees(t1->left, t2->left);
        TreeNode* temp = getNewNode(-1);
        if(t1 == NULL && t2 == NULL){
            temp = NULL;
        }else if(t1 == NULL && t2 != NULL){
            temp->val = t2->val;
            temp->left = mergeTreesUtil(NULL, t2->left);
            temp->right = mergeTreesUtil(NULL, t2->right);
        }else if(t1 != NULL && t2 == NULL){
            temp = t1;
        }else if(t1 != NULL && t2 != NULL){
            temp->val = t1->val + t2->val;
            temp->left = mergeTreesUtil(t1->left, t2->left);
            temp->right = mergeTreesUtil(t1->right, t2->right);
        }
        return temp;
        //t1->right = mergeTrees(t1->right, t2->right);
    }
    
    TreeNode* getNewNode(int val){
        TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }   
};

int main(){
	//Solution s;
	//cout << s.
	return 0;
}