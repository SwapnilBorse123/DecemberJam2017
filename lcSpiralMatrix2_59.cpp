/*
    Date: 12/27/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int top = 0, left = 0, bottom = n-1, right = n-1, counter = 1;
        while(left <= right && top <= bottom){
            for(int i = left; i <= right; ++i){
                matrix[top][i] = counter++;
                //cout << "pushingLR " << matrix[top][i] << endl;
            }
            top++;
            //cout << "top: " << top << endl;
            for(int i = top; i <= bottom; ++i){
                matrix[i][right] = counter++;
                //cout << "pushingTB " << matrix[i][right] << endl;
            }
            right--;
            //cout << "right: " << right << endl;
            for(int i = right; i >= left && top <= bottom; --i){
                matrix[bottom][i] = counter++;
                //cout << "pushingRL " << matrix[bottom][i] << endl;
            }
            bottom--;
            //cout << "bottom: " << bottom << endl;
            for(int i = bottom; i >= top && left <= right; --i){
                matrix[i][left] = counter++;
                //cout << "pushingBT " << matrix[i][left] << endl;
            }
            left++;
            //cout << "left: " << left << endl;
        }
        return matrix;
    }
};