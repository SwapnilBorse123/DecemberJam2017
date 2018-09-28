/*
author: Swapnil Borse
date: 23rd August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0], maxSumSoFar = nums[0];
        for(int i = 1; i < nums.size(); ++i){
        	if(maxSumSoFar + nums[i] > maxSumSoFar){
        		maxSumSoFar = nums[i] + maxSumSoFar;
        	}
        	if(maxSumSoFar > globalMax){
        		globalMax = maxSumSoFar;
        	}
        }
        return globalMax;
    }   
};

int main(){
	Solution s;
	std::vector<int> myVec = {-2,1,-3,4,-1,2,1,-5,4};
	cout << s.maxSubArray(myVec) << "\n";
	return 0;
}