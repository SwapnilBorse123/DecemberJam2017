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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;
        }
        vector<int> tVec1, tVec2;
        leafSequence(root1, &tVec1);
        leafSequence(root2, &tVec2);
        if(tVec1 == tVec2){
            return true;
        }else{
            return false;
        }
    }
    
    void leafSequence(TreeNode* root, vector<int> *vec){
        if(root != NULL){
            if(root->left == NULL && root->right == NULL){ // leaf node
                vec->push_back(root->val);
            }
            leafSequence(root->left, vec);
            leafSequence(root->right, vec);
        }
    }
};