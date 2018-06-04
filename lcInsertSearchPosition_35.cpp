/*
author: Swapnil Borse
date: 15th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	int binarySearch(vector<int>& nums, int low, int hi, register int target){
		register int mid = (low + hi)/2;
		//cout << "mid: " << mid << endl;
		if (nums[mid] == target){ return mid; }
		if (mid == 0){
			if (target > nums[mid] && target < nums[mid+1]){ return mid+1; }
			else if (target < nums[mid]){ return mid;}
		}
		if (mid == nums.size()-1){
			if(target < nums[mid] && target > nums[mid-1]){ return mid; }
			else if (target > nums[mid]){ return mid+1;}
		}
		if (target > nums[mid] && target < nums[mid+1]){
			return mid+1;
		}
		if(target < nums[mid] && target > nums[mid-1]) {
			return mid;
		}
		if (target < nums[mid]){
			return binarySearch(nums, 0, mid-1, target);
		}
		if (target > nums[mid]){
			return binarySearch(nums, mid+1, hi, target);
		}
	}

    int searchInsert(vector<int>& nums, int target) {
    	if (nums.size() == 1){
    		return target > nums[0] ? 1 : 0;
    	}
    	return nums.size() == 0 ? 0 : binarySearch(nums, 0, nums.size()-1, target);
    }
};

//int Solution::t = 0;

int main(){
	std::vector<int> v = {1, 3};
	Solution s;
	cout << s.searchInsert(v, 5) << endl;
	return 0;
}