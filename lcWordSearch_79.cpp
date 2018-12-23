/*
Date: 12/20/2019
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool found = false;
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }
        int r = board.size(), c = board[0].size();
        int vis[r*c] = {0};
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(board[i][j] == word[0] && !vis[i*c + j]){
                    //cout << "calling search word.\n";
                    searchWord(board, word, r, c, i, j, 0, vis);
                    if(found){
                        return found;   
                    }
                    for(int k = 0; k < r*c; ++k){
                        vis[k] = 0;
                    }
                }
            }
        }
        return false;
    }
    
    void searchWord(vector<vector<char>>& board, string word, int r, int c, int i, int j, int wIdx, int *vis){
        // if((i>=0 && i<r) && (j>=0 && j<c) && vis[i*c + j]){
        //     cout << board[i][j] << " (" << i << "," <<j << ")" << " already visited \n";   
        // }
        if((i>=0 && i<r) && (j>=0 && j<c) && !vis[i*c + j] && board[i][j] == word[wIdx] && !found){
            vis[i*c + j] = 1;
            //cout << board[i][j] << " (" << i << "," <<j << ")" << endl;
            if(wIdx == word.length()-1){
                found = true;
                //cout << " WORD FOUND:\n";
                return;
            }
            searchWord(board, word, r, c, i-1, j, wIdx+1, vis);
            searchWord(board, word, r, c, i+1, j, wIdx+1, vis);
            searchWord(board, word, r, c, i, j+1, wIdx+1, vis);
            searchWord(board, word, r, c, i, j-1, wIdx+1, vis);
            vis[i*c + j] = 0;
        }
    }
};