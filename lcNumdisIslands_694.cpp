/*
Date: 12/20/2018
*/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int r = grid.size(), c = grid[0].size();
        set<string> shapes;
        int vis[r * c] = {0};
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 1 && vis[i*c + j] == 0){
                    vector<char> v;
                    dfs(grid, vis, r, c, i, j, 'b', v); // 'b' for begin
                    string temp(v.begin(), v.end());
                    shapes.insert(temp);
                }
            }
        }
        return shapes.size();
    }
    
    void dfs(vector<vector<int>>& grid, int *vis, int r, int c, int i, int j, char ch, vector<char>& v){
        if((i >= 0 && i < r) && (j >=0 && j < c) && vis[i*c + j] == 0 && grid[i][j] == 1){
            v.push_back(ch);
            vis[i*c + j] = 1; // mark visited
            dfs(grid, vis, r, c, i+1, j, 'd', v);
            dfs(grid, vis, r, c, i-1, j, 'u', v);
            dfs(grid, vis, r, c, i, j+1, 'r', v);
            dfs(grid, vis, r, c, i, j-1, 'l', v);
        }else{
            v.push_back('x');
        }
    }
};