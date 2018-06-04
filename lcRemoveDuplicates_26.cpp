/*
author: Swapnil Borse
date: 19th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() == 0){ return 0; }
    	if(nums.size() == 1){ return 1; }

        register unsigned int i = 0;
        unsigned int replacePos = 0, isSameIndx = 0;

        while(isSameIndx < nums.size()){
        	nums[replacePos] = nums[isSameIndx];
        	int currentNum = nums[isSameIndx];
        	while(nums[isSameIndx] == currentNum){ isSameIndx++; }
        	replacePos++;
        }
        return replacePos;
    }
};

int main(){
	Solution s;
	std::vector<int> myVec = {1, 1, 2};
	cout << s.removeDuplicates(myVec) << endl;
	
	return 0;
}