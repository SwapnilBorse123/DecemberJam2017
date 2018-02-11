/*
author: Swapnil B
date: 02/03/2018
*/

#include <bits/stdc++.h>
#include <vector>
#include <bitset>

using namespace std;

class Solution {

public:
    bool canJump(vector<int>& nums) {
    	if(nums.size() == 1){
        	return true;
        }
        int* hash = (int*)malloc(sizeof(int) * nums.size());
        memset(hash, 0, nums.size());
        hash[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; --i){
        	cout << "nums: " << i << " "; 
        	if(nums[i] == 0){
        		hash[i] = 0;
        		cout << endl;
        		continue;
        	}
        	for(int j = 0; j < nums[i] && (j+i)+1 < nums.size(); ++j){
        		cout << "hash: " << (j+i)+1 << "[" << hash[(i+j)+1] << "]";
        		if(hash[(j + i) + 1] == 1){
        			cout << "\nputting 1 for: " << (j + i) + 1 << endl;
        			hash[i] = 1;
        			break;
        		}
        	}
        	cout << endl;
        	//hash[i] = 0;
        }

        for (int j = 0; j < nums.size(); ++j){ // sizeof(hash)/sizeof(hash[0])
        	cout << hash[j] << " ";
        }

        cout << endl;
        return hash[0] == 1 ? true : false;
    }
};

int main(){
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(4);
	Solution s;
	cout << s.canJump(v) << endl;
	return 0;
}