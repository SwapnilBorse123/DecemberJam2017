/*
author: Swapnil Borse
date: 6th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
        	return 0;
        }
        if(nums.size() == 1){
        	return nums[0];
        }
        int dpNums[nums.size()];
        dpNums[0] = nums[0];
        dpNums[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
        	dpNums[i] = max(nums[i] + dpNums[i-2], dpNums[i-1]);
        }
        return dpNums[nums.size() - 1];
    }

    int max(int a, int b){
    	return a > b ? a : b;
    }
};

int main(){
	Solution s;
	vector<int> v = {2,7,9,3,1};
	cout << s.rob(v) << "\n";
	return 0;
}