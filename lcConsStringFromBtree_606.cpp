/*
Date: 12/24/2018
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
    string res = "";
    string tree2str(TreeNode* t) {
        if(t == NULL){
            return res;
        }
        preOrder(t, true);
        return res.substr(1, res.length()-2);
    }
    
    void preOrder(TreeNode* root, bool include){
        if(root){
            if(include){
                res = res + '(' + to_string(root->val);
            }
            if(!(root->left) && !(root->right)){ // leaf node
                res = res + ')';
                return;       
            }
            if(!(root->left)){ // left node null
                res = res + '(' + ')';
            }else{
                preOrder(root->left, true);   
            }
            if(!(root->right)){ // right node null
                //preOrder(root->right, false);
                res = res + ')';
                return;
            }else{
                preOrder(root->right, true);
                res = res + ')';
            }
        }
    }
};