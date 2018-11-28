/*
author: Swapnil Borse
date: 1st Oct'18
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
class Solution {
public:
    TreeNode* head = NULL;
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        assignLeftMostHead(root);
        incUtil(root);
        makeLeftNull(head);
        return head;
    }
    
    void assignLeftMostHead(TreeNode* root){
        if(root){
            if(root->left == NULL && root->right == NULL){
                //cout << "assigning " << root->val << " as head.";
                head = root;
            }
            if(root->left == NULL){
                //cout << "assigning " << root->val << " as head.";
                head = root;
            }
            assignLeftMostHead(root->left);    
        }
    }
    
    void makeLeftNull(TreeNode* root){
        if(root){
            root->left = NULL;
            //cout << "making " << root->val << " 's left null.\n";
            makeLeftNull(root->right);
        }
    }
    
    void incUtil(TreeNode* root){
        static TreeNode* prev = NULL;
        if(root){
            //if(root->right)
                //cout << "incUtil(" << root->right->val << ");\n";
            //else
                //cout << "incUtil(NULL);\n";
            
            incUtil(root->right);
            
            //if(prev)
                //cout << root->val << "'s right as: " << prev->val << "\n";
            
            root->right = prev;
            prev = root;
            
            //if(root->left)
                //cout << "incUtil(" << root->left->val << ");\n";
            //else
                //cout << "incUtil(NULL);\n";
            
            incUtil(root->left);
        }
    }
};