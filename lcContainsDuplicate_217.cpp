/*
author: Swapnil Borse
date: 10th September 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
    	return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();   
    }
};

int main(){
	Solution s;
	std::vector<int> v = {1,2,3,4,5,1};
	cout << s.containsDuplicate(v) << "\n";
	return 0;
}