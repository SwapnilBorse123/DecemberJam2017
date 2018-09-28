/*
author: Swapnil Borse
date: 15th February 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	
	int binarySearch(vector<int>& nums, int low, int hi, register int target){
		int mid = (low + hi)/2;
		if (nums[mid] == target) return mid;
		else if (mid == 0 && nums[mid] < target) return mid + 1;
		else if (mid == 0 ||  (nums[mid-1] < target && nums[mid] > target)) return mid;
		else if (mid == nums.size()-1  && nums[nums.size()-1] > target) return mid;
		else if (mid == nums.size()-1 || (nums[mid+1] > target && nums[mid] < target)) return mid+1;
		else if (target < nums[mid]){
			return binarySearch(nums, 0, mid-1, target);
		} else {
			return binarySearch(nums, mid+1, hi, target);
		}
	}

    int searchInsert(vector<int>& nums, int target) {
    	return nums.size() == 0 ? 0 : binarySearch(nums, 0, nums.size()-1, target);
    }
};

//int Solution::t = 0;

int main(){
	std::vector<int> v = {9, 13};
	Solution s;
	cout << s.searchInsert(v, 14) << endl;
	return 0;
}