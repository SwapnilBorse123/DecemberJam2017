/*
author: Swapnil Borse
date: 20th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
        	ans ^= nums[i];
        }
        return ans;
    }
};

int main(){ 
	Solution s;
	std::vector<int> vec = {2, 2, 1};
	cout << s.singleNumber(vec);
	return 0;
}