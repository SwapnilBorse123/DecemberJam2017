/*
author: Swapnil Borse
date: 24th August 2018
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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return dfs(nums, 0, nums.size()-1);
    }

    TreeNode* dfs(std::vector<int> &nums, int low, int high){
    	if(low > high){
    		return NULL;
    	}
    	int mid = low + (high - low)/2;
    	TreeNode *currNode = new TreeNode(nums[mid]);
    	currNode->left = dfs(nums, low, mid-1);
    	currNode->right = dfs(nums, mid+1, high);
    	return currNode;
    }
};

int main(){
	Solution s;
	std::vector<int> v = {-10, -3, 0, 5, 9};
	TreeNode* root = s.sortedArrayToBST(v);
	return 0;
}