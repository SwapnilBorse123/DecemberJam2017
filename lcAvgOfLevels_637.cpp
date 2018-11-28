/*
author: Swapnil Borse
date: 5th Oct'18
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> finalRes;
        if(root == NULL){
            return finalRes;
        }
        
        std::queue<TreeNode*> myQ;
        myQ.push(root);
        int nodeCount = 0;
        
        while(1){     
            nodeCount = myQ.size();
            if(nodeCount == 0) break;
            
            vector<int> currLevel;
            while(nodeCount > 0){
                TreeNode* currNode = myQ.front();
                myQ.pop();  
                if(currNode != NULL){
                    myQ.push(currNode->left);
                    myQ.push(currNode->right);
                    currLevel.push_back(currNode->val);
                }
                nodeCount--;
            }
            if(currLevel.size() > 0){
                if(std::adjacent_find( currLevel.begin(), currLevel.end(), std::not_equal_to<int>() ) == currLevel.end()){
                    finalRes.push_back((double)currLevel[0]);    
                }else{
                    finalRes.push_back((std::accumulate(currLevel.begin(), currLevel.end(), 0)/(double)currLevel.size()));   
                }
            }
            currLevel.clear();
        }
        return finalRes;
    }
};