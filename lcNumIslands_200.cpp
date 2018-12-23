/*
Date: 12/20/2018
Author: Swapnil
*/

class Solution {
public:
    int islands = 0;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        int size = row*col;
        //int* visited = new int[row * col];
        //memset(visited, 0, sizeof(visited));
        int visited[row * col] = {0};
        // for(int i = 0; i < size; ++i){
        //     cout << visited[i] << " ";
        // }
        cout << endl;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                //cout << "checking: " << i*col + j << "\n";
                if(grid[i][j] == '1' && visited[i*col + j] == 0){ // current island not visited
                    //cout << "calling traceIsland\n";
                    traceIsland(grid, visited, i, j, row, col); // mark all lands visited for current island
                    islands++;
                }
            }
        }/*
        for(int i = 0; i < size; ++i){
            cout << visited[i] << " ";
        }*/
        return islands;
    }
    
    void traceIsland(vector<vector<char>>& grid, int* visited, int i, int j, int row, int col){
        //cout << "visiting: (" << i << "," << j << ")\n";
        visited[i*col + j] = 1;
        if(j-1 >= 0 && grid[i][j-1] == '1' && visited[i*col+(j-1)] == 0){ // visit left
            traceIsland(grid, visited, i, j-1, row, col);
        }
        if(i-1 >= 0 && grid[i-1][j] == '1' && visited[(i-1)*col + j] == 0){ // visit top
            traceIsland(grid, visited, i-1, j, row, col);
        }
        if(i+1 <= row-1 && grid[i+1][j] == '1' && visited[(i+1)*col + j] == 0){ // visit bottom
            traceIsland(grid, visited, i+1, j, row, col);
        }
        if(j+1 <= col-1 && grid[i][j+1] == '1' && visited[i*col + (j+1)] == 0){ // visit right
            traceIsland(grid, visited, i, j+1, row, col);
        }
    }
};