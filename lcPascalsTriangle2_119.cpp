/*
author: Swapnil Borse
date: 20th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows += 1;
    	vector<vector<int>> resultVector;
    	vector<int> firstRow = {1};
        vector<int> secondRow = {1, 1};
        if(numRows <= 1){
        	resultVector.push_back(firstRow);
        	return resultVector[0];
        }else if(numRows == 2){
        	resultVector.push_back(firstRow);
        	resultVector.push_back(secondRow);
        	resultVector[1];
        }else{
        	resultVector.push_back(firstRow);
        	resultVector.push_back(secondRow);
        	int currRowElemCnt = 1, elemCntIdx = 0;
        	std::vector<int> prevRow = secondRow;
        	for(int i = 2; i < numRows; ++i){
        		std::vector<int> currRow;
        		currRow.push_back(1);
        		for(int j = 1; j <= currRowElemCnt; ++j){
        			currRow.push_back(prevRow[j-1] + prevRow[j]);
        		}
        		currRowElemCnt++;
        		currRow.push_back(1);
        		resultVector.push_back(currRow);
        		prevRow = currRow;
        	}
        }
        return resultVector[numRows-1];
    }
};

int main(){
	Solution s;
	vector<int> resultVector = s.getRow(10);
	for(int i = 0; i < resultVector.size(); ++i){
		cout << resultVector[i] << " ";
	}
	return 0;
}