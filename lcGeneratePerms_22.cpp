/*
author: Swapnil Borse
date: 10th Oct'18
*/

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        if(n == 0){
            result.push_back("");
            return result;
        }else{
            char* arr = (char*)malloc(sizeof(char)*n + sizeof(char));
            util(arr, 0, 0, n, 0);
            return result;
        }
    }
    
    void util(char* arr, int clCnt, int opCnt, int n, int idx){
        if(clCnt == n){
            arr[idx] = '\0';
            result.push_back(arr);
            return;
        }else{
            if(opCnt < n){
                arr[idx] = '(';
                util(arr, clCnt, opCnt+1, n, idx+1);
            }
            if(clCnt < opCnt){
                arr[idx] = ')';
                util(arr, clCnt+1, opCnt, n, idx+1);
            }
        }
    }
};