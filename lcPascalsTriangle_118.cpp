/*
author: Swapnil Borse
date: 18th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> resultVector;
    	if(numRows <= 0){
    		return resultVector;
    	}
        vector<int> firstRow = {1};
        vector<int> secondRow = {1, 1};
        if(numRows == 1){
        	resultVector.push_back(firstRow);
        	return resultVector;
        }else if(numRows == 2){
        	resultVector.push_back(firstRow);
        	resultVector.push_back(secondRow);
        	resultVector;
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
        return resultVector;
    }
};

int main(){
	Solution s;
	vector<vector<int>> resultVector = s.generate(10);
	for(int i = 0; i < resultVector.size(); ++i){
		vector<int> currVec = resultVector[i];
		for(int j = 0; j < currVec.size(); ++j){
			cout << currVec[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}