
/*
Date: 12/25/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

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
    bool isBal = true;
    
    bool isBalanced(TreeNode* root) {
        helper(root);
        return isBal;
    }
    
    void helper(TreeNode* root){
        if(root){
            //int lHt = getHeight(root->left);
            //int rHt = getHeight(root->right);
            //cout << "for: " << root->val << " " << abs(lHt-rHt) << endl;
            if(abs(getHeight(root->left) - getHeight(root->right)) > 1){
                isBal = false;
                return;
            }
            if(isBal){
                helper(root->left);
                helper(root->right);
            }
        }
    }
    
    int getHeight(TreeNode* root){
        if(root){
            if(!(root->left) && !(root->right)){ // leaf node
                return 1;
            }
            int lHt = getHeight(root->left);
            int rHt = getHeight(root->right);
            //cout << root->val << " left: " << lHt << " right:" << rHt << endl;
            return 1 + max(lHt, rHt);
        }else{
            return 0;
        }
    }
};