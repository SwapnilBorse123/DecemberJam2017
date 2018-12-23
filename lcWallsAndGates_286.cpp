/*
Date: 12/20/2018
*/

class Solution {
public:
    struct cellLevel{
        int i;
        int j;
        int level;
    };
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()){
            return;
        }
        int rows = rooms.size(), cols = rooms[0].size();
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(rooms[i][j] == 0){ // its a gate. Perform a BFS
                    bfs(rooms, rows, cols, i, j);
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& rooms, int rows, int cols, int i, int j){
        //cout << "calling bfs on gate: " << i << "," << j << endl;
        int visited[rows * cols] = {0};
        queue<cellLevel> Q;
        int level = 1;
        Q.push({i, j, 0});
        visited[i*cols + j] = 1;
        while(!Q.empty()){
            struct cellLevel curCell = Q.front();
            //cout << "current cell: " << curCell.i << " " << curCell.j << " at dist: " << curCell.level << endl;
            int rIdx = curCell.i, cIdx = curCell.j;
            Q.pop();
            
            if(cIdx-1 >= 0 && rooms[rIdx][cIdx-1] != -1 && rooms[rIdx][cIdx-1] != 0 && visited[rIdx * cols + (cIdx-1)] == 0){ // visit left
                if(curCell.level+1 < rooms[rIdx][cIdx-1]){
                    rooms[rIdx][cIdx-1] = curCell.level+1;
                }
                Q.push({rIdx, cIdx-1, curCell.level+1});
                visited[rIdx * cols + (cIdx-1)] = 1;
            }
            if(rIdx-1 >= 0 && rooms[rIdx-1][cIdx] != -1 && rooms[rIdx-1][cIdx] != 0 && visited[(rIdx-1)*cols + cIdx] == 0){ // visit top
                if(curCell.level+1 < rooms[rIdx-1][cIdx]){
                    rooms[rIdx-1][cIdx] = curCell.level+1 ;
                }
                Q.push({rIdx-1, cIdx, curCell.level+1});
                visited[(rIdx-1)*cols + cIdx] = 1;
            }
            if(rIdx+1 <= rows-1 && rooms[rIdx+1][cIdx] != -1 && rooms[rIdx+1][cIdx] != 0 && visited[(rIdx+1)*cols + cIdx] == 0){ // visit bottom
                if(curCell.level+1 < rooms[rIdx+1][cIdx]){
                    rooms[rIdx+1][cIdx] = curCell.level+1 ;
                }
                Q.push({rIdx+1, cIdx, curCell.level+1});
                visited[(rIdx+1)*cols + cIdx] = 1;
            }
            if(cIdx+1 <= cols-1 && rooms[rIdx][cIdx+1] != -1 && rooms[rIdx][cIdx+1] != 0 && visited[rIdx* cols + (cIdx+1)] == 0){ // visit right
                if(curCell.level+1 < rooms[rIdx][cIdx+1]){
                    rooms[rIdx][cIdx+1] = curCell.level+1 ;
                }
                Q.push({rIdx, cIdx+1, curCell.level+1});
                visited[rIdx*cols + (cIdx+1)] = 1;
            }
            level++;
        }        
    }
};