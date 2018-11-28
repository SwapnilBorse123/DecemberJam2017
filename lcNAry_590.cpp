/*
author: Swapnil Borse
date: 28th Sep'18
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> myVec;
        if(root == NULL){
            return myVec;
        }
        pOUtil(root, &myVec);
        return myVec;
    }
    
    void pOUtil(Node* root, vector<int> *vec){
        if(root != NULL){
            for(int i = 0; i < root->children.size(); ++i){
                pOUtil(root->children[i], vec);
            }
            vec->push_back(root->val);
        }
    }
};