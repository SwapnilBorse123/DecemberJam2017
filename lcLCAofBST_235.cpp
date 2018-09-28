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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == p->val){ // when either of the given nodes is an ancestor
            cout << "returning p.\n";
            return p;
        }
        if(root->val == q->val){ // when either of the given nodes is an ancestor
            cout << "returning q.\n";
            return q;
        }
        if(isPresent(root->left, p->val) && isPresent(root->right, q->val) // one is in left subtree and other in right subtree
           || isPresent(root->left, q->val) && isPresent(root->right, p->val)){
            cout << "left right condition true for: " << root->val <<".\n";
            return root;
        }
        
        TreeNode* leftAncestor = NULL;
        TreeNode* rightAncestor = NULL;
        cout << "calling left:\n";
        leftAncestor = lowestCommonAncestor(root->left, p, q);
        
        cout << "calling right:\n";
        rightAncestor = lowestCommonAncestor(root->right, p, q);   
        if(leftAncestor != NULL){
            return leftAncestor;
        }else if(rightAncestor != NULL){
            return rightAncestor;
        }else{
            return NULL;
        }
    }
    
    bool isPresent(TreeNode* root, int element){
        if(root != NULL){
            bool ifPresent = false;
            if(root->val == element){
                ifPresent = true;
                return ifPresent;
            }
            if(root->val < element){
                ifPresent = isPresent(root->right, element);
            }else{
                ifPresent = isPresent(root->left, element);
            }
            return ifPresent;
        }else{
            return false;
        }
    }
};