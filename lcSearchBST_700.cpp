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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* result = NULL;
        if(root != NULL){
            if(root->val == val){
                return root;
            }
            if(root->val > val){
                result = searchBST(root->left, val);
            }else{
                result = searchBST(root->right, val);
            }   
        }
        return result;
    }
};