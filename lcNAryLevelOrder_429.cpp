/*
author: Swapnil Borse
date: 5th Oct'18
*/

#include <bits/stdc++.h>
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> finalResult;
        if(root == NULL){
            return finalResult;
        }
        std::queue<Node*> myQueue;
        myQueue.push(root);
        
        vector<int> rootVec; rootVec.push_back(root->val);
        finalResult.push_back(rootVec);
        
        int nodeCount = 0;// = myQueue.size();
        
        while(1){
            //Node* currentNode = myQueue.front();
            nodeCount = myQueue.size();
            
            if(nodeCount == 0){
                break;
            }
            vector<int> childList;
            while(nodeCount > 0){
                Node* currentNode = myQueue.front();
                //cout << currentNode->val << " ";
                myQueue.pop();
                vector<Node*> children = currentNode->children;
                if(children.size() > 0){
                    for(int i = 0; i < children.size(); ++i){
                        myQueue.push(children[i]);
                        childList.push_back(children[i]->val);
                    }
                }
                nodeCount--;
            }
            if(childList.size() >0 ){
                finalResult.push_back(childList);   
            }
        }
        return finalResult;
    }
};