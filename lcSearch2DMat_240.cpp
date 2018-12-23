/*
Date: 12/21/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int i = 0, j = matrix[0].size()-1; // top right element
        while(j >= 0 && i < matrix.size()){
            if(target == matrix[i][j]){
                return true;
            }else if(target < matrix[i][j]){
                j--;
            }else{// if(}target > matrix[i][j]){
                i++;
            }
        }
        return false;
    }
};