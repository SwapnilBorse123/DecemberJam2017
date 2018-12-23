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
        if(matrix.empty()){
            return false;
        }
        // find row
        int row = findRow(matrix, 0, matrix.size()-1, target);
        //cout <<"row " << row << endl;
        if(row < 0){
            return false;
        }
        return bs(matrix[row], 0, matrix[0].size()-1, target);
    }
    
    bool bs(vector<int>& vec, int low, int high, int target){
        if(low <= high){
            int mid = low + (high-low)/2;
            if(vec[mid] == target){
                return true;
            }else if(target > vec[mid]){
                return bs(vec, mid+1, high, target);
            }else{
                return bs(vec, low, mid-1, target);
            }
        }
        return false;
    }
    
    int findRow(vector<vector<int>>& matrix, int low, int high, int target){
        if(low <= high){
            int mid = low + (high-low)/2;
            int cols = matrix[0].size();
            if(cols == 0) return -1;
            if(matrix[mid][0] <= target && matrix[mid][cols-1] >= target){
                return mid;
            }else if(target > matrix[mid][cols-1]){
                return findRow(matrix, mid+1, high, target);
            }else{
                return findRow(matrix, low, mid-1, target);
            }
        }
        return -1;
    }
};