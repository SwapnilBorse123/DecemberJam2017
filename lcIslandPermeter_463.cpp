/*
author: Swapnil Borse
date: 10th Feb 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    	int perimeter = 0;
    	for (int row = 0; row < grid.size(); ++row){
    		for(int col = 0; col < grid[0].size(); ++col){
    			if(grid[row][col] == 1){ // find out the edges it has a '0' or boundary by
    				//cout << "1 found\n";
    				if(row == 0 || grid[row-1][col] == 0){ perimeter++; } //up
    				if(row == grid.size()-1 || grid[row+1][col] == 0){ perimeter++; } //down
    				if(col == 0 || grid[row][col-1] == 0){ perimeter++; } //left
    				if(col == grid[0].size()-1 || grid[row][col+1] == 0 ){ perimeter++; } //right
    			}
    		}
    	}
    	//cout << perimeter << endl;
    	return perimeter;
    }
};

int main(){
	std::vector<std::vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
	Solution s;
	cout << s.islandPerimeter(grid) << endl;
	return 0;
}