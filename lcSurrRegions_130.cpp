/*
Date: 12/20/2019
Author: Swapnil Borse
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }
        int rows = board.size(), cols = board[0].size();
        // for(int i = 0; i < rows; ++i){
        //     for(int j = 0; j < cols; ++j){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        //cout << "\n";
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if((j == 0 || j == cols-1 || i == 0 || i == rows-1) && board[i][j] == 'O'){
                    traceOFromBorder(board, i, j, rows, cols);        
                }
            }
        }
        // for(int i = 0; i < rows; ++i){
        //     for(int j = 0; j < cols; ++j){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                //cout << board[i][j] << " ";
                
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '-'){
                    board[i][j] = 'O';
                }
            }
            //cout << "\n";
        }
    }
    
    void traceOFromBorder(vector<vector<char>>& board, int i, int j, int rows, int cols){
        board[i][j] = '-';
        //cout << "- for " << i << "," << j << endl;
        if(j-1 >= 0 && board[i][j-1] == 'O'){ // visit left
            traceOFromBorder(board, i, j-1, rows, cols);
        }
        if(i-1 >= 0 && board[i-1][j] == 'O'){ // visit top
            traceOFromBorder(board, i-1, j, rows, cols);
        }
        if(i+1 <= rows-1 && board[i+1][j] == 'O'){ // visit bottom
            traceOFromBorder(board, i+1, j, rows, cols);
        }
        if(j+1 <= cols-1 && board[i][j+1] == 'O'){ // visit right
            traceOFromBorder(board, i, j+1, rows, cols);
        }
    }
};