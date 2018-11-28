class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.empty()){
            return res;
        }
        int row = M.size(), col = M[0].size();
        for(int i = 0; i < row; ++i){
            vector<int> curCol;
            for(int j = 0; j < col; ++j){
                int sum = 0;
                int neigh = 0;
                //consider all 8 possibilities.
                if(i-1 >= 0 && j-1 >= 0){
                    sum = sum + M[i-1][j-1];
                    neigh++;
                }
                if(i >= 0 && j-1 >= 0){
                    sum = sum + M[i][j-1];
                    neigh++;
                }
                if(i+1 < row && j-1 >= 0){
                    sum = sum + M[i+1][j-1];
                    neigh++;
                }
                if(i-1 >= 0 && j >= 0){
                    sum = sum + M[i-1][j];
                    neigh++;
                }
                //if(i-1 >= 0 && j-1 >= 0){
                sum = sum + M[i][j];
                neigh++;
                //}
                if(i+1 < row && j >= 0){
                    sum = sum + M[i+1][j];
                    neigh++;
                }
                if(i-1 >= 0 && j+1 < col){
                    sum = sum + M[i-1][j+1];
                    neigh++;
                }
                if(i >= 0 && j+1 < col){
                    sum = sum + M[i][j+1];
                    neigh++;
                }
                if(i+1 < row && j+1 < col){
                    sum = sum + M[i+1][j+1];
                    neigh++;
                }
                //cout << "for (" << i << "," << j << "): sum " << sum << endl;
                curCol.push_back(floor(sum/neigh));
            }
            res.push_back(curCol);
        }
        return res;
    }
};