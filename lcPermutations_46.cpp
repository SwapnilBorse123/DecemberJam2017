/*
author: Swapnil Borse
date: 19th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUtil();
    }

    void permuteUtil
};

int main(){
	Solution s;
	std::vector<int> v = {1,2,3};
	vector<vector<int>> myVec = permute(v);
	for(int i = 0; i < myVec.size(); ++i){
		std::vector<int> curr = myVec[i];
		for(int j = 0; j < curr.size(); ++j){
			cout << curr[j];
		}
		cout << endl;
	}
	return 0;
}